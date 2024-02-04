/* From SI read N strings not longer than 80 chars. At the beginning of the program read two integers:

N - number of strings you are going to read
X - shifting size.
Each of the read strings should be transformed in such a way that lowercase and uppercase letters (a-z, A-Z)
are replaced with the same letter shifted X places afterwards in the alphabet (a-z). If you overflow the range of alphabet, continue cyclic from the beginning of the alphabet.
Transformed string should be printed on SO.

Transformation of a string should be implemented in a separate recursive function.

Example:

Welcome -> transformed with shift 5 -> Bjqhtrj */
#include <iostream>

#include <cstring>

using namespace std;

void pomestuvanje_x_rek(char a[], int x, int i) {
    if (i >= strlen(a)) { //ako i e pogolemo ili ednakvo na dolzinata na stringot, kraj
        return;
    } else {
        if (isalpha(a[i])) {
            if (islower(a[i])) { //proverka dali sme na mala ili golema bukva
                if (a[i] + x > 'z') { //ako clenot plus pomestuvanjeto iskaca od granicite na abc
                    int mesta = 'z' - a[i]; //za kolku mesta e oddalecen clenot od z?
                    a[i] = 'a' + x - mesta - 1; //clenot stanuva 'a' + pomestuvanje - kolku e oddalenec - 1 (ne se broi samiot element)
                } else {
                    a[i] = a[i] + x; //ako ne iskaca od granicite, pomestuvanjeto se pravi najnormalno
                }
            } else {
                if (a[i] + x > 'Z') { //istoto samo so golemi bukvi
                    int mesta = 'Z' - a[i];
                    a[i] = 'A' + x - mesta - 1;
                } else {
                    a[i] = a[i] + x;
                }
            }
        }
    }
    return pomestuvanje_x_rek(a,x,i+1); //i+1 za sledna iteracija
}

int main() {

    int n, x;
    cin >> n >> x;
    cin.get();
    char a[81];
    if (x > 26) { //ako x e pogolemo od 26, go presmetuvame negoviot ostatok so 26 bidejki ciklicno ke se vrati od pocetok
        x %= 26;
    }
    for (int i = 0; i < n; i++) {
        cin.getline(a,80);
        pomestuvanje_x_rek(a,x,0);
        cout << a << endl;
    }

    return 0;
}