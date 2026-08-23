#include <stdio.h>

int findTransition(int A[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if this is the first 1
        if (A[mid] == 1 && (mid == 0 || A[mid - 1] == 0))
            return mid;

        if (A[mid] == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // No transition found
}

int main() {
    int A[] = {0, 0, 0, 0, 1, 1, 1, 1};
    int n = sizeof(A) / sizeof(A[0]);

    int index = findTransition(A, n);

    if (index != -1)
        printf("Transition point is at index %d\n", index);
    else
        printf("No transition point found.\n");

    return 0;
}