#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dist;
    int fuel;
} Station;

typedef struct {
    int data[1000];
    int size;
} MaxHeap;

// Helper function to compare stations by distance
int compareStations(const void* a, const void* b) {
    Station* s1 = (Station*)a;
    Station* s2 = (Station*)b;
    return s1->dist - s2->dist;
}

void pushHeap(MaxHeap* hp, int val) {
    hp->data[hp->size] = val;
    int i = hp->size;
    hp->size++;
    while (i != 0 && hp->data[(i - 1) / 2] < hp->data[i]) {
        int temp = hp->data[i];
        hp->data[i] = hp->data[(i - 1) / 2];
        hp->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int popHeap(MaxHeap* hp) {
    if (hp->size <= 0) return -1;
    int root = hp->data[0];
    hp->data[0] = hp->data[hp->size - 1];
    hp->size--;
    
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (hp->data[left] > hp->data[largest]) largest = left;
        if (right < hp->size && hp->data[right] > hp->data[largest]) largest = right;
        if (largest == i) break;
        int temp = hp->data[i];
        hp->data[i] = hp->data[largest];
        hp->data[largest] = temp;
        i = largest;
    }
    return root;
}

int minRefuelStops(int target, int startFuel, Station stations[], int n) {
    // Ensure stations are sorted by distance from origin
    qsort(stations, n, sizeof(Station), compareStations);

    MaxHeap max_fuel_heap = {.size = 0};
    int stops = 0;
    int curr_fuel = startFuel;
    int i = 0;

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    while (curr_fuel < target) {
        // Push all reachable stations into the Max-Heap
        while (i < n && stations[i].dist <= curr_fuel) {
            pushHeap(&max_fuel_heap, stations[i].fuel);
            printf("Reached Station at dist %d (Fuel: %d) -> Added to available choices.\n",
                   stations[i].dist, stations[i].fuel);
            i++;
        }

        if (max_fuel_heap.size == 0) {
            printf("\n[x] Cannot reach target! Maximum reach achieved: %d\n", curr_fuel);
            return -1; // Unreachable
        }

        int max_fuel_available = popHeap(&max_fuel_heap);
        curr_fuel += max_fuel_available;
        stops++;
        printf(" -> Refueled +%d fuel! Total reachable distance now: %d (Stops: %d)\n",
               max_fuel_available, curr_fuel, stops);
    }

    return stops;
}

int main() {
    int target, startFuel, n;

    printf("=======================================================\n");
    printf("      MINIMUM INITIAL FUEL / REFUELING STOPS           \n");
    printf("=======================================================\n");

    printf("Enter Target Distance (D): ");
    if (scanf("%d", &target) != 1 || target <= 0) {
        printf("Invalid target distance. Exiting.\n");
        return 1;
    }

    printf("Enter Initial Fuel (F): ");
    if (scanf("%d", &startFuel) != 1 || startFuel < 0) {
        printf("Invalid initial fuel. Exiting.\n");
        return 1;
    }

    printf("Enter Number of Stations (n): ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid station count. Exiting.\n");
        return 1;
    }

    Station* stations = (Station*)malloc(n * sizeof(Station));
    if (n > 0 && stations == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    if (n > 0) {
        printf("\nEnter station distance and fuel amount (e.g., '10 60'):\n");
        for (int i = 0; i < n; i++) {
            printf("Station %d: ", i + 1);
            scanf("%d %d", &stations[i].dist, &stations[i].fuel);
        }
    }

    int ans = minRefuelStops(target, startFuel, stations, n);

    printf("=======================================================\n");
    if (ans != -1) {
        printf("RESULT: Minimum refueling stops required: %d\n", ans);
    } else {
        printf("RESULT: Target is UNREACHABLE.\n");
    }
    printf("=======================================================\n");

    if (stations) free(stations);
    return 0;
}