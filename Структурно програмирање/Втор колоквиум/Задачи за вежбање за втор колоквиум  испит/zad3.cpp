/* Од тастатура во низа се внесуваат N позитивни цели броеви (N <= 100), а потоа се внесува и цел број ind (ind >= 0).

Да се напише функција sum_pos која ја прима низата, бројот ind (кој претставува индекс во низата) и бројот на валидни елементи во низата. Функцијата треба да врати сумата на сите елементи почнувајќи од дадениот индекс ind па се до крајот на низата. Ако индексот ind е поголем од Nфункцијата треба да врати 0.

НАПОМЕНА: Задачата да се реши со помош на покажувачи (без користење на оператор [ ]). */
#include <iostream>
#include <cstring>

using namespace std;

int sum_pos(int *a, int n, int ind) {
    if (ind > n) {
        return 0;
    }
    int suma = 0;
    for (int i = ind; i < n; i++) {
        suma += *(a+i);
    }
    return suma;
}

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ind;
    cin >> ind;
    int sum = sum_pos(a,n,ind);
    cout << sum << endl;

    return 0;
}
