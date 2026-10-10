#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[2000];
    int size;
} MaxHeap;

void pushHeap(MaxHeap *hp, int val) {
    hp->data[hp->size] = val;
    int i = hp->size++;
    while (i != 0 && hp->data[(i - 1) / 2] < hp->data[i]) {
        int t = hp->data[i];
        hp->data[i] = hp->data[(i - 1) / 2];
        hp->data[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

int popHeap(MaxHeap *hp) {
    int root = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (hp->data[left] > hp->data[largest]) largest = left;
        if (right < hp->size && hp->data[right] > hp->data[largest]) largest = right;
        if (largest == i) break;
        int t = hp->data[i];
        hp->data[i] = hp->data[largest];
        hp->data[largest] = t;
        i = largest;
    }
    return root;
}

int minDeviation(int nums[], int n) {
    MaxHeap hp = {.size = 0};
    int min_val = 1e9;

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    // Pre-processing: Double odd numbers to get max possible values
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 != 0) {
            printf("Element %d is odd -> Doubled to %d\n", nums[i], nums[i] * 2);
            nums[i] *= 2;
        }
        pushHeap(&hp, nums[i]);
        if (nums[i] < min_val) min_val = nums[i];
    }

    int min_dev = hp.data[0] - min_val;
    int step = 1;

    printf("\nInitial Max: %d | Min: %d | Starting Deviation: %d\n\n", hp.data[0], min_val, min_dev);

    // Repeatedly halve the maximum element while it remains even
    while (hp.data[0] % 2 == 0) {
        int max_val = popHeap(&hp);
        int half = max_val / 2;

        if (half < min_val) min_val = half;
        pushHeap(&hp, half);

        int current_dev = hp.data[0] - min_val;
        if (current_dev < min_dev) min_dev = current_dev;

        printf("Step %d: Halved max element %d -> %d | New Max: %d | New Min: %d | Current Dev: %d\n",
               step++, max_val, half, hp.data[0], min_val, current_dev);
    }

    printf("\nMax element (%d) is now odd and cannot be halved further.\n", hp.data[0]);
    return min_dev;
}

int main() {
    int n;

    printf("=======================================================\n");
    printf("        MINIMISE DEVIATION IN ARRAY (MAX-HEAP)         \n");
    printf("=======================================================\n");

    printf("Enter number of positive integers (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input size. Exiting.\n");
        return 1;
    }

    int *nums = (int *)malloc(n * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the %d positive integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    int ans = minDeviation(nums, n);

    printf("=======================================================\n");
    printf("RESULT: Minimum Possible Deviation: %d\n", ans);
    printf("=======================================================\n");

    free(nums);
    return 0;
}