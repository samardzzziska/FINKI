/* Од тастатура се чита природен број N (N < 400).

Да се напише програма којашто формира квадратна матрица што ги содржи броевите од 1 до N по растечки редослед на следниот начин:
 во првата колона во правец од горе надолу, па продолжува во втората колона од долу нагоре, па продолжува во третата колона од горе надолу итн.
 Да се избере најмалата димензија на матрицата во која ќе ги собере сите броеви до N. Доколку има преостанати празни места, тие да се пополнат со нули. */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main () {

    int b;
    cin >> b;
    int arr[400];
    for (int i = 1, j = 0; i <= b; i++, j++) {
        arr[j] = i;
    }
    int n;
    double square = sqrt(b);
    if (int(square) == square) {
        n = square;
    } else {
        n = square+1;
    }
    int a[n][n], k = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                if (k < b) {
                    a[j][i] = arr[k++];
                } else {
                    a[j][i] = 0;
                }
            }
        } else {
            for (int j = n-1; j >= 0; j--) {
                if (k < b) {
                    a[j][i] = arr[k++];
                } else {
                    a[j][i] = 0;
                }
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