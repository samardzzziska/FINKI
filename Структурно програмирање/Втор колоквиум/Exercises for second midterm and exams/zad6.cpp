/* Read from standard input the dimensions of a matrix (m < 100 and n < 100) which contains only zeros and ones. Then read the elements of the matrix.

Read the coordinates of one element of the matrix. If the element of the read position is 0, then it should become 1 and:

all zeros above that element to the first element with value 1 or to the start of the column,
all zeros bellow that element to the first element with value 1 or to the end of the column,
all zeros left from that element to the first element with value 1 or to the begin of the row and
all zeros right from that element to the first element with value 1 or to the end of the row.
If the element of the given position is 1 than the matrix stays unchanged. */
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
    int ind_r, ind_c;
    cin >> ind_r >> ind_c;
    if (a[ind_r][ind_c] == 0) {
        a[ind_r][ind_c] = 1;
        for (int j = ind_c+1; j < m; j++) { //levo
            if (a[ind_r][j] == 0) {
                a[ind_r][j] = 1;
            }
            if (a[ind_r][j+1] == 1) {
                if (a[ind_r][j] == 0) {
                    a[ind_r][j] = 1;
                }
                break;
            }
        }
        for (int j = ind_c-1; j >= 0; j--) { //desno
            if (a[ind_r][j] == 0) {
                a[ind_r][j] = 1;
            }
            if (a[ind_r][j-1] == 1) {
                if (a[ind_r][j] == 0) {
                    a[ind_r][j] = 1;
                }
                break;
            }
        }
        for (int i = ind_r-1; i >= 0; i--) { //gore
            if (a[i][ind_c] == 0) {
                a[i][ind_c] = 1;
            }
            if (a[i-1][ind_c] == 1) {
                if (a[i][ind_c] == 0) {
                    a[i][ind_c] = 1;
                }
                break;
            }
        }
        for (int i = ind_r+1; i < n; i++) { //dole
            if (a[i][ind_c] == 0) {
                a[i][ind_c] = 1;
            }
            if (a[i+1][ind_c] == 1) {
                if (a[i][ind_c] == 0) {
                    a[i][ind_c] = 1;
                }
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
