/* Da se vnesi m i n za redici i koloni, a potoa i elementite na matricata.
Se crta shablon kako bukvata Z koja pocnuva vo opsek (2x2) i zbirot na broevite sto gi opfakja. Potoa da se pecati zbirot na shablonot vo opsek (3x3) itn */
#include <iostream>

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
    int suma;
    if (n > m) {
        for (int k = 2; k <= m; k++) {
            int i = 0;
            suma = 0;
            int j;
            for (j = 0; j < k; j++) {
                suma += a[i][j];
            }
            j-=2;
            for (i = 1; j > 0; i++, j--) {
                suma += a[i][j];
            }
            for (j = 0; j <= i; j++) {
                suma += a[i][j];
            }
            cout << suma << endl;
        }
    } else {
        for (int k = 2; k <= n; k++) {
            int i = 0;
            suma = 0;
            int j;
            for (j = 0; j < k; j++) {
                suma += a[i][j];
            }
            j-=2;
            for (i = 1; j > 0; i++, j--) {
                suma += a[i][j];
            }
            for (j = 0; j <= i; j++) {
                suma += a[i][j];
            }
            cout << suma << endl;
        }
    }

    return 0;
}