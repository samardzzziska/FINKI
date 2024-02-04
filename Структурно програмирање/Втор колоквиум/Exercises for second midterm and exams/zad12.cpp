/* An array of integers is to be read from SI. First the number N (N<=100) is entered followed by N integers.
 * Write a program that will transform the array in the following way: starting at the beginning of the array,
 * for each element that is equal to the next element in the array, double the value of the first one and overwrite the second one with 0.
 * After that, rearrange the array so that all the zeroes will be moved at the end of the array, keeping the order of the other elements.
 * Print all the elements of the array on the SO in a single line, separated by space.

Write separate functions for transforming the array and for reordering the elements. */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void transform(int a[], int n, int i) {
    if (i == n) {
        return;
    }
    if (a[i] == a[i + 1]) {
        a[i] *= 2;
        a[i + 1] = 0;
        return transform(a, n, i + 1);
    }
    return transform(a, n, i + 1);
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void shift(int a[], int n, int i) {
    if (i == n) {
        return;
    }
    if (a[i] == 0) {
        for (int j = i+1; j < n; j++) {
            if (a[j] != 0) {
                swap(a[i],a[j]);
                break;
            }
        }
        return shift(a,n,i+1);
    }
    return shift(a,n,i+1);
}

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    transform(a,n,0);
    shift(a,n,0);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}