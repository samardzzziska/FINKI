/* Write a program that will read unknown number of three integers, and for each triple (a, b, c)
 * will print the number (a or b) that contains the digit c more times on even positions (the positions are counted from right to left, and the first position is 1). */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int contains_c_parni(int number, int c, int count, int digitcounter) {
    if (number == 0) {
        return count;
    }
    int digit = number%10;
    if (digitcounter%2 == 0 && digit == c) {
        return contains_c_parni(number/10,c,count+1,digitcounter+1);
    }
    return contains_c_parni(number/10,c,count,digitcounter+1);
}

int main() {

    int n1, n2, c;
    while (cin >> n1 >> n2 >> c) {
        if (contains_c_parni(n1,c,0,1) >= contains_c_parni(n2,c,0,1)) {
            cout << n1 << endl;
        } else {
            cout << n2 << endl;
        }
    }

    return 0;
}
