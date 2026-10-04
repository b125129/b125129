#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_KEYS 100
#define EPSILON 1e-9

/*
    Arrays are sized MAX_KEYS + 2 because the algorithm uses
    1-based indexing and accesses index n + 1.
*/
double cost[MAX_KEYS + 2][MAX_KEYS + 2];
double weight[MAX_KEYS + 2][MAX_KEYS + 2];
int root[MAX_KEYS + 2][MAX_KEYS + 2];

double p[MAX_KEYS + 2];
double q[MAX_KEYS + 2];

void printTree(int i, int j, int parent, char side)
{
    /*
        If i > j, this is a dummy key.

        For an empty subtree:
        - left subtree of key r contains d(r - 1)
        - right subtree of key r contains d(j)
    */
    if (i > j)
    {
        if (parent != -1)
        {
            printf("d%d is the %s child of k%d\n",
                   j, side == 'L' ? "left" : "right", parent);
        }
        return;
    }

    int r = root[i][j];

    if (parent == -1)
    {
        printf("k%d is the root\n", r);
    }
    else
    {
        printf("k%d is the %s child of k%d\n",
               r, side == 'L' ? "left" : "right", parent);
    }

    printTree(i, r - 1, r, 'L');
    printTree(r + 1, j, r, 'R');
}

int main(void)
{
    int n;
    double probabilitySum = 0.0;

    printf("Enter number of keys (1-%d): ", MAX_KEYS);

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_KEYS)
    {
        printf("Invalid number of keys.\n");
        return EXIT_FAILURE;
    }

    printf("\nEnter successful search probabilities p[1..%d]:\n", n);

    for (int i = 1; i <= n; i++)
    {
        if (scanf("%lf", &p[i]) != 1 || p[i] < 0.0)
        {
            printf("Invalid successful-search probability.\n");
            return EXIT_FAILURE;
        }

        probabilitySum += p[i];
    }

    printf("\nEnter unsuccessful search probabilities q[0..%d]:\n", n);

    for (int i = 0; i <= n; i++)
    {
        if (scanf("%lf", &q[i]) != 1 || q[i] < 0.0)
        {
            printf("Invalid unsuccessful-search probability.\n");
            return EXIT_FAILURE;
        }

        probabilitySum += q[i];
    }

    if (fabs(probabilitySum - 1.0) > EPSILON)
    {
        printf("\nError: probabilities must sum to 1.\n");
        printf("Current sum = %.10f\n", probabilitySum);
        return EXIT_FAILURE;
    }

    /*
        Base case:
        cost[i][i - 1] and weight[i][i - 1]
        represent an empty subtree containing dummy key d[i - 1].
    */
    for (int i = 1; i <= n + 1; i++)
    {
        cost[i][i - 1] = q[i - 1];
        weight[i][i - 1] = q[i - 1];
    }

    /*
        Dynamic programming computation.

        length = number of real keys in the subtree.
    */
    for (int length = 1; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            weight[i][j] =
                weight[i][j - 1] + p[j] + q[j];

            cost[i][j] = HUGE_VAL;

            for (int r = i; r <= j; r++)
            {
                double currentCost =
                    cost[i][r - 1] +
                    cost[r + 1][j] +
                    weight[i][j];

                if (currentCost < cost[i][j])
                {
                    cost[i][j] = currentCost;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("\nMinimum expected search cost = %.6f\n",
           cost[1][n]);

    printf("\nOptimal Binary Search Tree:\n");
    printTree(1, n, -1, ' ');

    return EXIT_SUCCESS;
}
