#include <stdio.h>

/*
    Balance Scale

    Compares the total weight of one group of coins against another.

    Returns:
        -1 -> Left side is lighter
         0 -> Both sides are equal
         1 -> Right side is lighter
*/
int weigh(const float coins[],
          int leftStart, int leftEnd,
          int rightStart, int rightEnd) {

    float leftWeight = 0.0f;
    float rightWeight = 0.0f;

    for (int i = leftStart; i <= leftEnd; i++)
        leftWeight += coins[i];

    for (int i = rightStart; i <= rightEnd; i++)
        rightWeight += coins[i];

    float difference = leftWeight - rightWeight;

    if (difference < -0.0001f)
        return -1;
    if (difference > 0.0001f)
        return 1;
    return 0;
}


/*
    Finds the defective (lighter) coin among candidates in [low, high].

    good    -> index of a coin already known to be normal (used only
               when we need to verify a single remaining candidate).
    certain -> 1 if we already KNOW a defective coin exists somewhere
               in [low, high] (because a previous weighing showed this
               side was lighter). 0 if we're not sure yet (this range
               is just "whatever's left after a balanced weighing").

    Why this matters: if certain == 1 and only one coin is left, that
    coin MUST be the defective one — no need to weigh it again. That's
    what saves us a weighing compared to always double-checking.

    Returns index of the defective coin, or -1 if none exists.
*/
int findDefective(const float coins[],
                   int low, int high,
                   int good, int certain) {

    int cnt = high - low + 1;

    if (cnt == 0)
        return -1;

    /*
        Base case: exactly one candidate left.
    */
    if (cnt == 1) {

        if (certain)
            return low;   // already proven defective, no weighing needed

        // not certain -> verify against the known-good coin
        if (weigh(coins, low, low, good, good) == -1)
            return low;

        return -1;
    }

    /*
        Split the candidates into three groups, as equal as possible.
        Example for cnt = 8: sizes come out 3, 3, 2.
    */
    int third     = cnt / 3;
    int remainder = cnt % 3;

    int g1 = third + (remainder > 0);
    int g2 = third + (remainder > 1);
    int g3 = cnt - g1 - g2;

    int aStart = low,           aEnd = aStart + g1 - 1;
    int bStart = aEnd + 1,      bEnd = bStart + g2 - 1;
    int cStart = bEnd + 1,      cEnd = high;

    /*
        Weigh group A against group B.
    */
    int result = weigh(coins, aStart, aEnd, bStart, bEnd);

    if (result == -1) {
        // A is lighter -> defect is definitely in A, B is normal
        return findDefective(coins, aStart, aEnd, bStart, 1);
    }

    if (result == 1) {
        // B is lighter -> defect is definitely in B, A is normal
        return findDefective(coins, bStart, bEnd, aStart, 1);
    }

    /*
        A and B balanced -> both are normal. If a defect exists at
        all, it has to be in C. If C is empty, there's nothing left
        to check, so there's no defect.
    */
    if (g3 == 0)
        return -1;

    return findDefective(coins, cStart, cEnd, aStart, 0);
}


int main() {

    int n;

    printf("Enter number of coins: ");

    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Please enter at least 2 coins.\n");
        return 1;
    }

    float coins[n];

    printf("\nEnter the weights of %d coins:\n", n);

    for (int i = 0; i < n; i++) {
        printf("Coin %d: ", i + 1);
        if (scanf("%f", &coins[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    /*
        Top-level call: no known-good coin exists yet, and we don't
        know if a defect even exists. Since n >= 2, this call will
        always go through the 3-way split branch first, so the unused
        "good" and "certain" values here never actually get read.
    */
    int defective = findDefective(coins, 0, n - 1, -1, 0);

    if (defective != -1) {
        printf("\n----------------------------------\n");
        printf("Defective coin found!\n");
        printf("Coin number : %d\n", defective + 1);
        printf("Weight      : %.2f\n", coins[defective]);
    } else {
        printf("\n----------------------------------\n");
        printf("No defective coin found.\n");
        printf("All coins have identical weight.\n");
         
    }

    return 0;
}