/* For one integer b we say that is a parity complement of other integer a if and only if
 * in the number b all the even digits of the number a are replaced with the corresponding (odd) digit increased by 1,
 * and all odd digits of the number a are replaced with the corresponding (odd) digit decreased by 1 .

Example. Number b = 4013698 is a parity complement of a = 5102789.

Read from SI unknown number of integers (not more than 100), until something that is not a number is entered.

Your task is to print the smallest 5 of the parity complements of all numbers, from the smallest to the largest.

Notice: If less then 5 numbers are entered, then print all the entered numbers.

Finding the parity complement of a number should be implemented in a separate recursive function parcom(int a).

Example.

For numbers: 9641, 69403, 103007, 6, 11, 181, 20486 you should find their parity complements (those are: 8750, 78512, 12116, 7, 0, 90 and 31597, respectively),
 and print the 5 smallest of them in this order: 0 7 90 8750 12116.

Using global variables is FORBIDDEN. */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int parcom(int a) {
    if (a == 0) {
        return 0;
    }
    int digit = a%10;
    if (digit % 2 == 0) {
        return (digit+1) + parcom(a/10)*10;
    } else {
        return (digit-1) + parcom(a/10)*10;
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubblesort(int a[], int n) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < n-1; i++) {
            if (a[i] > a[i+1]) {
                swap(a[i],a[i+1]);
                swapped = true;
            }
        }
    }
}

int main() {

    int a[100], n = 0;
    while (cin >> a[n]) {
        n++;
    }
    for (int i = 0; i < n; i++) {
        a[i] = parcom(a[i]);
    }
    bubblesort(a,n);
    if (n < 5) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    } else {
        for (int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }
    }

    return 0;
}