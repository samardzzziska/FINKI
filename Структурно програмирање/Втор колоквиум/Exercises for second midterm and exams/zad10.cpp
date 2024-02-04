/* Write a program where a matrix A read from SI (maximum value of dimensions of the matrix is 100) is transformed to a new matrix B.
 * Each element of the new matrix B is sum of positive neighbors of the corresponding element of the matrix A. Print the new matrix B on the standard output. */
#include <iostream>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i+1 <= n-1 && a[i+1][j] > 0) {
                b[i][j] += a[i+1][j];
            }
            if (i-1 >= 0 && a[i-1][j] > 0) {
                b[i][j] += a[i-1][j];
            }
            if (j-1 >= 0 && a[i][j-1] > 0) {
                b[i][j] += a[i][j-1];
            }
            if (j+1 <= m-1 && a[i][j+1] > 0) {
                b[i][j] += a[i][j+1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

