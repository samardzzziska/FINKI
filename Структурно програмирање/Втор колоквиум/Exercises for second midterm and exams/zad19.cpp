/* From SI are read dimension and elements of square matrix (MAX 100x100) of integers.

Create a new matrix where each element of the main diagonal will be replaced with the sum of all elements from the same row right from the element and
 elements from the same column over the element.

Also replace each element of the antidiagonal with the sum of all elements from the same row before the element and elements from the same column below the element.

The blue red elements are part of the main diagonal, the blue elements are part of antidiagonal, and the element in purple is part of both diagonals.

If there is no such elements, the element is 0. If some element is on both diagonals, both sums are summed. */
#include <iostream>
#include <cstring>

using namespace std;

int main () {

    int n;
    cin >> n;
    int a[n][n], b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                int ind_r = i;
                int ind_k = j;
                int suma = 0;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            if (x == ind_r && y > ind_k) {
                                suma += a[x][y];
                            } else if (y == ind_k && x < ind_k) {
                                suma += a[x][y];
                            }
                        }
                    }
                }
                b[i][j] = suma;
                //cout << "suma1c: " << suma << endl;
                if (i == j && (i+j) == (n-1)) {
                    b[i][j] = 0;
                    b[i][j] += suma;
                    //cout << "suma vnatre1c: " << suma << endl;
                }
            }
        }
    }
    //cout << b[1][1] << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i+j) == (n-1)) {
                int ind_r = i;
                int ind_k = j;
                int suma = 0;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            if (x == ind_r && y < ind_k) {
                                suma += a[x][y];
                            } else if (x > ind_r && y == ind_k) {
                                suma += a[x][y];
                            }
                        }
                    }
                }
                if ((i+j) == (n-1) && i != j) {
                    b[i][j] = suma;
                } else if (i == j && (i+j) == (n-1)) {
                    b[i][j] += suma;
                }
                /*cout << "suma2c: " << suma << endl;
                if (i == j && (i+j) == (n-1)) {
                    b[i][j] += suma;
                    cout << "bij: " << b[i][j] << endl;
                    cout << "suma vnatre2c: " << suma << endl;
                }*/
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}