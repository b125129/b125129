#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adj;
} Graph;

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->adj = (Node**)calloc(V + 1, sizeof(Node*));
    return g;
}

void addEdge(Graph* g, int u, int v) {
    Node* n1 = (Node*)malloc(sizeof(Node));
    n1->vertex = v;
    n1->next = g->adj[u];
    g->adj[u] = n1;

    Node* n2 = (Node*)malloc(sizeof(Node));
    n2->vertex = u;
    n2->next = g->adj[v];
    g->adj[v] = n2;
}

typedef struct {
    int* parent;
    int* rank;
    long long* comp_weight;
} DSU;

DSU* createDSU(int V, long long vertex_weights[]) {
    DSU* dsu = (DSU*)malloc(sizeof(DSU));
    dsu->parent = (int*)malloc((V + 1) * sizeof(int));
    dsu->rank = (int*)calloc(V + 1, sizeof(int));
    dsu->comp_weight = (long long*)malloc((V + 1) * sizeof(long long));

    for (int i = 1; i <= V; i++) {
        dsu->parent[i] = i;
        dsu->comp_weight[i] = vertex_weights[i];
    }
    return dsu;
}

int find(DSU* dsu, int i) {
    if (dsu->parent[i] == i)
        return i;
    return dsu->parent[i] = find(dsu, dsu->parent[i]);
}

long long unionSets(DSU* dsu, int i, int j) {
    int rootI = find(dsu, i);
    int rootJ = find(dsu, j);

    if (rootI != rootJ) {
        if (dsu->rank[rootI] < dsu->rank[rootJ]) {
            int temp = rootI; rootI = rootJ; rootJ = temp;
        }
        dsu->parent[rootJ] = rootI;
        dsu->comp_weight[rootI] += dsu->comp_weight[rootJ];
        if (dsu->rank[rootI] == dsu->rank[rootJ]) {
            dsu->rank[rootI]++;
        }
    }
    return dsu->comp_weight[rootI];
}

int main() {
    int V, E;
    printf("=======================================================\n");
    printf("     REVERSE TIME-STEP DSU (VERTEX DELETION)           \n");
    printf("=======================================================\n");

    printf("Enter number of vertices (V) and edges (E): ");
    if (scanf("%d %d", &V, &E) != 2 || V <= 0) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    long long* vertex_weights = (long long*)malloc((V + 1) * sizeof(long long));
    printf("Enter weights for the %d vertices (v1 to v%d):\n", V, V);
    for (int i = 1; i <= V; i++) {
        printf("Weight of Vertex %d: ", i);
        scanf("%lld", &vertex_weights[i]);
    }

    Graph* g = createGraph(V);
    printf("Enter %d undirected edges (u v):\n", E);
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    int* deletion_order = (int*)malloc((V + 1) * sizeof(int));
    printf("Enter deletion order permutation P (list of %d vertices):\n", V);
    for (int i = 1; i <= V; i++) {
        printf("Deletion Step %d: ", i);
        scanf("%d", &deletion_order[i]);
    }

    DSU* dsu = createDSU(V, vertex_weights);
    int* active = (int*)calloc(V + 1, sizeof(int));
    long long* ans = (long long*)malloc((V + 1) * sizeof(long long));

    long long max_weight = 0;

    // Process vertices in REVERSE order of deletion
    for (int i = V; i >= 1; i--) {
        // Record max component weight BEFORE adding back vertex deletion_order[i]
        ans[i] = max_weight;

        int u = deletion_order[i];
        active[u] = 1;
        if (vertex_weights[u] > max_weight) {
            max_weight = vertex_weights[u];
        }

        // Connect u with all adjacent vertices that are already active
        for (Node* curr = g->adj[u]; curr != NULL; curr = curr->next) {
            int v = curr->vertex;
            if (active[v]) {
                long long merged_weight = unionSets(dsu, u, v);
                if (merged_weight > max_weight) {
                    max_weight = merged_weight;
                }
            }
        }
    }

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    for (int i = 1; i <= V; i++) {
        printf("After deleting Vertex %d (Step %d): Max Component Weight = %lld\n",
               deletion_order[i], i, ans[i]);
    }

    printf("=======================================================\n");
    printf("RESULT: Reverse DSU Vertex Deletion Analysis Complete.\n");
    printf("=======================================================\n");

    free(vertex_weights);
    free(deletion_order);
    free(active);
    free(ans);
    free(dsu->parent);
    free(dsu->rank);
    free(dsu->comp_weight);
    free(dsu);

    return 0;
}
