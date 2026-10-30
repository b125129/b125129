#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct Edge {
    int to;
    int weight; // 0 or 1
    struct Edge* next;
} Edge;

typedef struct Graph {
    int V;
    Edge** head;
} Graph;

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->head = (Edge**)calloc(V, sizeof(Edge*));
    return g;
}

void addEdge(Graph* g, int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->weight = w;
    e->next = g->head[u];
    g->head[u] = e;
}

typedef struct {
    int u;
    int parity; // 0 for even weight-1 edges, 1 for odd
} State;

typedef struct {
    State* data;
    int front;
    int rear;
    int capacity;
} Deque;

Deque* createDeque(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (State*)malloc(capacity * sizeof(State));
    dq->front = capacity / 2;
    dq->rear = capacity / 2;
    dq->capacity = capacity;
    return dq;
}

void pushFront(Deque* dq, State s) {
    dq->front--;
    dq->data[dq->front] = s;
}

void pushBack(Deque* dq, State s) {
    dq->data[dq->rear] = s;
    dq->rear++;
}

State popFront(Deque* dq) {
    State s = dq->data[dq->front];
    dq->front++;
    return s;
}

int isEmpty(Deque* dq) {
    return dq->front == dq->rear;
}

void solveParityConstrainedBFS(Graph* g, int S, int C) {
    int V = g->V;
    int dist[V][2];
    for (int i = 0; i < V; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    Deque* dq = createDeque(4 * V + 10);
    dist[S][0] = 0;
    pushFront(dq, (State){S, 0});

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    while (!isEmpty(dq)) {
        State curr = popFront(dq);
        int u = curr.u;
        int p = curr.parity;

        for (Edge* e = g->head[u]; e != NULL; e = e->next) {
            int v = e->to;
            int w = e->weight;
            int next_p = p ^ w;
            int next_dist = dist[u][p] + w;

            if (next_dist < dist[v][next_p]) {
                dist[v][next_p] = next_dist;
                printf("Relaxed State: Node %d (Parity %d) -> Node %d (Parity %d) | Weight-1 Dist: %d\n",
                       u, p, v, next_p, next_dist);
                if (w == 0) {
                    pushFront(dq, (State){v, next_p});
                } else {
                    pushBack(dq, (State){v, next_p});
                }
            }
        }
    }

    printf("\n=======================================================\n");
    printf("                    FINAL RESULTS                      \n");
    printf("=======================================================\n");
    for (int v = 0; v < V; v++) {
        int min_cost = INF;
        if (dist[v][0] != INF) {
            int cost0 = dist[v][0];
            if (cost0 < min_cost) min_cost = cost0;
        }
        if (dist[v][1] != INF) {
            int cost1 = dist[v][1] + C;
            if (cost1 < min_cost) min_cost = cost1;
        }

        if (min_cost == INF) {
            printf("Node %d: Unreachable\n", v);
        } else {
            printf("Node %d: Minimum Cost = %d (Even-parity path: %s, Odd-parity path: %s)\n",
                   v, min_cost,
                   (dist[v][0] == INF) ? "N/A" : "Valid",
                   (dist[v][1] == INF) ? "N/A" : "Valid");
        }
    }
}

int main() {
    int V, E, S, C;
    printf("=======================================================\n");
    printf("      0-1 BFS FOR PARITY-CONSTRAINED SHORTEST PATH     \n");
    printf("=======================================================\n");
    printf("Enter number of vertices (V) and edges (E): ");
    if (scanf("%d %d", &V, &E) != 2 || V <= 0) return 1;

    Graph* g = createGraph(V);
    printf("Enter %d directed edges (format: src dest weight [0 or 1]):\n", E);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(g, u, v, w);
    }

    printf("Enter Source Vertex (S) and Penalty Cost (C): ");
    scanf("%d %d", &S, &C);

    solveParityConstrainedBFS(g, S, C);

    return 0;
}
