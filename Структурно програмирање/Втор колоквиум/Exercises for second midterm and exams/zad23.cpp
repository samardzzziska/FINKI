/* N positive integers are entered from the standard input and stored in an array a (N <100)**.
 * Also, a single-digit integer **k** is entered. Write a function that will find the maximum of the abbreviated numbers of the elements in the array **a**
 * and provide a call to that function in the main () function. A given element of the array is abbreviated as follows: all digits smaller than or equal to **k are deleted from the number.

For example: If k = 3 and a[0] = 12345, then abbreviated a[0] becomes 45, if a[1] = 458763, a[1] becomes 45876, and a[2] = 112 is shortened to a[2] = 0.
 The maximum abbreviated number is 45876. */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int abbreviate(int n, int k) {
    if (n == 0) {
        return 0;
    }
    int digit = n%10;
    if (digit > k) {
        return digit + abbreviate(n/10,k)*10;
    }
    return abbreviate(n/10,k);
}

void abbreviate_elements(int a[], int n, int i, int k) {
    if (n == i) {
        return;
    }
    a[i] = abbreviate(a[i],k);
    return abbreviate_elements(a,n,i+1,k);
}

int max_abbreviated(int a[], int n, int i, int max) {
    if (i == n) {
        return max;
    }
    if (a[i] > max) {
        max = a[i];
        return max_abbreviated(a,n,i+1,max);
    }
    return max_abbreviated(a,n,i+1,max);
}

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    abbreviate_elements(a,n,0,k);
    cout << max_abbreviated(a,n,0,0) << endl;

    return 0;
}