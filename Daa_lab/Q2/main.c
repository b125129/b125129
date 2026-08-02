#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Different numbers of tosses
int tosses[] = {100, 200, 500, 1000, 2000, 5000, 7500, 10000};
        int numTests = sizeof(tosses) / sizeof(tosses[0]);

    FILE *fp;
    fp = fopen("results.dat", "w");

    if (fp == NULL) {
        printf("Error creating results.dat\n");
        return 1;
    }

    fprintf(fp, "# Tosses FairCoin BiasedCoin\n");

    srand(time(NULL));

    printf("------------------------------------------------------------\n");
    printf("      Fair Coin vs Biased Coin Simulation\n");
    printf("------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s\n",
           "Tosses", "Fair Coin", "Biased Coin (0.7)");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < numTests; i++) {

        int n = tosses[i];
        int fairHeads = 0;
        int biasedHeads = 0;

        // Fair Coin Simulation
        for (int j = 0; j < n; j++) {
            if (rand() % 2)
                fairHeads++;
        }

        // Biased Coin Simulation (70% chance of HEAD)
        for (int j = 0; j < n; j++) {
            double r = (double)rand() / RAND_MAX;
            if (r < 0.7)
                biasedHeads++;
        }

        double fairProb = (double)fairHeads / n;
        double biasedProb = (double)biasedHeads / n;

        printf("%-10d %-20.4f %-20.4f\n",
               n, fairProb, biasedProb);

        fprintf(fp, "%d %.4f %.4f\n",
                n, fairProb, biasedProb);
    }

    fclose(fp);
    
    FILE *gp = fopen("plot.gnu", "w");

if (gp == NULL)
{
    printf("Error creating plot.gnu\n");
    return 1;
}

fprintf(gp, "set terminal pngcairo size 900,600\n");
fprintf(gp, "set output 'coin_probability.png'\n");
fprintf(gp, "set title 'Fair vs Biased Coin Toss Simulation'\n");
fprintf(gp, "set xlabel 'Number of Tosses'\n");
fprintf(gp, "set ylabel 'Estimated Probability of Head'\n");
fprintf(gp, "set grid\n");
fprintf(gp, "set logscale x\n");
fprintf(gp, "set xtics ('100' 100,'500' 500,'1000' 1000,'5000' 5000,'10000' 10000)\n");
fprintf(gp, "set yrange [0.4:0.8]\n");
fprintf(gp, "set arrow from 100,0.5 to 10000,0.5 nohead dt 2\n");
fprintf(gp, "set arrow from 100,0.7 to 10000,0.7 nohead dt 2\n");
fprintf(gp,
"plot 'results.dat' using 1:2 with linespoints lw 2 pt 7 title 'Fair Coin',\\\n"
"     'results.dat' using 1:3 with linespoints lw 2 pt 5 title 'Biased Coin'\n");

fclose(gp);

system("gnuplot plot.gnu");
    
    printf("------------------------------------------------------------\n");
    printf("Data saved successfully to results.dat\n");
    printf("Use Gnuplot with plot.gnu to generate the graph.\n");

    return 0;
}