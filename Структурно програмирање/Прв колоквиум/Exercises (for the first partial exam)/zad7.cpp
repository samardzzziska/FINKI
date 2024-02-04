/* Read from SI one integer n. From the integers smaller than n, find the one with maximum sum of divisors. Do not count the number itself in the sum of divisors. */
#include <iostream>

using namespace std;

int main () {

    int n;
    cin >> n;
    int temp = 0;
    int max = 0;

    for (int i = n - 1; i > 0; i--) {
        int BrojDeliteli = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                BrojDeliteli += j;
            }
        }
        if (temp < BrojDeliteli) {
            max = i;
            temp = BrojDeliteli;
        }
    }
    cout << max << endl;

    return 0;
}
