/* Write a program that reads matrix with dimensions MxN (max. 100x100). At the beginning the dimensions are read,
 * then the elements of the matrix with values 0 or 1. Your program should count and print on SO the number of rows and columns
 * with at least 3 consecutive appearance of elements with value 1. */
#include <iostream>

#include <cstring>

using namespace std;

int main () {

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int redici = 0, edinici;
    for (int i = 0; i < n; i++) {
        edinici = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                edinici++;
                if (edinici >= 3) {
                    redici++;
                    break;
                }
            } else {
                edinici = 0;
            }
        }
    }
    int koloni = 0;
    for (int i = 0; i < m; i++) {
        edinici = 0;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == 1) {
                edinici++;
                if (edinici >= 3) {
                    koloni++;
                    break;
                }
            } else {
                edinici = 0;
            }
        }
    }
    int pojavi = koloni + redici;
    cout << pojavi << endl;

    return 0;
}


