/* N positive integers are entered from the standard input and are stored in an array (N <100). All elements that meet the next criteria should be presented
 * on the standard output in the same order that they have appeared on the standard input. The criteria is following: the most important digit (the digit on the first place)
 * is odd and the least important digit is even. If, no such number was entered, you should print out "No such elements!" message.

The implementation of checking the criteria should be performed in a separate function (recursive function for additional 5 points). */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int lastdigit(int n) {
    int digit = n%10;
    return digit;
}

int firstdigit(int n) {
    if (n <= 9) {
        return n;
    }
    return firstdigit(n/10);
}

bool criteria(int n) {
    if (firstdigit(n)%2==1 && lastdigit(n)%2==0) {
        return true;
    } else {
        return false;
    }
}

void printarray(int a[], int n, int i, bool flag) {
    if (i == n) {
        if (!flag) {
            cout << "No such elements!" << endl;
        }
        return;
    }
    if (criteria(a[i])) {
        cout << a[i] << endl;
        return printarray(a,n,i+1,true);
    }
    return printarray(a,n,i+1,flag);
}

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    printarray(a,n,0,false);

    return 0;
}