/* Read from SI lines. Find and print the row, where the ratio of digits/letters is largest. If there are more than one such rows print the last.
 * No row is longer than 100 characters, and if in a row there are no letters, that row is ignored. */
#include <iostream>

#include <cstring>

using namespace std;

int main() {

    char a[101];
    char najdolga[101];
    najdolga[0] = '\0'; //prazna niza za najdolgata niza
    float max_ratio = 0.00;
    while (true) {
        cin.getline(a,100);
        if (a[0] == 0) { //break ako se stisne enter
            break;
        }
        int letter_counter = 0, digit_counter = 0; //gi broime bukvite i cifrite
        for (int i = 0; i < strlen(a); i++) {
            if (isalpha(a[i])) {
                letter_counter++;
            }
        }
        if (letter_counter == 0) { //ako nema nitu edna bukva, preskokni ja
            continue;
        }
        for (int i = 0; i < strlen(a); i++) {
            if (isdigit(a[i])) {
                digit_counter++;
            }
        }
        if (digit_counter == 0) { //ako nema nitu edna cifra, preskokni ja
            continue;
        }
        float ratio = float (digit_counter)/letter_counter; //prosek na bukvi i cifri
        if (ratio >= max_ratio) { //naogjanje na najgolem prosek
            max_ratio = ratio;
            strcpy(najdolga,a); //kopiranje na taa niza vo najdolga
        }
    }
    cout << najdolga << endl;

    return 0;
}

