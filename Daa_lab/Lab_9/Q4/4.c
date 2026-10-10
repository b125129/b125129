#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[1000];
    int size;
} MinHeap;

void push(MinHeap *hp, int val) {
    hp->data[hp->size] = val;
    int i = hp->size++;
    while (i != 0 && hp->data[(i - 1) / 2] > hp->data[i]) {
        int t = hp->data[i];
        hp->data[i] = hp->data[(i - 1) / 2];
        hp->data[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

int pop(MinHeap *hp) {
    int root = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (hp->data[left] < hp->data[smallest]) smallest = left;
        if (right < hp->size && hp->data[right] < hp->data[smallest]) smallest = right;
        if (smallest == i) break;
        int t = hp->data[i];
        hp->data[i] = hp->data[smallest];
        hp->data[smallest] = t;
        i = smallest;
    }
    return root;
}

int connectSticks(int sticks[], int n) {
    if (n <= 1) return 0;

    MinHeap hp = {.size = 0};
    for (int i = 0; i < n; i++) {
        push(&hp, sticks[i]);
    }

    int total_cost = 0;
    int step = 1;

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    while (hp.size > 1) {
        int first = pop(&hp);
        int second = pop(&hp);
        int cost = first + second;
        total_cost += cost;

        printf("Step %d: Connected sticks of length %d and %d -> New stick length: %d (Cost: %d)\n",
               step++, first, second, cost, cost);

        push(&hp, cost);
    }

    return total_cost;
}

int main() {
    int n;

    printf("=======================================================\n");
    printf("         MINIMUM COST TO CONNECT STICKS                \n");
    printf("=======================================================\n");

    printf("Enter number of sticks (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of sticks. Exiting.\n");
        return 1;
    }

    int *sticks = (int *)malloc(n * sizeof(int));
    if (sticks == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the lengths of the %d sticks:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Stick %d length: ", i + 1);
        scanf("%d", &sticks[i]);
    }

    int min_cost = connectSticks(sticks, n);

    printf("=======================================================\n");
    printf("RESULT: Minimum Total Cost to Connect All Sticks: %d\n", min_cost);
    printf("=======================================================\n");

    free(sticks);
    return 0;
}