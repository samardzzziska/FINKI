/* Words (no longer than 20 letters and each in a new line) are read from SI. Write a program that will print the word that has the biggest number of different letters.
 * Words that have less than four letters are not taken into account during the check. Do not make a difference between upper and lower case letters.
 * If there are more words that meet the criteria, the last one is printed. */
#include <iostream>

#include <cstring>

using namespace std;

int repeating_letters(char a[]) {
    char letters[26];
    for (int i = 0; i < 26; i++) {
        letters[i] = 'a' + i;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (letters[i] == tolower(a[j])) {
                letters[i] = 'X';
                i=0;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (letters[i] == 'X') {
            count++;
        }
    }
    return count;
}

int main () {

    char a[20];
    char najdolga[20];
    int max_count = 0;
    while (cin >> a) {
        if (strlen(a) < 4) {
            continue;
        }
        int count = repeating_letters(a);
        if (count >= max_count) {
            max_count = count;
            strcpy(najdolga,a);
        }
    }
    cout << najdolga << endl;

    return 0;
}
