/* Да се напише програма во која се вчитува матрица од цели броеви A со N редици и N * 2 колони (N не е поголемо од 50).
 * Програмата треба да ја трансформира вчитаната матрица во нова матрица B, така што сите елементи десно од N-тата колона ќе ги префрли под N-тата редица,
 * односно од матрица со димензија N редици и 2 * N колони ќе се добие матрица со 2 * N редици x N колони. */
#include <iostream>
#include <cstring>

using namespace std;

int main() {

    int n;
    cin >> n;
    int a[n][n*2], b[n*2][n], copy[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n*2; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = a[i][j];
        }
    }
    for (int i = 0, k = 0; i < n; i++, k++) {
        for (int j = n, l = 0; j < 2*n; j++, l++) {
            copy[k][l] = a[i][j];
        }
    }
    for (int i = n, k = 0; i < 2*n; i++, k++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = copy[k][j];
        }
    }
    for (int i = 0; i < 2*n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}