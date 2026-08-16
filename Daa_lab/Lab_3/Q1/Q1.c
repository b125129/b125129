#include <stdio.h>
   
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid + 1; // Return index (1-based)

        // If the element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // Element is not present in array
    return -1;
}

int ternarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if x is present at mid1
        if (arr[mid1] == x)
            return mid1 + 1; // Return index (1-based)

        // Check if x is present at mid2
        if (arr[mid2] == x)
            return mid2 + 1; // Return index (1-based)

        // If x is present in left one-third
        if (x < arr[mid1])
            return ternarySearch(arr, l, mid1 - 1, x);

        // If x is present in right one-third
        else if (x > arr[mid2])
            return ternarySearch(arr, mid2 + 1, r, x);

        // If x is present in middle one-third
        else
            return ternarySearch(arr, mid1 + 1, mid2 - 1, x);
    }

    // Element is not present in array
    return -1;
}

int main() {
   int  n ;
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);

   int arr[n];
   printf("Enter %d elements in sorted order:\n", n);
   for(int i = 0; i < n; i++) {
       scanf("%d", &arr[i]);
   }

   int x;
   printf("Enter the element to search: ");
   scanf("%d", &x);

    // Binary Search
    int resultBinary = binarySearch(arr, 0, n - 1, x);

    if (resultBinary != -1)
        printf("Element found at index (Binary Search): %d\n", resultBinary);
    else
        printf("Element not found (Binary Search)\n");

    // Ternary Search
    int resultTernary = ternarySearch(arr, 0, n - 1, x);

    if (resultTernary != -1)
        printf("Element found at index (Ternary Search): %d\n", resultTernary);
    else
        printf("Element not found (Ternary Search)\n");

    return 0;
}