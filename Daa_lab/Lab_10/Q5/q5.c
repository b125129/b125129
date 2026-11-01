#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* parent;
    int* rank;
} DSU;

DSU* createDSU(int n) {
    DSU* dsu = (DSU*)malloc(sizeof(DSU));
    dsu->parent = (int*)malloc((n + 1) * sizeof(int));
    dsu->rank = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        dsu->parent[i] = i;
    }
    return dsu;
}

int find(DSU* dsu, int i) {
    if (dsu->parent[i] == i)
        return i;
    return dsu->parent[i] = find(dsu, dsu->parent[i]);
}

void unionSets(DSU* dsu, int i, int j) {
    int rootI = find(dsu, i);
    int rootJ = find(dsu, j);
    if (rootI != rootJ) {
        if (dsu->rank[rootI] < dsu->rank[rootJ]) {
            dsu->parent[rootI] = rootJ;
        } else if (dsu->rank[rootI] > dsu->rank[rootJ]) {
            dsu->parent[rootJ] = rootI;
        } else {
            dsu->parent[rootJ] = rootI;
            dsu->rank[rootI]++;
        }
    }
}

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, m;
    printf("=======================================================\n");
    printf("     LEXICOGRAPHICALLY SMALLEST PERMUTATION VIA SWAPS  \n");
    printf("=======================================================\n");

    printf("Enter number of elements (n) and number of allowable swaps (m): ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    int* A = (int*)malloc((n + 1) * sizeof(int));
    printf("Enter the permutation A of numbers 1 to %d:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    DSU* dsu = createDSU(n);

    printf("Enter %d allowable swap pairs (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        unionSets(dsu, u, v);
    }

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    int* comp_size = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        int root = find(dsu, i);
        comp_size[root]++;
    }

    int** comp_indices = (int**)malloc((n + 1) * sizeof(int*));
    int** comp_values = (int**)malloc((n + 1) * sizeof(int*));
    int* comp_idx_tracker = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        if (comp_size[i] > 0) {
            comp_indices[i] = (int*)malloc(comp_size[i] * sizeof(int));
            comp_values[i] = (int*)malloc(comp_size[i] * sizeof(int));
        }
    }

    for (int i = 1; i <= n; i++) {
        int root = find(dsu, i);
        int idx = comp_idx_tracker[root]++;
        comp_indices[root][idx] = i;
        comp_values[root][idx] = A[i];
    }

    for (int i = 1; i <= n; i++) {
        if (comp_size[i] > 0) {
            printf("Component Root %d: Size = %d (Sorting indices & values)\n", i, comp_size[i]);
            qsort(comp_indices[i], comp_size[i], sizeof(int), compareInts);
            qsort(comp_values[i], comp_size[i], sizeof(int), compareInts);

            for (int j = 0; j < comp_size[i]; j++) {
                A[comp_indices[i][j]] = comp_values[i][j];
            }
        }
    }

    printf("\n=======================================================\n");
    printf("RESULT: Lexicographically Smallest Permutation:\n[ ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    printf("]\n=======================================================\n");

    free(A);
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
    free(comp_size);
    free(comp_idx_tracker);
    for (int i = 1; i <= n; i++) {
        if (comp_indices[i]) free(comp_indices[i]);
        if (comp_values[i]) free(comp_values[i]);
    }
    free(comp_indices);
    free(comp_values);

    return 0;
}
