#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    // Allocate memory for rows (pointer to pointers)
    int** matrix = new int*[m];

    // Allocate memory for columns in each row
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }

    // Input elements
    cout << "Enter elements of " << m << "x" << n << " matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Display matrix
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Deallocate memory for columns first
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    
    // Deallocate row pointer array
    delete[] matrix;
    matrix = nullptr;

    return 0;
}