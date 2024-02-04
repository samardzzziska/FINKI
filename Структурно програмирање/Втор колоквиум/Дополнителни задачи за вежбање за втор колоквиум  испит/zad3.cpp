/* Од стандарден влез се чита цел број N (N<100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци, а секоја од нив не е поголема од 50 знаци.

Да се напише програма што ќе ги отпечати на екран сите низи од знаци во кои се содржи поднизата А1c  најмалку 2 пати
 (пр. A1c01АA1c92, 12A1cwwA1cxy, аA1cwA1cA1ccA1cxab) според редоследот како што се прочитани од влезот.
 При печатење на зборовите, сите алфабетски знаци треба да се испечатат со мали букви. */
#include <iostream>
#include <cstring>

using namespace std;

int sodrzi_a1c(char a[]) {
    int count = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == 'a' && a[i+1] == '1' && a[i+2] == 'c') {
            count++;
        }
    }
    return count;
}

void smali(char a[]) {
    for (int i = 0; i < strlen(a); i++) {
        a[i] = tolower(a[i]);
    }
}

int main () {

    int n;
    cin >> n;
    char a[80];
    for (int i = 0; i < n; i++) {
        cin >> a;
        smali(a);
        if (sodrzi_a1c(a) >= 2) {
            cout << a << endl;
        }
    }

    return 0;
}
