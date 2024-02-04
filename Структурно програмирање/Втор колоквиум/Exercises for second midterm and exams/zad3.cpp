/* Let A = {a1, a2, .. a_n} is an array of integers. The size of the array n and the elements of the array are read from SI.
 * Write a program that will transform the array so each element of the original array is replaced with the number of appearance
 * of the least significant digit (the right most) in the number itself. Print the result array on the standard output.

Compute the count of given digit in a number with separate recursive function.

Example:

Input:
5
1 11 1121 111222112 22222
Output:
1 2 3 4 5 */
#include <iostream>

using namespace std;

int pojavuvanja_edinici (int number, int edinici) {
    int counter = 0;
    if (number == 0) {
        return 0;
    }
    int digit = number % 10;
    if (digit == edinici) {
        counter++;
    }
    return counter + pojavuvanja_edinici(number/10,edinici);
}

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int edinici;
    for (int i = 0; i < n; i++) {
        edinici = a[i] % 10;
        a[i] = pojavuvanja_edinici(a[i],edinici);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
