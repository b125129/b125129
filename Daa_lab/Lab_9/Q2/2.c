#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

typedef struct {
    char ch;
    int length;
    unsigned int code;
} CanonicalCode;

typedef struct {
    int size;
    Node* array[256];
} MinHeap;

Node* createNode(char ch, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void swapNode(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

Node* extractMin(MinHeap* heap) {
    Node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

void insertMinHeap(MinHeap* heap, Node* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void getLengths(Node* root, int depth, CanonicalCode codes[], int* count) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[*count].ch = root->ch;
        codes[*count].length = depth;
        (*count)++;
        return;
    }
    getLengths(root->left, depth + 1, codes, count);
    getLengths(root->right, depth + 1, codes, count);
}

int compareCanonical(const void* a, const void* b) {
    CanonicalCode* c1 = (CanonicalCode*)a;
    CanonicalCode* c2 = (CanonicalCode*)b;
    if (c1->length != c2->length)
        return c1->length - c2->length;
    return c1->ch - c2->ch;
}

void printBinary(unsigned int val, int len) {
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
    }
}

int main() {
    int n;
    printf("=======================================================\n");
    printf("        HUFFMAN CODING & CANONICAL CODEBOOK            \n");
    printf("=======================================================\n");

    printf("Enter number of unique symbols (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    MinHeap heap = {.size = 0};

    printf("\nEnter symbol and frequency (e.g., 'a 5'):\n");
    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        printf("Symbol %d: ", i + 1);
        scanf(" %c %d", &ch, &freq);
        heap.array[i] = createNode(ch, freq);
    }
    heap.size = n;

    // Build min heap
    for (int i = (heap.size - 2) / 2; i >= 0; --i)
        minHeapify(&heap, i);

    // Build Huffman Tree
    while (heap.size > 1) {
        Node* left = extractMin(&heap);
        Node* right = extractMin(&heap);
        Node* parent = createNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        insertMinHeap(&heap, parent);
    }

    Node* root = heap.array[0];
    CanonicalCode codes[256];
    int count = 0;
    getLengths(root, 0, codes, &count);

    // Sort by code length, then lexicographically
    qsort(codes, count, sizeof(CanonicalCode), compareCanonical);

    // Generate Canonical Codes
    unsigned int current_code = 0;
    int current_len = codes[0].length;
    codes[0].code = current_code;

    for (int i = 1; i < count; i++) {
        current_code++;
        if (codes[i].length > current_len) {
            current_code <<= (codes[i].length - current_len);
            current_len = codes[i].length;
        }
        codes[i].code = current_code;
    }

    printf("\n=======================================================\n");
    printf("            CANONICAL HUFFMAN CODEBOOK                 \n");
    printf("=======================================================\n");
    printf("%-10s %-15s %-15s\n", "Symbol", "Code Length", "Canonical Code");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10c %-15d ", codes[i].ch, codes[i].length);
        printBinary(codes[i].code, codes[i].length);
        printf("\n");
    }
    printf("=======================================================\n");

    return 0;
}