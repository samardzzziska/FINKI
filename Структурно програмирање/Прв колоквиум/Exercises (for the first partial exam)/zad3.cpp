/* Using the characters + and - form a square image with "width" n (n > 2) that represent square of the chars -, enclosed by a square of chars + (view examples).
 * For given n, print the appropriate image.

Attention: do not print additional characters as empty spaces, or unnecessary new line... The image ends with new line char. Do not use any matrix or arrays because n is not limited. */
#include <iostream>

using namespace std;

int main () {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == n) {
            for (int j = 1; j <= n; j++) {
                if (j == 1 || j == n) {
                    cout << "+";
                } else {
                    cout << "+";
                }
            }
            cout << endl;
        } else {
            for (int k = 1; k <= n; k++) {
                if (k == 1 || k == n) {
                    cout << "+";
                } else {
                    cout << "-";
                }
            }
            cout << endl;
        }
    }

    return 0;
}