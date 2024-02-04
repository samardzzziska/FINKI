/* Read words from SI. No words are longer than 20 characters. Write a program that on the SO will print all the words from the file that are unsigned hexadecimal numbers
 * (one word per line in uppercase digits). At the end also print the total number of such numbers found in the file.

The hexadecimal numbers can contain both upper and lowercase letters a-f and A-F, but when printing them convert them all to uppercase. The possible leading zeroes are also
 treated as part of the number and should also be printed.
Since the numbers are unsigned whole numbers no sign or decimal point is considered as part of the number. */
#include <iostream>

#include <cstring>

using namespace std;

bool hexadecimal_char(char c) {
    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F') {
        return true;
    } else {
        return false;
    }
}

bool hexadecimal_digit(char c) {
    if (c  >= '0' && c <= '9') {
        return true;
    } else {
        return false;
    }
}

bool ima_specijalen_znak(char a[]) {
    for (int i = 0; i < strlen(a); i++) {
        if (!isalnum(a[i])) {
            return true;
        }
    }
    return false;
}

bool sodrzi_samo_bukvi(char a[]) {
    for (int i = 0; i < strlen(a); i++) {
        if (isalpha(a[i])) {
            return true;
        }
    }
    return false;
}

int main () {

    char a[100];
    int count = 0;
    while (cin>>a) {
        cin.get();
        if (ima_specijalen_znak(a)) {
            continue;
        }
        bool hex = true;
        for (int i = 0; i < strlen(a); i++) {
            if (isalpha(a[i])) {
                if (!hexadecimal_char(a[i])) {
                    hex = false;
                    break;
                }
            } else {
                if (!hexadecimal_digit(a[i])) {
                    hex = false;
                    break;
                }
            }
        }
        if (hex) {
            if (sodrzi_samo_bukvi(a)) {
                for (int i = 0; i < strlen(a); i++) {
                    if (islower(a[i])) {
                        a[i] = toupper(a[i]);
                    }
                }
                for (int i = 0; i < strlen(a); i++) {
                    cout << a[i];
                }
                cout << endl;
                count++;
            } else {
                cout << a << endl;
                count++;
            }
        }
    }
    cout << "Total: " << count << endl;

    return 0;
}