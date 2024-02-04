/* Благ број е број што е составен само од парни цифри (0, 2, 4, 6, 8).
 * Во зададен опсег (почетокот m и крајот на опегот n се цели броеви чија вредност се внесува од тастатура),
 * да се најде и испечати најмалиот „благ број“. Ако не постои таков број, да се испечати NE. */
#include <iostream>

using namespace std;

int main () {

    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; i++) {
        int temp = i;
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
    cout << "NE" << endl;

    return 0;
}
