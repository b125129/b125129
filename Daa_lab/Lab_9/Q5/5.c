#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int minCandies(int ratings[], int n) {
    int* candies = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) candies[i] = 1;

    // Left to Right Pass
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to Left Pass
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int total_candies = 0;
    printf("\n=======================================================\n");
    printf("               CANDY ALLOCATION TABLE                  \n");
    printf("=======================================================\n");
    printf("%-12s %-12s %-15s\n", "Child Index", "Rating", "Candies Given");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-12d %-12d %-15d\n", i + 1, ratings[i], candies[i]);
        total_candies += candies[i];
    }

    free(candies);
    return total_candies;
}

int main() {
    int n;

    printf("=======================================================\n");
    printf("               CANDY DISTRIBUTION PROBLEM             \n");
    printf("=======================================================\n");

    printf("Enter number of children (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of children. Exiting.\n");
        return 1;
    }

    int* ratings = (int*)malloc(n * sizeof(int));
    if (ratings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter ratings for each of the %d children:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Child %d rating: ", i + 1);
        scanf("%d", &ratings[i]);
    }

    int total = minCandies(ratings, n);

    printf("=======================================================\n");
    printf("RESULT: Minimum Total Candies Required: %d\n", total);
    printf("=======================================================\n");

    free(ratings);
    return 0;
}