/* Write a program that will read lines from SI and it will print on the SO the lines preceded by the ratio of upper/lower case letters in the rows.

Also, at the end print the number of the line with the largest ration of upper/lower case letters. */
#include <iostream>

#include <cstring>

#include <iomanip>

using namespace std;

int main() {

    char a[101];
    int line_count = -1; //na -1 za da broime od 0
    double max_ratio = 0.00;
    int longest = 0;
    while (true) {
        line_count++; //broime za sekoja vnesena niza
        cin.getline(a,100);
        if (a[0] == 0) {
            break;
        }
        int uppercase = 0, lowercase = 0; //kolku golemi i mali bukvi ima
        for (int i = 0; i < strlen(a); i++) {
            if (isupper(a[i])) {
                uppercase++; //broime golemi
            }
        }
        for (int i = 0; i < strlen(a); i++) {
            if (islower(a[i])) {
                lowercase++; //broime mali
            }
        }
        double ratio = double(uppercase)/lowercase; //presmetuvame prosek na golemi i mali
        if (ratio > max_ratio) {
            max_ratio = ratio;
            longest = line_count; //naogjame koja ima najgolem prosek
        }
        cout << fixed << setprecision(2) << ratio << " " << a << endl; //so fixed imame fiksen broj na decimalni mesta
    }
    cout << longest << endl;

    return 0;
}

