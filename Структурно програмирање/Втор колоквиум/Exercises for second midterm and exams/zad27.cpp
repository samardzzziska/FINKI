/* Read the dimensions M and N (not bigger than 100) and the values (whole numbers) of one matrix A_ {MxN} from the standard input.
 * Print out the index of the first column that has the smallest sum of all of its elements. */
#include <iostream>

#include <cstring>

#include <climits>

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
    int min_sum = INT_MAX, sumkol, index_kol;
    for (int i = 0; i < m; i++) {
        sumkol = 0;
        for (int j = 0; j < n; j++) {
            sumkol += a[j][i];
        }
        if (sumkol < min_sum) {
            min_sum = sumkol;
            index_kol = i;
        }
    }
    cout << index_kol << endl;

    return 0;
}

