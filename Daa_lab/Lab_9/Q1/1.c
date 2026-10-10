#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double v;      // base value
    double w;      // weight
    double lambda; // decay rate
    double density;// v / w
} Item;

// Comparator to sort items in descending order of density (v/w)
int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->density > itemA->density) return 1;
    if (itemB->density < itemA->density) return -1;
    return 0;
}

void solveFractionalKnapsackDecay(Item items[], int n, double W) {
    // Sort items by initial value density (v_i / w_i) descending
    qsort(items, n, sizeof(Item), compareItems);

    double current_weight = 0.0;
    double current_time = 0.0;
    double total_value = 0.0;

    printf("\n=======================================================\n");
    printf("                  EXECUTION RESULTS                    \n");
    printf("=======================================================\n");
    printf("%-8s %-12s %-12s %-15s %-15s\n", "Item ID", "Weight Taken", "Fraction", "Avg Density", "Value Gained");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < n && current_weight < W; i++) {
        double rem_capacity = W - current_weight;
        double take_weight = (items[i].w < rem_capacity) ? items[i].w : rem_capacity;
        
        double frac = take_weight / items[i].w;
        double delta_t = take_weight; // processing rate: 1 unit weight per unit time

        // Average effective density during this processing time interval
        double avg_density = items[i].density - items[i].lambda * (current_time + delta_t / 2.0);

        if (avg_density <= 0) {
            printf("%-8d %-12s %-12s %-15.2f %-15s (Skipped - Decayed to <= 0)\n", 
                   items[i].id, "0.00", "0.00", avg_density, "0.00");
            continue;
        }

        double gained_val = avg_density * take_weight;
        total_value += gained_val;
        current_weight += take_weight;
        current_time += delta_t;

        printf("%-8d %-12.2f %-12.2f %-15.2f %-15.2f\n",
               items[i].id, take_weight, frac, avg_density, gained_val);
    }

    printf("-------------------------------------------------------\n");
    printf("Total Knapsack Capacity Used : %.2f / %.2f\n", current_weight, W);
    printf("Total Time Elapsed           : %.2f time units\n", current_time);
    printf("Maximum Total Value Achieved : %.2f\n", total_value);
    printf("=======================================================\n");
}

int main() {
    int n;
    double W;

    printf("=======================================================\n");
    printf(" FRACTIONAL KNAPSACK WITH DETERIORATION RATE (GREEDY)  \n");
    printf("=======================================================\n");

    printf("Enter total Knapsack Capacity (W): ");
    if (scanf("%lf", &W) != 1 || W <= 0) {
        printf("Invalid capacity entered. Exiting.\n");
        return 1;
    }

    printf("Enter number of items (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of items. Exiting.\n");
        return 1;
    }

    Item *items = (Item *)malloc(n * sizeof(Item));
    if (items == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\n--- Enter Details for Each Item ---\n");
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("\nItem %d:\n", i + 1);
        
        printf("  Base Value (v_%d)    : ", i + 1);
        scanf("%lf", &items[i].v);
        
        printf("  Weight (w_%d)        : ", i + 1);
        scanf("%lf", &items[i].w);
        
        printf("  Decay Rate (lambda_%d): ", i + 1);
        scanf("%lf", &items[i].lambda);

        if (items[i].w <= 0) {
            printf("Weight must be positive. Defaulting weight to 1.0\n");
            items[i].w = 1.0;
        }

        items[i].density = items[i].v / items[i].w;
    }

    solveFractionalKnapsackDecay(items, n, W);

    free(items);
    return 0;
}