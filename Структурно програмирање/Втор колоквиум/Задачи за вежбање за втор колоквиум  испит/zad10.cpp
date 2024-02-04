/* Од стандарден влез прво се читаат два знака z1 и z2 , а потоа се читаат редови со низи од знаци се’ додека не се прочита знакот # (секој од редовите не е подолг од 80 знаци).

Да се напише програма со која на стандарден излез ќе се испечатат поднизите од секој ред составени од знаците што се наоѓаат меѓу z1 и z2 (без нив). Секоја подниза се печати во нов ред.

Се смета дека секој ред од датотеката точно еднаш ги содржи знаците z1 и z2, знакот z1 секогаш се наоѓа пред знакот z2, а меѓу z1 и z2 секогаш има барем еден знак. */
#include <iostream>

#include <cstring>

using namespace std;

int main() {

    char z1, z2;
    cin >> z1 >> z2;
    cin.get();
    char a[81];
    char pom[80];
    while (true) {
        cin.getline(a,80);
        if (a[0] == '#') {
            break;
        }
        int start = 0, end = 0;
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] == z1) {
                start = i+1;
                break;
            }
        }
        for (int i = strlen(a); i >= 0; i--) {
            if (a[i] == z2) {
                end = i-1;
                break;
            }
        }
        strncpy(pom,a+start,(end-start)+1);
        pom[(end-start)+1] = '\0';
        cout << pom << endl;
    }

    return 0;
}
