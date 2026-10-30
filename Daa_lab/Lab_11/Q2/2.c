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

void multiSourceBFS(Graph* g, int hubs[], int K, int R) {
    int V = g->V;
    int* dist = (int*)malloc((V + 1) * sizeof(int));
    int* owner = (int*)malloc((V + 1) * sizeof(int));
    int* queue = (int*)malloc((V + 1) * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 1; i <= V; i++) {
        dist[i] = -1;
        owner[i] = -1;
    }

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    // Initialize multi-source queue with hubs in ascending order of index
    for (int i = 0; i < K; i++) {
        int h = hubs[i];
        dist[h] = 0;
        owner[h] = i + 1; // 1-based index hub label
        queue[tail++] = h;
        printf("Initialized Hub %d at vertex %d (Dist: 0)\n", i + 1, h);
    }

    while (head < tail) {
        int u = queue[head++];

        if (dist[u] >= R) continue;

        for (Node* curr = g->adj[u]; curr != NULL; curr = curr->next) {
            int v = curr->vertex;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                owner[v] = owner[u];
                queue[tail++] = v;
                printf("Vertex %d assigned to Hub %d at Distance %d\n", v, owner[v], dist[v]);
            }
        }
    }

    printf("\n=======================================================\n");
    printf("                  VORONOI CELL PARTITION               \n");
    printf("=======================================================\n");
    for (int i = 1; i <= V; i++) {
        if (owner[i] == -1 || dist[i] > R) {
            printf("Vertex %2d : Owner = -1 | Shortest Distance = Unreachable/Exceeds R\n", i);
        } else {
            printf("Vertex %2d : Owner = Hub %d | Shortest Distance = %d\n", i, owner[i], dist[i]);
        }
    }

    free(dist);
    free(owner);
    free(queue);
}

int main() {
    int V, E, K, R;
    printf("=======================================================\n");
    printf("    MULTI-SOURCE BFS VORONOI CELL PARTITIONING          \n");
    printf("=======================================================\n");
    printf("Enter number of vertices (V) and edges (E): ");
    if (scanf("%d %d", &V, &E) != 2 || V <= 0) return 1;

    Graph* g = createGraph(V);
    printf("Enter %d undirected edges (u v):\n", E);
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    printf("Enter number of service hubs (K): ");
    scanf("%d", &K);
    int* hubs = (int*)malloc(K * sizeof(int));
    printf("Enter vertex indices for the %d hubs:\n", K);
    for (int i = 0; i < K; i++) {
        printf("Hub %d vertex: ", i + 1);
        scanf("%d", &hubs[i]);
    }

    printf("Enter radius threshold (R): ");
    scanf("%d", &R);

    multiSourceBFS(g, hubs, K, R);

    free(hubs);
    return 0;
}
