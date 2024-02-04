/* Firstly read the dimension of one matrix (m, n <= 100) from the standard input, and then the elements of the matrix.
 * Generate an array (with at most m x n elements) of the elements of the matrix that will contain the elements of each row that appear exactly once in that row.
 * The order of writing the elements in the array corresponds to the order of the rows and the order of the elements within the row.
 * If the newly generated array has no elements, print N, otherwise, print the elements of the array. */
#include <iostream>

#include <cstring>

#include <climits>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    int a[200][200];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int count, arr[200], len = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count = 0;
            for (int k = 0; k < m; k++) {
                if (a[i][j] == a[i][k]) {
                    count++;
                }
            }
            if (count == 1) {
                arr[len] = a[i][j];
                len++;
            }
        }
    }
    if (arr[0] == 0) {
        cout << "N" << endl;
    } else {
        for (int i = 0; i < len; i++) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}
