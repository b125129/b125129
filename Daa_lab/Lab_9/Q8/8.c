#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(Interval intervals[], int n) {
    int* starts = (int*)malloc(n * sizeof(int));
    int* ends = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        starts[i] = intervals[i].start;
        ends[i] = intervals[i].end;
    }

    qsort(starts, n, sizeof(int), compareInt);
    qsort(ends, n, sizeof(int), compareInt);

    int rooms = 0, max_rooms = 0;
    int s_ptr = 0, e_ptr = 0;

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    while (s_ptr < n) {
        if (starts[s_ptr] < ends[e_ptr]) {
            rooms++;
            if (rooms > max_rooms) max_rooms = rooms;
            printf("Time %2d: Meeting started -> Rooms currently in use: %d\n", starts[s_ptr], rooms);
            s_ptr++;
        } else {
            rooms--;
            printf("Time %2d: Meeting ended   -> Rooms currently in use: %d\n", ends[e_ptr], rooms);
            e_ptr++;
        }
    }

    free(starts);
    free(ends);
    return max_rooms;
}

int main() {
    int n;

    printf("=======================================================\n");
    printf("            MINIMUM MEETING ROOMS REQUIRED             \n");
    printf("=======================================================\n");

    printf("Enter number of meetings (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of meetings. Exiting.\n");
        return 1;
    }

    Interval* meetings = (Interval*)malloc(n * sizeof(Interval));
    if (meetings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter start and end times for each meeting (e.g. '0 30'):\n");
    for (int i = 0; i < n; i++) {
        printf("Meeting %d: ", i + 1);
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    int rooms = minMeetingRooms(meetings, n);

    printf("=======================================================\n");
    printf("RESULT: Minimum Conference Rooms Required: %d\n", rooms);
    printf("=======================================================\n");

    free(meetings);
    return 0;
}