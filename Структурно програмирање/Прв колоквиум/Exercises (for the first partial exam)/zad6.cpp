/* One number is interesting if his flipped number is divisible by the number of digits it contains. The flipped number is composed from the same digits,
 * but in opposite order (ex. 653 is flipped of the number 356). Read from SI one integer n ( n > 9). Find and print the largest integer small than n that is "interesting".
 * If the read number is not valid print a message "The number is invalid". */
#include <iostream>

using namespace std;

int main () {

    int n;
    cin >> n;
    int max = 0;

    if (n < 9) {
        cout << "The number is invalid" << endl;
    } else {
        for (int i = n - 1; i > 0; i--) {
            int Reversed = 0;
            int Digits = 0;
            int temp = i;
            while (temp > 0) {
                int digit = temp % 10;
                Reversed = (Reversed * 10) + digit;
                Digits++;
                temp /= 10;
            }
            if (Reversed % Digits == 0) {
                if (i > max) {
                    max = i;
                }
            }
        }
        cout << max << endl;
    }

    return 0;
}