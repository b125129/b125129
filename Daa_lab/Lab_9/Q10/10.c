#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leastInterval(char tasks[], int taskSize, int n) {
    int freq[26] = {0};
    int max_freq = 0;
    int max_freq_count = 0;

    // Count frequencies of each task
    for (int i = 0; i < taskSize; i++) {
        freq[tasks[i] - 'A']++;
        if (freq[tasks[i] - 'A'] > max_freq) {
            max_freq = freq[tasks[i] - 'A'];
        }
    }

    // Count how many tasks have the maximum frequency
    for (int i = 0; i < 26; i++) {
        if (freq[i] == max_freq) {
            max_freq_count++;
        }
    }

    // Mathematical Greedy Formula:
    // Formula calculation: (max_freq - 1) * (n + 1) + max_freq_count
    int empty_slots = (max_freq - 1) * (n + 1) + max_freq_count;
    int total_units = (empty_slots > taskSize) ? empty_slots : taskSize;

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");
    printf("Total Tasks Count     : %d\n", taskSize);
    printf("Max Frequency         : %d\n", max_freq);
    printf("Tasks with Max Freq   : %d\n", max_freq_count);
    printf("Cooling Distance (n)  : %d\n", n);
    printf("Formula Output        : %d slots\n", empty_slots);
    printf("Idle Slots Needed     : %d\n", (total_units - taskSize > 0) ? (total_units - taskSize) : 0);

    return total_units;
}

int main() {
    char taskStr[1000];
    int n;

    printf("=======================================================\n");
    printf("        TASK SCHEDULER WITH COOLING INTERVALS          \n");
    printf("=======================================================\n");

    printf("Enter task array as a continuous string : ");
    if (scanf("%999s", taskStr) != 1) {
        printf("Invalid input for tasks. Exiting.\n");
        return 1;
    }

    printf("Enter cooling interval (n): ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid cooling interval. Exiting.\n");
        return 1;
    }

    int taskSize = strlen(taskStr);
    int total_time = leastInterval(taskStr, taskSize, n);

    printf("=======================================================\n");
    printf("RESULT: Minimum Units of Time Required: %d\n", total_time);
    printf("=======================================================\n");

    return 0;
}