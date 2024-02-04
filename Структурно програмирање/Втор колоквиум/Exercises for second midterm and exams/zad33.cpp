/* Z-diagonal of given square matrix is composed of the elements of the first row, the elements of the supportive diagonal, and the elements of the last row
 * (marked with blue color on the example).

From SI read the dimensions of square matrix (integer N, N > 2, N<100), and the elements of the matrix (real numbers). Store the elements of the Z-diagonal in a array,
 starting from the first row, continuing with the supportive diagonal, and finishing with the last row (the last element of the first row is the same element with the first element
 of the supportive diagonal, and the last element of the supportive diagonal is the same as the first element of the last row, and these elements should be stored only once).
 The resulted array should be printed on the SO. Then print the original matrix, but with the elements of Z-diagonal in reverse order. */
#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    float a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    float z[100];
    int len = 0; //dolzinata na nizata ja stavame na 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                z[len] = a[i][j]; //gi dodavame elementite od prvata redica
                len++; //ja zgolemuvame dolzinata
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i+j) == (n-1) && i != 0 && i != (n-1)) { //gi dodavame elementite od sporednata dijagonala bez krajnite elementi od prvata i poslednata redica
                z[len] = a[i][j];
                len++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == (n-1)) { //gi dodavame elementite od poslednata redica
                z[len] = a[i][j];
                len++;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        cout << z[i] << " "; //ja pecatime nizata dobiena od dijagonalata z
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        a[0][i] = z[len-1]; //gi dodavame poslednite elementi na nizata na prvata redica od matricata
        len--;
    }
    len = len-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i+j) == (n-1) && i != 0 && j != (n-1) && i != (n-1) && j != 0) { //gi dodavame elementite na sporednata dijagonala
                a[i][j] = z[len];
                len--;
            }
        }
    }
    len = 0;
    for (int i = n-1; i >= 0; i--) {
        a[n-1][i] = z[len]; //gi dodavame elementite na poslednata redica
        len++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
