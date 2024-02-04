/* Vnesi broj n, niza od zbor i potoa  vnesi n nizi. Za sekoja niza da se ispecati na kolku mesta ima posledovatelno pojavuvanje na samoglaski
Na pr:
2
Sreeeeekna nova 2024!
Srekjaaaaa i zdraaaaavje vo noooovata 2024 godina. Vi posakuvame se najdobro!

Output:
0:0
1:1
2:0
3:1 */
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool is_vowel (char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    } else {
        return false;
    }
}

int repeating_vowels(char a[], int start, int end) {
    int counter = 0;
    for (int i = start; i <= end; i++) {
        if (is_vowel(a[i]) && is_vowel(a[i+1])) {
            counter = 1;
            while (is_vowel(a[i])) {
                counter++;
                i++;
            }
        }
        if (counter > 2) {
            return counter;
        }
    }
    return counter;
}

int main () {

    int n;
    cin >> n;
    cin.get();
    int samoglaski[100];
    int k = 0;
    char a[101];
    for (int x = 0; x < n; x++) {
        cin.getline(a,100);
        int start = 0;
        int mesta = 0;
        for (int i = 0; i <= strlen(a); i++) {
            if (a[i] == ' ' || a[i] == '\0') {
                if (repeating_vowels(a,start,i-1) > 1) {
                    mesta++;
                }
                start = i+1;
            }
        }
        samoglaski[k] = mesta;
        k++;
    }
    int max = 0;
    for (int i = 0; i < k; i++) {
        if (samoglaski[i] > max) {
            max = samoglaski[i];
        }
    }
    int count_rec;
    for (int i = 0; i <= max; i++) {
        count_rec = 0;
        for (int j = 0; j < k; j++) {
            if (samoglaski[j] == i) {
                count_rec++;
            }
        }
        cout << i << ": " << count_rec << endl;
    }

    return 0;
}