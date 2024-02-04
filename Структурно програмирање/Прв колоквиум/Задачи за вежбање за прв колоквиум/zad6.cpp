/* Да се напише програма во која од стандарден влез прво се внесува еден позитивен цел број z,
 * а потоа последователно се внесуваат парови цели броеви (a, b). Внесувањето на парови цели броеви треба да заврши кога корисникот ќе го внесе парот (0, 0).
 * Треба да се пресмета колку пати z е еднаков на збирот на секој внесен пар броеви a и b, како и колкав процент од вкупниот број внесени парови (a, b) даваат збир z
 * (ЗАБЕЛЕШКА: парот (0, 0) не се зема во предвид при извршувањето на пресметките!). */
#include <iostream>

using namespace std;

int main () {

    int z;
    cin >> z;
    float Counter1 = 0;
    float Counter2 = 0;

    int par1, par2;
    while (cin >> par1 >> par2) {
        if (par1 == 0 && par2 == 0) {
            break;
        }
        if (par1 + par2 == z) {
            Counter1++;
        }
        Counter2++;
    }
    cout << "Vnesovte " << Counter1 << " parovi od broevi chij zbir e " << z << endl;
    cout << "Procentot na parovi so zbir " << z << " e " << (Counter1/Counter2)*100 << "%" << endl;

    return 0;
}
