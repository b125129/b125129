#include <stdio.h>

// Structure to return both max and min from functions
struct MinMax {
    int min;
    int max;
};

// Function to find max and min using Divide and Conquer
struct MinMax getMinMax(int arr[], int low, int high) {
    struct MinMax result, leftResult, rightResult;
    int mid;

    // Base Case 1: If there is only one element
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    // Base Case 2: If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    // Divide Step: Find middle point
    mid = low + (high - low) / 2;

    // Conquer Step: Recursively find max and min in left and right halves
    leftResult = getMinMax(arr, low, mid);
    rightResult = getMinMax(arr, mid + 1, high);

    // Combine Step: Compare max and min from both halves
    if (leftResult.max > rightResult.max) {
        result.max = leftResult.max;
    } else {
        result.max = rightResult.max;
    }

    if (leftResult.min < rightResult.min) {
        result.min = leftResult.min;
    } else {
        result.min = rightResult.min;
    }

    return result;
}

int main() {
     int n ;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);    
    int arr[n];
    printf("Enter %d elements in sorted order:\n", n);
    for(int i = 0; i < n; i++) {    
        scanf("%d", &arr[i]);
    }

    struct MinMax minmax = getMinMax(arr, 0, n - 1);

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    printf("Minimum element: %d\n", minmax.min);
    printf("Maximum element: %d\n", minmax.max);

    return 0;
}