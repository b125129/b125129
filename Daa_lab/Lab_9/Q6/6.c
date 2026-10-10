#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

typedef struct {
    CharFreq data[256];
    int size;
} MaxHeap;

void pushHeap(MaxHeap *hp, CharFreq cf) {
    hp->data[hp->size] = cf;
    int i = hp->size++;
    while (i != 0 && hp->data[(i - 1) / 2].freq < hp->data[i].freq) {
        CharFreq t = hp->data[i];
        hp->data[i] = hp->data[(i - 1) / 2];
        hp->data[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

CharFreq popHeap(MaxHeap *hp) {
    CharFreq root = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (hp->data[left].freq > hp->data[largest].freq) largest = left;
        if (right < hp->size && hp->data[right].freq > hp->data[largest].freq) largest = right;
        if (largest == i) break;
        CharFreq t = hp->data[i];
        hp->data[i] = hp->data[largest];
        hp->data[largest] = t;
        i = largest;
    }
    return root;
}

typedef struct {
    CharFreq item;
    int valid_idx;
} QueueNode;

char* rearrangeString(char* s, int k) {
    int len = strlen(s);
    if (k <= 1) return strdup(s);

    int counts[256] = {0};
    for (int i = 0; i < len; i++) {
        counts[(unsigned char)s[i]]++;
    }

    MaxHeap hp = {.size = 0};
    for (int i = 0; i < 256; i++) {
        if (counts[i] > 0) {
            CharFreq cf = {(char)i, counts[i]};
            pushHeap(&hp, cf);
        }
    }

    QueueNode queue[256];
    int head = 0, tail = 0;

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int res_idx = 0;

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    while (res_idx < len) {
        // Release characters from cool-down queue back to heap if valid_idx reached
        if (head < tail && (res_idx - queue[head].valid_idx >= 0)) {
            printf("Pos %d: Character '%c' out of cool-down -> Re-added to heap\n", 
                   res_idx, queue[head].item.ch);
            pushHeap(&hp, queue[head].item);
            head++;
        }

        if (hp.size == 0) {
            free(result);
            return NULL; // Impossible to satisfy K distance constraint
        }

        CharFreq curr = popHeap(&hp);
        result[res_idx] = curr.ch;
        curr.freq--;

        printf("Pos %d: Placed '%c' (Remaining count: %d)\n", res_idx, curr.ch, curr.freq);

        if (curr.freq > 0) {
            queue[tail].item = curr;
            queue[tail].valid_idx = res_idx + k;
            printf("   '%c' placed in cool-down until position %d\n", curr.ch, res_idx + k);
            tail++;
        }
        res_idx++;
    }

    result[len] = '\0';
    return result;
}

int main() {
    char str[500];
    int k;

    printf("=======================================================\n");
    printf("      REORGANIZE STRING WITH K-DISTANCE APART          \n");
    printf("=======================================================\n");

    printf("Enter string S: ");
    if (scanf("%499s", str) != 1) {
        printf("Invalid string input. Exiting.\n");
        return 1;
    }

    printf("Enter minimum distance K: ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid K distance entered. Exiting.\n");
        return 1;
    }

    char* rearranged = rearrangeString(str, k);

    printf("=======================================================\n");
    if (rearranged == NULL) {
        printf("RESULT: Impossible to rearrange string with K=%d distance apart.\n", k);
    } else {
        printf("RESULT: Rearranged String: %s\n", rearranged);
        free(rearranged);
    }
    printf("=======================================================\n");

    return 0;
}