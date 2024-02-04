/* Read a square matrix of integers from standard input. First the dimension N is entered (2 < N <= 100) and then the elements of the matrix by rows.

Transform the matrix in a way that all the elements ABOVE the main diagonal will be set to the value of the maximal element found above the main diagonal,
 while all the elements BELOW the main diagonal will be set to the value of the minimal element found below the main diagonal. Print out the transformed matrix. */
#include <iostream>

#include <climits>

using namespace std;

int main() {

    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                if (a[i][j] > max) {
                    max = a[i][j];
                }
            } else if (i > j) {
                if (a[i][j] < min) {
                    min = a[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                a[i][j] = a[i][j];
            } else if (i > j) {
                a[i][j] = min;
            } else if (i < j) {
                a[i][j] = max;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

