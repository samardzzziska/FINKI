/* Write a program that will read from SI array of natural numbers (not more than 100). Print all the elements of the array that represent strong numbers (each in new line).
 * One number is strong if the sum of factorials of each of his digits is equal to the number itself. Example, number 145 is strong because:

145 = 1! + 4! + 5!

If a number is strong should be checked in a separate function, and for computing factorial a separate recursive function should be implemented and used. */
#include <iostream>
#include <cstring>

using namespace std;

int fact(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n*fact(n-1);
}

int sum_fact_digit(int number, int sum) {
    if (number == 0) {
        return sum;
    }
    int digit = number%10;
    return fact(digit) + sum_fact_digit(number/10,sum);
}

bool is_strong(int number) {
    if (sum_fact_digit(number,0) == number) {
        return true;
    } else {
        return false;
    }
}

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Strong numbers: " << endl;
    for (int i = 0; i < n; i++) {
        if (is_strong(a[i])) {
            cout << a[i] << endl;
        }
    }

    return 0;
}
