#include <stdio.h>
#include <string.h>

int main() {
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int red[n], blue[n], yellow[n];
    int r = 0, b = 0, y = 0;

    int number;
    char colour[10];

    printf("Enter number and colour (input must be sorted by number):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &number, colour);

        if (strcmp(colour, "red") == 0) {
            red[r++] = number;
        }
        else if (strcmp(colour, "blue") == 0) {
            blue[b++] = number;
        }
        else if (strcmp(colour, "yellow") == 0) {
            yellow[y++] = number;
        }
        else {
            printf("Invalid colour: %s\n", colour);
            return 1;
        }
    }

    printf("\nSorted by colour:\n");

    for (int i = 0; i < r; i++)
        printf("(%d, red) ", red[i]);

    for (int i = 0; i < b; i++)
        printf("(%d, blue) ", blue[i]);

    for (int i = 0; i < y; i++)
        printf("(%d, yellow) ", yellow[i]);

    printf("\n");

    return 0;
}