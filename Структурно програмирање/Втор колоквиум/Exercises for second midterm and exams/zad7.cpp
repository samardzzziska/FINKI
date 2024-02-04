/* The dimensions of one matrix (m,n <= 100), and then the elements of the matrix are entered from the keyboard.
 * Make a transformation of the matrix so that the middle element in each column is replaced by the difference (by absolute value) of the sum of the elements in the first half
 * of the column and the sum of the elements in the second half of the column. If the matrix has even number of rows, the value of the middle two elements should be changed.
 * The middle element(s) are included when calculating the sum (in the case of an odd number of rows, the middle element is included when calculating both of the sums (upper and lower sum)!).
 * Print the transformed matrix on the standard output. */
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
    //cout << "sum1: ";
    int sum_1_a[100], sum_2_a[100], differences[100];
    if (n % 2 == 0) {
        for (int i = 0; i < m; i++) {
            int sum_kol_1 = 0;
            for (int j = 0; j < n/2; j++) {
                sum_kol_1 += a[j][i];
            }
            sum_1_a[i] = sum_kol_1;
            //cout << sum_1_a[i] << " ";
        }
        //cout << endl;
        //cout << "sum2: ";
        for (int i = 0; i < m; i++) {
            int sum_kol_2 = 0;
            for (int j = n/2; j <= n-1; j++) {
                sum_kol_2 += a[j][i];
            }
            sum_2_a[i] = sum_kol_2;
            //cout << sum_2_a[i] << " ";
        }
        //cout << endl;
        //cout << "differences: ";
        for (int i = 0; i < m; i++) {
            differences[i] = abs(sum_2_a[i] - sum_1_a[i]);
            //cout << differences[i] << " ";
        }
        //cout << endl;
    } else {
        for (int i = 0; i < m; i++) {
            int sum_kol_1 = 0;
            for (int j = 0; j <= n/2; j++) {
                sum_kol_1 += a[j][i];
            }
            sum_1_a[i] = sum_kol_1;
            //cout << sum_1_a[i] << " ";
        }
        //cout << endl;
        //cout << "sum2: ";
        for (int i = 0; i < m; i++) {
            int sum_kol_2 = 0;
            for (int j = n/2; j <= n-1; j++) {
                sum_kol_2 += a[j][i];
            }
            sum_2_a[i] = sum_kol_2;
            //cout << sum_2_a[i] << " ";
        }
        //cout << endl;
        //cout << "differences: ";
        for (int i = 0; i < m; i++) {
            differences[i] = abs(sum_2_a[i] - sum_1_a[i]);
            //cout << differences[i] << " ";
        }
        //cout << endl;
    }
    if (m == n && (m % 2 == 0 && n % 2 == 0)) {
        for (int i = 0; i < m; i++) {
            a[m/2][i] = differences[i];
            a[(m/2)-1][i] = differences[i];
        }
    } else if (n % 2 == 0 && m % 2 == 1) {
        for (int i = 0; i < m; i++) {
            a[m/2][i] = differences[i];
            a[(m/2)+1][i] = differences[i];
        }
    } else if (m == n && (m % 2 == 1 && n % 2 == 1)) {
        for (int i = 0; i < m; i++) {
            a[m/2][i] = differences[i];
        }
    } else if (n % 2 == 1 && m % 2 == 0) {
        for (int i = 0; i < m; i++) {
            a[m/2][i] = differences[i];
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

