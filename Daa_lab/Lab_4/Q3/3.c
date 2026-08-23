#include <stdio.h>
#include <stdlib.h>

/* Merge function */
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

/* Merge Sort */
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/* Binary Search */
int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return 1;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

/*
 * Generate all combinations of k-1 elements.
 * For every combination, find the required
 * kth element using binary search.
 */
int findCombination(int arr[], int n, int k, int target,
                    int start, int depth, long long sum) {

    /* We have selected k-1 elements */
    if (depth == k - 1) {
        long long required = (long long)target - sum;

        if (binarySearch(arr, n, (int)required)) {
            return 1;
        }

        return 0;
    }

    for (int i = start; i < n; i++) {

        if (findCombination(arr, n, k, target,
                            i + 1, depth + 1,
                            sum + arr[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, k, T;

    printf("Enter number of elements n: ");
    scanf("%d", &n);

    int S[n];

    printf("Enter the elements of S:\n");
    for (int i = 0; i < n; i++)     scanf("%d", &S[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter target T: ");
    scanf("%d", &T);

    if (k < 2 || k > n) {
        printf("Invalid value of k.\n");
        return 1;
    }

    /* Sort the set */
    mergeSort(S, 0, n - 1);

    printf("\nSorted set: ");
    for (int i = 0; i < n; i++)
        printf("%d ", S[i]);

    printf("\n");

    /* Find k elements whose sum is T */
    if (findCombination(S, n, k, T, 0, 0, 0))
        printf("YES: %d elements can sum to %d.\n", k, T);
    else
        printf("NO: %d elements cannot sum to %d.\n", k, T);
    return 0;
}