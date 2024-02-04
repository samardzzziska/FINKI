/* Read a an array of N integers from standard input (first read the number N than the elements). Than call a recursive function on the array that will change on the following way:

a0=aN−1=max(a0,aN−1)
a1=aN−2=max(a1,aN−2)
...

where max is a function that returns the maximum of the two numbers. The function should return the number of switched elements. Then print that number and the changed array. */
#include <iostream>

using namespace std;

int max(int a, int b) {
    int najgolem = a;
    if (najgolem < b) {
        najgolem = b;
    }
    return najgolem;
}

int max_rec(int a[], int n, int i) {
    if (i == n) {
        return 0;
    } else {
        a[i] = max(a[i],a[(n-1)-i]);
        return max_rec(a,n,i+1);
    }
}

int max_counter(int a[], int b[], int n, int i, int counter) {
    if (i == n/2) {
        return counter;
    }
    if (a[i] != b[i]) {
        return max_counter(a,b,n,i+1,counter+1);
    }
    return max_counter(a,b,n,i+1,counter);
}

int main() {

    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    max_rec(a,n,0);
    int counter = 0;
    counter = max_counter(a,b,n,0,counter);
    cout << counter << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
