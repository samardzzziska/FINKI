/* Четиринасочник претставува матрица во која се испишани зборови хоризонотално и вертикално, одлево-надесно и оддесно-налево.
 * Притоа секој елемент од матрицата претставува буква од англиската азбука.

пример скриени зборови: HAIR, OLE (прецртани), FISH, TOE (подвлечени)

T H A I R E
E S N K N E
M I M J O L
M F S P S T
I F G E L O
X U T Y O E
Од стандарден влез се чита квадратна матрица од ред n (3 <= n <= 50), составена од знаци. Прво се чита бројот n - бројот на редици (колони) на матрицата,
 а потоа и самите елементи на матрицата (види пример).
По читањето на матрицата, од стандарден влез се внесува збор составен од максимум 10 букви.

Ваша задача е да определите дали тој збор се наоѓа во четиринасочникот (хоризонтално или вертикално, одлево-надесно или оддесно-налево).
 Потребно е да се испечати локацијата (ред, колона) на првата и последната буква од зборот. Доколку зборот повеќепати се наоѓа во четеринасочникот,
 треба да се испечати првото појавување, гледано елемент по елемент како што се чита матрицата.

Доколку не се пронајде зборот, тогаш се печати Not Found. */
#include <iostream>

#include <cstring>

using namespace std;

int main () {

    int n;
    cin >> n;
    char a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    char zbor[10];
    cin >> zbor;
    int sr = -1, sc = -1, er = -1, ec = -1;
    bool found = false;
    int k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == zbor[0]) {
                sr = i;
                sc = j;
                for (k = 1; k <= strlen(zbor); k++) {
                    if (zbor[k] != a[i+k][j]) {
                        found = false;
                        break;
                    } else if ((i+k) >= n) {
                        found = false;
                        break;
                    }
                    er = i+k;
                    ec = j;
                }
                if (k == strlen(zbor)) {
                    found = true;
                    break;
                }
                for (k = 1; k <= strlen(zbor); k++) {
                    if (zbor[k] != a[i-k][j]) {
                        found = false;
                        break;
                    } else if ((i-k) < 0) {
                        found = false;
                        break;
                    }
                    er = i-k;
                    ec = j;
                }
                if (k == strlen(zbor)) {
                    found = true;
                    break;
                }
                for (k = 1; k <= strlen(zbor); k++) {
                    if (zbor[k] != a[i][j+k]) {
                        found = false;
                        break;
                    } else if ((j+k) >= n) {
                        found = false;
                        break;
                    }
                    er = i;
                    ec = j+k;
                }
                if (k == strlen(zbor)) {
                    found = true;
                    break;
                }
                for (k = 1; k <= strlen(zbor); k++) {
                    if (zbor[k] != a[i][j-k]) {
                        found = false;
                        break;
                    } else if ((i-k) < 0) {
                        found = false;
                        break;
                    }
                    er = i;
                    ec = j-k;
                }
                if (k == strlen(zbor)) {
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            break;
        }
    }
    if (found) {
        cout << sr << ", " << sc << " -> " << er << ", " << ec << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}