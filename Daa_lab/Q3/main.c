#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Function to generate random array
void generateRandomArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}

// Function to copy array
void copyArray(int source[], int destination[], int n)
{
    for(int i = 0; i < n; i++)
        destination[i] = source[i];
}

// Bubble Sort Version 1
// Stops early if array becomes sorted
long bubbleSortEarlyStop(int arr[], int n)
{
    long comparisons = 0;
    int temp;

    for(int i = 0; i < n-1; i++)
    {
        int swapped = 0;

        for(int j = 0; j < n-i-1; j++)
        {
            comparisons++;

            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swapped = 1;
            }
        }

        if(swapped == 0)
            break;
    }

    return comparisons;
}

// Bubble Sort Version 2
// Always completes all passes
long bubbleSortNormal(int arr[], int n)
{
    long comparisons = 0;
    int temp;

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            comparisons++;

            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    return comparisons;
}

int main()
{
    srand(time(NULL));

    FILE *fp = fopen("bubble_data.dat", "w");

    if(fp == NULL)
    {
        printf("Cannot create file.\n");
        return 0;
    }

    fprintf(fp,"#Size EarlyStop NormalBubble\n");

    int original[MAX];
    int arr1[MAX];
    int arr2[MAX];

    for(int n = 10; n <= 100; n += 10)
    {
        generateRandomArray(original, n);

        copyArray(original, arr1, n);
        copyArray(original, arr2, n);

        long early = bubbleSortEarlyStop(arr1, n);
        long normal = bubbleSortNormal(arr2, n);

        fprintf(fp,"%d %ld %ld\n", n, early, normal);

        printf("Size=%d  Early=%ld  Normal=%ld\n",
               n, early, normal);
    }

    fclose(fp);

    printf("\nData stored in bubble_data.dat\n");

    return 0;
}