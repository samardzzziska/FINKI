/* Sweet number is number that contains only even digits (0, 2, 4, 6, 8). In given range (m and n read from SI) find the smallest "sweet number". If there is no such number, print NSN. */
#include <iostream>

using namespace std;

int main () {

    int m, n, temp;
    cin >> m >> n;

    for (int i = m; i <= n; i++) {
        temp = i;
        bool isBlag = true;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit % 2 != 0) {
                isBlag = false;
                break;
            }
            temp /= 10;
        }
        if (isBlag == true) {
            cout << i << endl;
            return 0;
        }

    }
    cout << "NSN" << endl;

    return 0;
}
