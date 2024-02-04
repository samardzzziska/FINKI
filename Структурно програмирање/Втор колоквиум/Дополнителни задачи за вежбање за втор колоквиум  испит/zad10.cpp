/* Од стандарден влез се читаат елементите на една матрица (A), составена од цели броеви. Прво се читаат бројот на редици N и бројот на колони M на матрицата (N, M < 120), а потоа и самите елементи на матрицата.

Да се испечати колку индексни броеви има во секоја колона поединечно.

Индексен број е број чија вредност е идентична со вредноста што се добива со спојување на индексот од редицата и колоната на елементот.

Помош:

Индексен елемент: вредноста на елементот Aij е иста со ij како број

- ако i=10, j=31, елементот Aij треба да има вредност 1031 за да биде индексен број */
#include <iostream>

#include <cmath>

using namespace std;

int brojcifri(int number) {
    int temp = number;
    int counter = 0;
    if (temp == 0) {
        return 1;
    }
    while (temp > 0) {
        counter++;
        temp /= 10;
    }
    return counter;
}

int main() {

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) { //pocnuvame da citame od kolonite
        int indeksni = 0; //resetirame za sekoja kolona
        for (int j = 0; j < n; j++) { //pa potoa od redicite
            int stotki = j;
            int desetki = i;
            int indeksen = stotki * pow(10, brojcifri(desetki)) + desetki;
            if (indeksen == a[j][i]) {
                indeksni++;
            }
        }
        cout << indeksni << endl;
    }


    return 0;
}

