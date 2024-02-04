/* Write a program in which from the standard input you read one positive integer z, and afterwards you read one after another pairs of integers (a, b).
 * Thereby, the loop should end if you read the pair (0, 0). The program should calculate how many times the integer z is equal to the sum of the pairs a and b,
 * as well as the percentage of the pairs (a,b) that give sum equal to z (NOTE: the pair (0,0) is not taken into account when doing calculations!). */
#include <iostream>

using namespace std;

int main () {

    int z;
    cin >> z;
    int par1, par2;
    float Counter1 = 0;
    float Counter2 = 0;

    while (cin >> par1 >> par2) {
        if (par1 == 0 && par2 == 0) {
            break;
        }
        if (par1 + par2 == z) {
            Counter1++;
        }
        Counter2++;
    }

    cout << "You entered " << Counter1 << " pairs of numbers that have a sum equal to " << z << endl;
    cout << "The percentage of pairs with sum " << z << " is " << (Counter1/Counter2)*100 << "%" << endl;

    return 0;
}