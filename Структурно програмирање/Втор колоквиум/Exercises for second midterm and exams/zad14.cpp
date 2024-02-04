/* Read a square binary matrix from standard input. First the dimension N is entered (1 < N <= 100) and then the elements of the matrix (either 0 or 1) by rows.

Write a program that will calculate the smallest number of necessary changes of the elements in order to transform the matrix to zero diagonal symmetrical matrix.
 Any transition of an element form 0 to 1 or form 1 to 0 is counts as a single change. After the conversion all the elements of the main diagonal should be 0,
 and the matrix should be symmetrical with respect to the main diagonal. Print the minimal number of transitions required. */
#include <iostream>

#include <cstring>

using namespace std;

int main () {

    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int changes = 0; //broime promeni
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && a[i][j] == 1) { //ako sme na glavnata dijagonala i elementot eden, go pravime nula
                a[i][j] = 0;
                changes++;
            }
            if (i < j && i != j) { //pocnuvame od gorniot triagolnik (nad glavnata dijagonala) da gi menuvame elementite
                if (a[i][j] == 0 && a[i][j] != a[j][i]) { //bidejki e kvadratna matricata, i so j se simetricni
                    a[j][i] = 0; //ako elementot vo gorniot triagolnik e 0, vo dolniot stanuva isto 0
                    changes++;
                } else if (a[i][j] == 1 && a[i][j] != a[j][i]) { //ako e eden, stanuva eden
                    a[j][i] = 1;
                    changes++;
                }
            }
        }
    }
    cout << changes << endl;

    return 0;
}
