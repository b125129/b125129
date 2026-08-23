#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char expression[50];

    double coefficient;   // Constant multiplier
    double exponent;      // Power of n

    int hasLog;           // 1 if log(n) is present
    int isExponential;    // 1 if function is a^n
    int isSuperPoly;      // 1 if function is n^(log n)
} Function;

Function functions[] = {
    {"1/n",           1,      -1,   0, 0, 0},
    {"log2(n)",       1,       0,   1, 0, 0},

    {"12sqrt(n)",     12,    0.5,   0, 0, 0},
    {"50n^0.5",       50,    0.5,   0, 0, 0},

    {"n^0.51",        1,     0.51,  0, 0, 0},

    {"nlog2(n)",      1,       1,   1, 0, 0},

    {"2^32 n",        4294967296.0, 1, 0, 0, 0},

    {"100n^2+6n",     100,     2,   0, 0, 0},

    {"n^2-324",       1,       2,   0, 0, 0},

    {"2n^3",          2,       3,   0, 0, 0},

    {"n^(log2 n)",    1,       0,   0, 0, 1},

    {"3^n",           3,       0,   0, 1, 0}
};

void printBigO(Function f){
    printf("%-15s --> ", f.expression);

    if(f.isExponential)
    {
        printf("O(3^n)");
    }

    else if(f.isSuperPoly)
    {
        printf("O(n^(log n))");
    }

    else if(f.hasLog && f.exponent == 0)
    {
        printf("O(log n)");
    }

    else if(f.hasLog && f.exponent == 1)
    {
        printf("O(n log n)");
    }

    else if(f.exponent == -1)
    {
        printf("O(1/n)");
    }

    else if(f.exponent == 0.5)
    {
        printf("O(sqrt(n))");
    }

    else if(f.exponent == 1)
    {
        printf("O(n)");
    }

    else
    {
        printf("O(n^%.2f)", f.exponent);
    }

    printf("\n");
}

int getRank(Function f)
{
    if(f.exponent == -1)
        return 1;               // 1/n

    if(f.hasLog && f.exponent == 0)
        return 2;               // log n

    if(f.exponent == 0.5)
        return 3;               // sqrt(n)

    if(f.exponent == 0.51)
        return 4;               // n^0.51

    if(f.hasLog && f.exponent == 1)
        return 5;               // n log n

    if(f.exponent == 1)
        return 6;               // n

    if(f.exponent == 2)
        return 7;               // n^2

    if(f.exponent == 3)
        return 8;               // n^3

    if(f.isSuperPoly)
        return 9;               // n^(log n)

    if(f.isExponential)
        return 10;              // 3^n

    return 100;
}

void sortFunctions(Function arr[], int size)
{
    int i, j;
    Function temp;

    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(getRank(arr[j]) > getRank(arr[j + 1]))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double evaluate(Function f, double n)
{
    if(f.isExponential)
        return pow(3,n);

    if(f.isSuperPoly)
        return pow(n,log2(n));

    if(f.hasLog && f.exponent==0)
        return log2(n);

    if(f.hasLog && f.exponent==1)
        return n*log2(n);

    return f.coefficient*pow(n,f.exponent);
}

void generateDataFile(Function functions[], int size)
{
    FILE *fp = fopen("functions.dat", "w");

    if(fp == NULL)
    {
        printf("Error creating data file.\n");
        return;
    }

    // Header
    fprintf(fp, "# n values\n");

    // Values of n
    for(int n=1;n<=50;n++)
    {
        fprintf(fp,"%d",n);

        for(int i=0;i<size;i++)
        {
            fprintf(fp," %.10lf",evaluate(functions[i],n));
        }

        fprintf(fp,"\n");
    }

    fclose(fp);
}

void generatePlotScript()
{
    FILE *gp = fopen("plot.gp","w");

    if(gp==NULL)
    {
        printf("Error creating plot script.\n");
        return;
    }

    fprintf(gp,"set title 'Asymptotic Growth of Functions'\n");
    fprintf(gp,"set xlabel 'n'\n");
    fprintf(gp,"set ylabel 'Function Value'\n");
    fprintf(gp,"set grid\n");
    fprintf(gp,"set key outside\n");

    fprintf(gp, "set key outside right\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set terminal qt font 'Arial,10'\n");
    fprintf(gp, "set xlabel 'n'\n");
    fprintf(gp, "set ylabel 'Function Value (log scale)'\n");


    // This is the important line
    fprintf(gp,"set logscale y\n\n");

    fprintf(gp,
"plot "
"'functions.dat' using 1:2  with lines lw 2 title '1/n',\\\n"
"'functions.dat' using 1:3  with lines lw 2 title 'log2(n)',\\\n"
"'functions.dat' using 1:4  with lines lw 2 title '12sqrt(n)',\\\n"
"'functions.dat' using 1:5  with lines lw 2 title '50n^0.5',\\\n"
"'functions.dat' using 1:6  with lines lw 2 title 'n^0.51',\\\n"
"'functions.dat' using 1:7  with lines lw 2 title 'nlog2(n)',\\\n"
"'functions.dat' using 1:8  with lines lw 2 title '2^32 n',\\\n"
"'functions.dat' using 1:9  with lines lw 2 title '100n^2+6n',\\\n"
"'functions.dat' using 1:10 with lines lw 2 title 'n^2-324',\\\n"
"'functions.dat' using 1:11 with lines lw 2 title '2n^3',\\\n"
"'functions.dat' using 1:12 with lines lw 2 title 'n^(log2 n)',\\\n"
"'functions.dat' using 1:13 with lines lw 2 title '3^n'\n");

    fprintf(gp,"\npause -1\n");

    fclose(gp);
}

void plotGraph()
{
    system("gnuplot plot.gp");
}

int main()
{
    int n = sizeof(functions) / sizeof(functions[0]);

    printf("===== Original Functions and Big-O =====\n\n");

    for(int i = 0; i < n; i++)
    {
        printBigO(functions[i]);
    }

    sortFunctions(functions, n);

    printf("\n===== Increasing Order of Growth =====\n\n");

    for(int i = 0; i < n; i++)
    {
        printf("%2d. %s\n", i + 1, functions[i].expression);
    }

    printf("\n");


    generateDataFile(functions,n);

generatePlotScript();

printf("\nOpening gnuplot...\n");

plotGraph();

    return 0;
}
