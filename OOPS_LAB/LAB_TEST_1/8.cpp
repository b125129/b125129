#include <iostream>
using namespace std;

void score_increase_10(int *ptr, int n) {
    for (int i = 0; i < n; i++) {
        *ptr += 10;
        ptr++;
    }
}

int main() {
    int n;
    cout << "Enter number of players: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter initial scores for " << n << " players:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }

    cout << "\nInitial Scores of players: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    score_increase_10(arr, n);

    cout << "Scores after adding 10: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}