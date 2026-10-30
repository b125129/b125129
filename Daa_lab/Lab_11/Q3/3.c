#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 2000
#define MAX_L 12

typedef struct {
    char word[MAX_L];
    int dist;
} QueueNode;

int hammingDistance(const char* a, const char* b, int L) {
    int diff = 0;
    for (int i = 0; i < L; i++) {
        if (a[i] != b[i]) diff++;
    }
    return diff;
}

int bidirectionalBFS(char dict[][MAX_L], int N, char* start, char* target, int L) {
    int start_visited[MAX_N] = {0};
    int target_visited[MAX_N] = {0};

    int target_idx = -1;
    for (int i = 0; i < N; i++) {
        if (strcmp(dict[i], target) == 0) {
            target_idx = i;
            break;
        }
    }

    if (target_idx == -1) {
        printf("\nTarget word '%s' is not in the dictionary D!\n", target);
        return -1;
    }

    QueueNode qStart[MAX_N], qTarget[MAX_N];
    int headS = 0, tailS = 0, headT = 0, tailT = 0;

    // Check if start word is in dict
    int start_idx = -1;
    for (int i = 0; i < N; i++) {
        if (strcmp(dict[i], start) == 0) {
            start_idx = i;
            break;
        }
    }

    if (start_idx != -1) start_visited[start_idx] = 1;

    strcpy(qStart[tailS].word, start);
    qStart[tailS].dist = 0;
    tailS++;

    target_visited[target_idx] = 1;
    strcpy(qTarget[tailT].word, target);
    qTarget[tailT].dist = 0;
    tailT++;

    printf("\n=======================================================\n");
    printf("                  EXECUTION TRACE                      \n");
    printf("=======================================================\n");

    while (headS < tailS && headT < tailT) {
        // Expand forward search
        if (tailS - headS <= tailT - headT) {
            QueueNode curr = qStart[headS++];
            printf("Forward Search visiting: %s (Dist: %d)\n", curr.word, curr.dist);

            for (int i = 0; i < N; i++) {
                if (hammingDistance(curr.word, dict[i], L) == 1) {
                    if (target_visited[i]) {
                        // Collision detected!
                        int target_dist = 0;
                        for (int k = 0; k < tailT; k++) {
                            if (strcmp(qTarget[k].word, dict[i]) == 0) {
                                target_dist = qTarget[k].dist;
                                break;
                            }
                        }
                        return curr.dist + 1 + target_dist;
                    }
                    if (!start_visited[i]) {
                        start_visited[i] = 1;
                        strcpy(qStart[tailS].word, dict[i]);
                        qStart[tailS].dist = curr.dist + 1;
                        tailS++;
                    }
                }
            }
        } else { // Expand backward search
            QueueNode curr = qTarget[headT++];
            printf("Backward Search visiting: %s (Dist: %d)\n", curr.word, curr.dist);

            for (int i = 0; i < N; i++) {
                if (hammingDistance(curr.word, dict[i], L) == 1) {
                    if (start_visited[i]) {
                        // Collision detected!
                        int start_dist = 0;
                        for (int k = 0; k < tailS; k++) {
                            if (strcmp(qStart[k].word, dict[i]) == 0) {
                                start_dist = qStart[k].dist;
                                break;
                            }
                        }
                        return curr.dist + 1 + start_dist;
                    }
                    if (!target_visited[i]) {
                        target_visited[i] = 1;
                        strcpy(qTarget[tailT].word, dict[i]);
                        qTarget[tailT].dist = curr.dist + 1;
                        tailT++;
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    int N, L;
    char start[MAX_L], target[MAX_L];
    char dict[MAX_N][MAX_L];

    printf("=======================================================\n");
    printf("   BIDIRECTIONAL BFS WORD TRANSFORMATION SEQUENCE      \n");
    printf("=======================================================\n");

    printf("Enter number of dictionary words (N) and word length (L): ");
    if (scanf("%d %d", &N, &L) != 2 || N <= 0 || L <= 0) return 1;

    printf("Enter start word A: ");
    scanf("%s", start);
    printf("Enter target word B: ");
    scanf("%s", target);

    printf("Enter %d dictionary words:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%s", dict[i]);
    }

    int steps = bidirectionalBFS(dict, N, start, target, L);

    printf("=======================================================\n");
    if (steps != -1) {
        printf("RESULT: Minimum Mutations Required = %d\n", steps);
    } else {
        printf("RESULT: No valid transformation sequence exists (-1)\n");
    }
    printf("=======================================================\n");

    return 0;
}
