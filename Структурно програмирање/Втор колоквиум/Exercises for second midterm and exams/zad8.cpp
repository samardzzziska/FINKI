/* Write a recursive function that will find the number of odd numbers of an array of integers.
 * The function accepts as an arguments the array for which the number of odd numbers is required and the total number of elements in the array.
 * The function is given with the following prototype:

int Odd (int a [], int n);

Also write the main () function to test the Odd function. */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int Odd (int a [], int n);

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << Odd(a,n) << endl;

    return 0;
}

int Odd (int a[], int n) {
    if (n == 0) {
        return 0;
    }
    if (abs(a[n-1]) % 2 == 1) {
        return 1 + Odd(a,n-1);
    }
    return Odd(a,n-1);
}