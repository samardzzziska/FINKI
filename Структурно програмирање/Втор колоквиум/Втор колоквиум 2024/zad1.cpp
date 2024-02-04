/* Vnesi broj n, niza od zbor i potoa  vnesi n nizi. Za sekoja niza da se ispecati kolku recenici e (pocnuvajki od 0)
 * i kolku pati posledovatelno se pojavuva prvata niza vo sekoja niza
Na pr:
2
2024
Srekna nova 2024!
Srekja i zdravje vo novata 20242024 godina. Vi posakuvame se najdobro!

Output:
0:1
1:2 */
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int posl_pojavuvanja(char a[], char b[], int start, int end) {
    int count = 0;
    int ind;
    for (int i = start; i <= end; i++) {
        ind = 0;
        if (a[i] == b[ind]) {
            while (ind < strlen(b) && a[i] == b[ind]) {
                i++;
                ind++;
            }
            count++;
        }
    }
    return count;
}

int main () {

    int n;
    cin >> n;
    cin.get();
    char b[20];
    cin >> b;
    cin.get();
    char a[101];
    for (int x = 0; x < n; x++) {
        cin.getline(a,100);
        int start = 0;
        int count;
        int res;
        for (int i = 0; i <= strlen(a)+1; i++) {
            if (a[i] == ' ' || a[i] == '\0') {
                count = posl_pojavuvanja(a,b,start,i-1);
                if (count >= 1) {
                    res = count;
                }
                start = i+1;
            }
        }
        cout << x << ": " << res << endl;
    }

    return 0;
}
