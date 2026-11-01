#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* parent;
    int* size;
    long long* weight;
    int* version; // To track component mutations for heap lazy deletion
} DSU;

typedef struct {
    long long weight;
    int root;
    int version;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MaxHeap;

DSU* createDSU(int n, long long vertex_weights[]) {
    DSU* dsu = (DSU*)malloc(sizeof(DSU));
    dsu->parent = (int*)malloc((n + 1) * sizeof(int));
    dsu->size = (int*)malloc((n + 1) * sizeof(int));
    dsu->weight = (long long*)malloc((n + 1) * sizeof(long long));
    dsu->version = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        dsu->parent[i] = i;
        dsu->size[i] = 1;
        dsu->weight[i] = vertex_weights[i];
    }
    return dsu;
}

int find(DSU* dsu, int i) {
    if (dsu->parent[i] == i)
        return i;
    return dsu->parent[i] = find(dsu, dsu->parent[i]);
}

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* hp = (MaxHeap*)malloc(sizeof(MaxHeap));
    hp->data = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    hp->size = 0;
    hp->capacity = capacity;
    return hp;
}

void pushHeap(MaxHeap* hp, long long weight, int root, int version) {
    int i = hp->size++;
    hp->data[i] = (HeapNode){weight, root, version};
    while (i != 0 && hp->data[(i - 1) / 2].weight < hp->data[i].weight) {
        HeapNode temp = hp->data[i];
        hp->data[i] = hp->data[(i - 1) / 2];
        hp->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

HeapNode popHeap(MaxHeap* hp) {
    HeapNode root = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (hp->data[left].weight > hp->data[largest].weight) largest = left;
        if (right < hp->size && hp->data[right].weight > hp->data[largest].weight) largest = right;
        if (largest == i) break;
        HeapNode temp = hp->data[i];
        hp->data[i] = hp->data[largest];
        hp->data[largest] = temp;
        i = largest;
    }
    return root;
}

int main() {
    int V, E, K;
    printf("=======================================================\n");
    printf("      MAXIMUM WEIGHT COMPONENT WITH SIZE CONSTRAINTS   \n");
    printf("=======================================================\n");

    printf("Enter number of vertices (V), edges (E), and size threshold (K): ");
    if (scanf("%d %d %d", &V, &E, &K) != 3 || V <= 0 || K <= 0) {
        printf("Invalid input parameters. Exiting.\n");
        return 1;
    }

    long long* vertex_weights = (long long*)malloc((V + 1) * sizeof(long long));
    printf("Enter weights for the %d vertices (v1 to v%d):\n", V, V);
    for (int i = 1; i <= V; i++) {
        printf("Vertex %d weight: ", i);
        scanf("%lld", &vertex_weights[i]);
    }

    DSU* dsu = createDSU(V, vertex_weights);
    MaxHeap* hp = createMaxHeap(4 * V + E + 10);

    // Initially, every vertex is its own component of size 1
    for (int i = 1; i <= V; i++) {
        if (1 <= K) {
            pushHeap(hp, dsu->weight[i], i, dsu->version[i]);
        }
    }

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    printf("Enter %d edges sequentially (format: u v):\n", E);
    for (int edge_idx = 1; edge_idx <= E; edge_idx++) {
        int u, v;
        scanf("%d %d", &u, &v);

        int rootU = find(dsu, u);
        int rootV = find(dsu, v);

        if (rootU != rootV) {
            // Union by size
            if (dsu->size[rootU] < dsu->size[rootV]) {
                int temp = rootU; rootU = rootV; rootV = temp;
            }

            // Merge rootV into rootU
            dsu->parent[rootV] = rootU;
            dsu->size[rootU] += dsu->size[rootV];
            dsu->weight[rootU] += dsu->weight[rootV];
            dsu->version[rootU]++;
            dsu->version[rootV]++;

            // If new component size <= K, push its weight to max heap
            if (dsu->size[rootU] <= K) {
                pushHeap(hp, dsu->weight[rootU], rootU, dsu->version[rootU]);
            }
        }

        // Clean up heap top for valid components (lazy deletion)
        long long max_valid_weight = -1;
        while (hp->size > 0) {
            HeapNode top = hp->data[0];
            int current_root = find(dsu, top.root);
            // Check if top represents current component root, active version, and size <= K
            if (current_root == top.root && dsu->version[top.root] == top.version && dsu->size[top.root] <= K) {
                max_valid_weight = top.weight;
                break;
            } else {
                popHeap(hp);
            }
        }

        printf("After Edge %d (%d - %d): Max Weight Component (Size <= %d) = %lld\n",
               edge_idx, u, v, K, max_valid_weight);
    }

    printf("=======================================================\n");
    printf("RESULT: Processing complete for all %d edges.\n", E);
    printf("=======================================================\n");

    free(vertex_weights);
    free(dsu->parent);
    free(dsu->size);
    free(dsu->weight);
    free(dsu->version);
    free(dsu);
    free(hp->data);
    free(hp);

    return 0;
}
