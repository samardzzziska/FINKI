/* An integer N is read from SI, followed by an array of N one-digit integers.

Find the numbers A and B that repeat the most times in the array. Then print a rectangle with dimension A x B on the standard output in the following format:

**.....*
**.....*
**.....*
**.....*
**.....*
(A-lines with B-stars, where A is the smaller of the two numbers found).

In the test cases, there are always exactly two numbers that appear the same most times.

Example:

Input:

10

2 5 3 7 5 3 3 6 4 5

(3 appears 3 times, 5 appears 3 times, while the others are less frequent)

Output:

* * * * *

* * * * *

* * * * *
*/
#include <iostream>
#include <cstring>

using namespace std;

int count(int a[], int n, int i, int e, int c) {
    if (i == n) {
        return c;
    }
    if (a[i] == e) {
        return count(a,n,i+1,e,c+1);
    }
    return count(a,n,i+1,e,c);
}

int max_count(int a[], int n, int i, int max, int e) {
    if (i == n) {
        return e;
    }
    int occurs = count(a,n,0,a[i],0);
    if (occurs > max) {
        return max_count(a,n,i+1,occurs,a[i]);
    }
    return max_count(a,n,i+1,max,e);
}

int find_max(int a[], int n, int i, int e, int max) {
    int occurs = count(a,n,0,a[i],0);
    if (occurs == max && a[i] != e) {
        return a[i];
    }
    return find_max(a,n,i+1,e,max);
}

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main () {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int e1 = max_count(a,n,0,0,a[0]);
    int max_o = count(a,n,0,e1,0);
    int e2 = find_max(a,n,0,e1,max_o);
    if (e1 > e2) {
        swap(e1,e2);
    }
    for (int i = 0; i < e1; i++) {
        for (int j = 0; j < e2; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}