/* Од тастатура се внесува цел број M, а потоа M низи од цели броеви. За секоја низа прво се внесува бројот на елементи во низата N (N<=100), а потоа и елементите на низата.

Секоја од внесените низи треба да се трансформира според следново правило:

Ако првиот елемент од низата е позитивен број, тоа значи сите елементи од низата (вклучувајќи го и првиот) да се поместат за онолку места во десно, колку што е вредноста на елементот,
 празнините што ќе настанат во низата да се пополнат со елементи со вредност нула.

Ако првиот елемент од низата е негативен број, тоа значи сите елементи од низата (вклучувајќи го и првиот) да се поместат за онолку места во лево, колку што е вредноста на елементот,
 празнините што ќе настанат во низата да се пополнат со елементи со вредност нула.

При поместување на елементите, бројот на елементите во низата останува непроменет.

На крајот да се испечатат трансформираните низи како и тоа колку од влезните низи останале празни, односно по трансформацијата имаат само елементи со вредност нула.

Трансформацијата на низите да се реализира во посебна функција. Решенијата без користење функција ќе бидат оценети со најмногу 40% од поените. */
#include <iostream>

using namespace std;

void pomesti_desno(int a[], int n, int e) {
    if (e > n) { //ako elementot e pogolem od brojot na elementi, site elementi se 0
        for (int i = 0; i < n; i++) {
            a[i] = 0;
        }
    } else {
        for (int i = 0; i < e; i++) { //pomestuvame za e mesta vo desno
            for (int j = n - 1; j > 0; j--) {
                a[j] = a[j-1];
            }
        }
        for (int i = 0; i < e; i++) { //preostanatite elementi gi pravime 0
            a[i] = 0;
        }
    }
}

void pomesti_levo(int a[], int n, int e) {
    if (e > n) {
        for (int i = 0; i < n; i++) {
            a[i] = 0;
        }
    } else {
        for (int i = 0; i < e; i++) { //pomestuvame za e mesta vo levo
            for (int j = 0; j < n; j++) {
                a[j] = a[j+1];
            }
        }
        for (int i = (n-e)+e; i >= n-e; i--) { //broime od nazad do razlikata od n i e plus e
            a[i] = 0; //tie elementi se zamenuvaat so 0
        }
    }
}

int main() {

    int m;
    cin >> m;
    int counter_prazni_nizi = 0;
    for (int k = 0; k < m; k++) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int e = a[0]; //go smestuvame prviot element vo nizata vo e
        if (e > 0) {
            pomesti_desno(a,n,e);
        } else {
            e = abs(e); //apsolutna vrednost na e za da znaeme za kolku mesta da pomestuvame
            pomesti_levo(a,n,e);
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " "; //ja pecatime transformiranata niza
        }
        cout << endl;
        int prazni_elementi = 0; //gi broime praznite elementi vo nizata
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                prazni_elementi++; //ako elementot e prazen, counter++
            }
        }
        if (prazni_elementi == n) { //ako praznite elementi se ednakvi so brojot elementi, nizata e prazna
            counter_prazni_nizi++; //najdena e prazna niza
        }
    }
    cout << counter_prazni_nizi << endl;



    return 0;
}

