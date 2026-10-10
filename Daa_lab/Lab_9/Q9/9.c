#include <stdio.h>
#include <stdlib.h>

int canCompleteCircuit(int gas[], int cost[], int n) {
    int total_tank = 0;
    int current_tank = 0;
    int start_station = 0;

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    for (int i = 0; i < n; i++) {
        int net_gas = gas[i] - cost[i];
        total_tank += net_gas;
        current_tank += net_gas;

        printf("Station %d: Gas = %d | Cost = %d | Net = %+d | Current Tank = %d\n",
               i, gas[i], cost[i], net_gas, current_tank);

        // If current_tank drops below 0, we cannot reach station i+1 from the current start_station
        if (current_tank < 0) {
            printf("   -> Tank depleted at station %d! Resetting starting candidate to %d.\n",
                   i, i + 1);
            start_station = i + 1;
            current_tank = 0;
        }
    }

    printf("\nTotal Net Fuel Balance across all stations: %+d\n", total_tank);

    // If total_tank >= 0, a valid circular route is guaranteed
    return (total_tank >= 0) ? start_station : -1;
}

int main() {
    int n;

    printf("=======================================================\n");
    printf("          GAS STATION / CIRCULAR TOUR PROBLEM          \n");
    printf("=======================================================\n");

    printf("Enter number of gas stations (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of stations. Exiting.\n");
        return 1;
    }

    int *gas = (int *)malloc(n * sizeof(int));
    int *cost = (int *)malloc(n * sizeof(int));

    if (gas == NULL || cost == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter gas available at each station:\n");
    for (int i = 0; i < n; i++) {
        printf("Gas at Station %d: ", i);
        scanf("%d", &gas[i]);
    }

    printf("Enter cost (gas needed) to travel to the next station:\n");
    for (int i = 0; i < n; i++) {
        printf("Cost from Station %d to %d: ", i, (i + 1) % n);
        scanf("%d", &cost[i]);
    }

    int start_index = canCompleteCircuit(gas, cost, n);

    printf("=======================================================\n");
    if (start_index != -1) {
        printf("RESULT: Starting Gas Station Index: %d\n", start_index);
    } else {
        printf("RESULT: Impossible to complete the circuit (-1)\n");
    }
    printf("=======================================================\n");

    free(gas);
    free(cost);
    return 0;
}