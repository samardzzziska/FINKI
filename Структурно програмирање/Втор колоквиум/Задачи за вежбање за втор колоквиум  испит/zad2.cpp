/* На стандарден влез се дадени повеќе редови со броеви така што секој ред започнува со еден цел број (N>=1) што означува колку броеви следуваат по него во истиот ред.
 * Да се напише програма која на СИ за секој ред ќе го испечати бројот со најголема најзначајна цифра. Читањето на броеви завршува кога ќе се прочита бројот 0. */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main () {

    char a[101];
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        int max = 0;
        char najgolem[101];
        for (int i = 0; i < n; i++) {
            cin >> a;
            if ((a[0] - '0') > max) {
                max = a[0] - '0';
                strcpy(najgolem,a);
            }
        }
        cout << najgolem << endl;
    }

    return 0;
}
