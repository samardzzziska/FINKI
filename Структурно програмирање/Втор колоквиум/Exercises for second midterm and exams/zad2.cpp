/* Write a program that will print the contents read from SI coded. The coding is done letter by letter, so that each letter (only letters, not digits, dots, ...)
 * is replaced with the letter 3 places after in the alphabet. In case of the letters at the end of the alphabet, the counting continues cyclic from the beginning of the alphabet.
 * In the final coded text all letters are lowercase. Example letter a is coded to d, H is coded to k, p is coded to s, x is coded to a, etc. */
#include <iostream>
#include <cstring>

using namespace std;

void make_lower(char a[], int i) {
    if (i == strlen(a)) {
        return;
    }
    a[i] = tolower(a[i]);
    return make_lower(a,i+1);
}

void transform(char a[], int i) {
    if (i == strlen(a)) {
        return;
    }
    if (isalpha(a[i])) {
        if ((a[i] + 3) > 'z') {
            a[i] = 'a' + ((3-('z'-a[i])))-1;
        } else {
            a[i] = a[i] + 3;
        }
    }
    return transform(a,i+1);
}

int main () {

    char a[101];
    while (true) {
        cin.getline(a,100);
        if (a[0] == 0) {
            break;
        }
        make_lower(a,0);
        transform(a,0);
        cout << a << endl;
    }

    return 0;
}
