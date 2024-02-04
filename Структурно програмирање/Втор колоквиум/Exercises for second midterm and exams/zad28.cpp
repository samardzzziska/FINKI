/* Write a program that reads lines no longer than 80 characters from SI. Each line consists of digits and letters.

The program should print on SO each line transformed in such way that the letters will be concatenated next to each other,
 followed by the sum of all numbers that appear in the row. The numbers can be with more than one digit! If there are no numbers, print 0 at the end of the line. */
#include <iostream>

#include <cstring>

using namespace std;

int main () {

    char a[81];
    while (true) {
        cin.getline(a,80);
        if (cin.eof()) {
            break;
        }
        int number = 0, numbers[100], len = 0;
        bool convert = false;
        for (int i = 0; i < strlen(a); i++) {
            if (isdigit(a[i])) {
                convert = true;
                number = number * 10 + (a[i] - '0');
            } else if (convert) {
                numbers[len] = number;
                len++;
                number = 0;
                convert = false;
            }
        }
        if (convert) {
            numbers[len] = number;
            len++;
        }
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += numbers[i];
        }
        char pom[81];
        pom[0] = '\0';
        int letters = 0;
        for (int i = 0; i < strlen(a); i++) {
            if (isalpha(a[i])) {
                pom[letters] = a[i];
                letters++;
            }
        }
        pom[letters] = '\0';
        cout << pom << sum << endl;
    }

    return 0;
}