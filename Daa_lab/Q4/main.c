#include <stdio.h>
#include <math.h>

// Function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n-1, source, destination, auxiliary);

    printf("Move disk %d from %c to %c\n", n, source, destination);

    towerOfHanoi(n-1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nSteps to solve Tower of Hanoi:\n\n");

    towerOfHanoi(n,'A','B','C');

    printf("\n----------------------------------\n");

    // Create data file for plotting
    FILE *fp = fopen("moves.dat","w");

    if(fp == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    printf("\nNumber of moves:\n");

    for(int i=1;i<=n;i++)
    {
        int moves = pow(2,i)-1;

        printf("Disks = %d   Moves = %d\n",i,moves);

        fprintf(fp,"%d %d\n",i,moves);
    }

    fclose(fp);

    printf("\nData saved to moves.dat\n");

    return 0;
}