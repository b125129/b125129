#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

long long bruteSteps = 0;
long long sortSteps = 0;

/* Comparison function for qsort() */
int compare(const void *a, const void *b)
{
    sortSteps++;
    return (*(int *)a - *(int *)b);
}

/* Brute Force Method */
int bruteForce(int arr[], int n)
{
    bruteSteps = 0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            bruteSteps++;

            if(arr[i]==arr[j])
                return 1;
        }
    }

    return 0;
}

/* Sorting Method */
int sortingMethod(int arr[], int n)
{
    sortSteps = 0;

    qsort(arr,n,sizeof(int),compare);

    for(int i=0;i<n-1;i++)
    {
        sortSteps++;

        if(arr[i]==arr[i+1])
            return 1;
    }

    return 0;
}

int main()
{
    FILE *fp;

    fp = fopen("steps.dat","w");

    srand(time(NULL));

    for(int n=100;n<=5000;n+=100)
    {
        int a[MAX];
        int b[MAX];

        for(int i=0;i<n;i++)
        {
            a[i]=rand()%100000;
            b[i]=a[i];
        }

        bruteForce(a,n);
        sortingMethod(b,n);

        fprintf(fp,"%d %lld %lld\n",n,bruteSteps,sortSteps);
    }

    fclose(fp);

    printf("Data saved in steps.dat\n");

    return 0;
}