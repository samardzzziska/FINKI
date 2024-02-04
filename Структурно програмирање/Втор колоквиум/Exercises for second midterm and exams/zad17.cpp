/* Read an integer k from SI, followed by lines of characters. Print on SO the read lines transformed in such a way that all the vowels in the line will be repeated k times.  */
#include <iostream>

#include <cstring>

using namespace std;

bool is_vowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    } else {
        return false;
    }
}

int main() {

    int k;
    cin >> k;
    cin.get();
    char c;
    while (cin.get(c)) {
        cout << c;
        if (is_vowel(c)) {
            for (int i = 1; i < k; i++) {
                cout << c;
            }
        }
    }

    return 0;
}

