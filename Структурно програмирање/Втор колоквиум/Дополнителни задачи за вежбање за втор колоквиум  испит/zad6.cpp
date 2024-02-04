/* Од стандарден влез се чита природен број N (N <= 100), како и низа од позитивни цели броеви a[ ] со N елементи.

Да се напише функција int par(a, n) која ќе го врати најмалиот елемент во низата кој се појавува парен број пати во низата. Доколку нема таков елемент, функцијата враќа вредност 0.

Напишете програма што ќе ја повика функцијата par за внесената низа a[ ] и ќе го испечати најмалиот број којшто се појавува парен број пати во низата a[ ]. */
#include <iostream>
#include <cstring>

using namespace std;

int par(int a[], int n) {
    int min = 999999;
    bool rule = false;
    for (int i = 0; i < n; i++) {
        int e = a[i];
        int counter = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                counter++;
            }
        }
        if (e < min) {
            if (counter % 2 == 0) {
                min = e;
                rule = true;
            }
        }
    }
    if (rule) {
        return min;
    } else {
        return 0;
    }
}

int main () {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min = par(a,n);
    if (min == 0) {
        cout << "Nitu eden element ne se pojavuva paren broj pati!" << endl;
    } else {
        cout << "Najmaliot element koj se pojavuva paren broj pati e " << min << endl;
    }

    return 0;
}
