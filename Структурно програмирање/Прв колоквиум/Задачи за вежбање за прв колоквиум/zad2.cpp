/* Eден природен e „интересен“ ако неговиот обратен број е делив со неговиот број на цифри.
 * Обратен број е бројот составен од истите цифри, но во обратен редослед (на пример, 653 е обратен број на бројот 356).
 * Од тастатура се внесува природен број n ( n > 9). Да се најде и отпечати најголемиот природен број помал од n кој што е „интересен“.
 * Ако внесениот број не е валиден, да се отпечати соодветна порака (Brojot ne e validen). */
#include <iostream>

using namespace std;

int main () {

    int n;
    cin >> n;
    int max = 0;

    if (n < 9) {
        cout << "Brojot ne e validen" << endl;
    } else {
        for (int i = n - 1; i > 0; i--) {
            int temp = i;
            int Obraten = 0;
            int BrojCifri = 0;
            while (temp > 0) {
                int digit = temp % 10;
                Obraten = (Obraten * 10) + digit;
                BrojCifri++;
                temp /= 10;
            }
            if (Obraten % BrojCifri == 0) {
                if (i > max) {
                    max = i;
                }
            }
        }
        cout << max << endl;
    }




    return 0;
}