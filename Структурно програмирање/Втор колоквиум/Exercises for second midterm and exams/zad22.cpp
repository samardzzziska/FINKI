/* Write a fully recursive function triangle (n) which given the input argument n, prints a triangle from the numbers from 1 to n.
 * Additional functions can be used, but no loops should be used.

Example for n=4.

    1
    12
    123
    1234 */
#include <iostream>

#include <cstring>

using namespace std;

void triangle(int n, int i, int j) {
    if (i == n) { //base case: i go dostignuva vneseniot broj
        return;
    }
    if (j <= i+1) { //koga ni pocnuva vtoriot vgnezden ciklus
        cout << j;
        triangle(n,i,j+1); //go nakacuvame j
    } else { //ako uslovot vekje ne e zadovolen
        cout << endl; //pecatime nov red vo triagolnikot
        triangle(n,i+1,1); //i go nakacuvame, j GO RESETIRAME NA 1
    }
}

int main () {

    int n;
    cin >> n;
    triangle(n,0,1);

    return 0;
}