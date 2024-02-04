/* Од стандарден влез се чита цел број N (N<=100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци (без знаци за празно место),
 * а секоја од нив не е подолга од 80 знаци.

Да се напише програма со која што на стандарден излез ќе се отпечати најдолгата низа, којашто е палиндром (се чита исто од од лево на десно и од десно на лево)
и што содржи барем еден специјален знак. Ако нема такви низи, се печати "Nema!".
Ако има две или повеќе низи што го задоволуваат овој услов, се печати првата низа којашто го задоволува условот. */
#include <iostream>
#include <cstring>

using namespace std;

bool palindrom(char a[]) {
    int start = 0, end = strlen(a)-1;
    while (start <= end) {
        if (a[start] != a[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool sodrzi_specijalen_znak(char a[]) {
    for (int i = 0; i < strlen(a); i++) {
        if (!isalnum(a[i])) {
            return true;
        }
    }
    return false;
}

int main () {

    int n;
    cin >> n;
    char a[80];
    char najdolga[80];
    najdolga[0] = '\0';
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (sodrzi_specijalen_znak(a)) {
            if (palindrom(a)) {
                if (strlen(a) > strlen(najdolga)) {
                    strcpy(najdolga,a);
                }
            }
        }
    }
    if (najdolga[0] == '\0') {
        cout << "Nema!" << endl;
    } else {
        cout << najdolga << endl;
    }

    return 0;
}
