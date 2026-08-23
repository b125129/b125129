#include <stdio.h>
#include <stdlib.h>

/* Merge two sorted portions */
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
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return 1;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int main() {
    int n, x;

    printf("Enter size of the sets: ");
    scanf("%d", &n);

    int S1[n], S2[n];

    printf("Enter elements of S1:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &S1[i]);

    printf("Enter elements of S2:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &S2[i]);

    printf("Enter target value x: ");
    scanf("%d", &x);

    /* Sort S2 */
    mergeSort(S2, 0, n - 1);

    /* Search for complement of each S1 element */
    for (int i = 0; i < n; i++) {
        int required = x - S1[i];

        if (binarySearch(S2, n, required)) {
            printf("Pair found: (%d, %d)\n",
                   S1[i], required);
            return 0;
        }
    }

    printf("No pair exists whose sum is %d.\n", x);

    return 0;
}