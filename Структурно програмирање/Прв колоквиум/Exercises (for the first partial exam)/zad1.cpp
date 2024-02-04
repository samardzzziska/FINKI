/* From SI read characters until you read the char !. In these characters are hidden integers (smaller than 100).
 * Write a program that will read all characters and print the sum of all integers hidden in the text. */
#include <iostream>

using namespace std;

int main () {

    char znak;
    int broj = 0;
    int zbir = 0;

    while (cin >> noskipws >> znak) {
        if (znak >= '0' && znak <= '9') {
            broj = (broj * 10) + (znak - '0');
        } else {
            zbir += broj;
            broj = 0;
        }
        if (znak == '!') {
            break;
        }
    }
    cout << zbir << endl;

    return 0;
}