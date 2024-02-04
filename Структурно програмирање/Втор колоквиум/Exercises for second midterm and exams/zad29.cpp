/* Write a program that will read from SI words (each in a separate row) no longer than 30 letters. Find all the words  that define a palindrome only with the vowels they contain
 * (after making the opposite word of the given one, the vowels have not changed their indexes within the word). Print these words on a standard output.
 * The appearance of uppercase and lowercase letters should be ignored. */
#include <iostream>

#include <cstring>

using namespace std;

bool issamoglaska(char a) {
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U') { //proveruvame dali karakterot e samoglaska
        return true;
    } else {
        return false;
    }
}

int main () {

    char a[31];
    while (true) {
        cin.getline(a,30);
        if (a[0] == 0) {
            break;
        }
        int n = strlen(a);
        if (n % 2 == 1) { //ako dolzinata na stringot e neparna treba +1 za da go proverime sredniot element
            bool palindrom_samoglaski = true;
            for (int i = 0; i < (n/2)+1; i++) {
                if (issamoglaska(a[i])) { //naogjame prvo pojavuvanje na samoglaska
                    if (tolower(a[i]) != tolower(a[(n-1)-i])) { //ako karakterot od krajot od stringot ne e ist, ne e palindrom
                        palindrom_samoglaski = false;
                        break;
                    }
                }
            }
            if (palindrom_samoglaski) { //ako site samoglaski se na isti pozicii, stringot e palindrom so samoglaski i go pecatime
                cout << a << endl;
            }
        } else {
            bool palindrom_samoglaski = true;
            for (int i = 0; i < n/2; i++) { //go pravime istoto samo sto odime do polovinata na stringot bez +1 za da go fatime sredniot element
                if (issamoglaska(a[i])) {
                    if (tolower(a[i]) != tolower(a[(n-1)-i])) {
                        palindrom_samoglaski = false;
                        break;
                    }
                }
            }
            if (palindrom_samoglaski) {
                cout << a << endl;
            }
        }
    }

    return 0;
}