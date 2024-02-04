/* Од тастатура се внесуваат димензиите на една матрица (m, n <= 100), а потоа и елементите од матрицата.
 * Да се генерира низа (со најмногу m) така што секој елемент од низата се добива со наоѓање на елементот во секоја редица
 * од матрицата што е најоддалечен од аритметичката средина во рамки на таа редица. Ако постојат повеќе елементи што се најоддалечени
 * од аритметичката средина, тогаш се зема предвид првиот. Редоследот на запишување на елементите во низата одговара на редоследот на редиците. */
#include <iostream>
#include <cstring>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    int a[n][m], b[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    float suma;
    float arit;
    for (int i = 0; i < n; i++) {
        suma = 0, arit = 0.00;
        float naj_o = -1;
        float element;
        for (int j = 0; j < m; j++) {
            suma += a[i][j];
        }
        arit = suma/m;
        for (int j = 0; j < m; j++) {
            element = arit - a[i][j];
            if (element < 0) {
                element *= -1;
            }
            if (element > naj_o) {
                naj_o = element;
                b[i] = a[i][j];
            }
        }

    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}
