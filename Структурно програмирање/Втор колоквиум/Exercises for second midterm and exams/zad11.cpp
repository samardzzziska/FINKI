/* Write a program that will read a string (not longer than 100 characters) containing letters and digits.
 * The program should print on the standard output the letters that are between the first and the second digit, left-to-right,
 * including the bordering digits themselves. If there is only one digit in the string, the program should print all the letters till the end of the string.
 * If there is no digits in the string the program should print out the message "No digits". */
#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char a[101];
    cin.getline(a,100);
    int start = 0, end = 0;
    char pom[100];
    for (int i = 0; i < strlen(a); i++) {
        if (isdigit(a[i])) {
            start = i;
            break;
        }
    }
    for (int i = start+1; i < strlen(a); i++) {
        if (isdigit(a[i])) {
            end = i;
            break;
        }
    }
    if (start == 0 && end == 0) {
        cout << "No digits" << endl;
    } else if (end == 0) {
        for (int i = start; i < strlen(a); i++) {
            cout << a[i];
        }
    } else {
        int j = 0;
        for (int i = start; i <= end; i++) {
            pom[j++] = a[i];
        }
        pom[j] = '\0';
        cout << pom << endl;
    }


    return 0;
}

