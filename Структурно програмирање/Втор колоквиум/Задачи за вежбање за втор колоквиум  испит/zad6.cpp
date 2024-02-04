/* Да се напише програма која вчитува матрица со димензии MxN (макс. 100x100). На почетокот се внесуваат димензиите на матрицата,
 * а потоа и елементите на матрицата кои се само вредностите 1 и 0.
 * Програмата треба да изброи и отпечати на СИ во колку од редиците и колоните има барем 3 последователни елементи со вредност 1. */
#include <iostream>
#include <cstring>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int edinici, redici = 0;
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
    int pojavuvanja = redici + koloni;
    cout << pojavuvanja << endl;

    return 0;
}
