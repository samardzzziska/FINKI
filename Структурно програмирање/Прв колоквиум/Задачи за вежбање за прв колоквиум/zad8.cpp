/* Од стандарден влез се внесуваат два цели броја N и Х.

Да се најде најблискот број помал од N коj е тотално различен од бројот Х.

Еден број е тотално различен од друг ако и само ако во него не се појавува ниту една од цифрите на другиот број.

Задачата да се реши без употреба на низи и матрици. */
#include <iostream>

using namespace std;

int main () {

    int N, X;
    cin >> N >> X;
    N--;

    for (; N > 0; N--) {
        int tempn = N;
        bool ista = false;
        while (tempn > 0) {
            int digitn = tempn % 10;
            int tempx = X;
            while (tempx > 0) {
                int digitx = tempx % 10;
                if (digitx == digitn) {
                    ista = true;
                    break;
                }
                tempx /= 10;
            }
            tempn /= 10;
        }
        if (ista == false) {
            break;
        }
    }
    cout << N << endl;

    return 0;
}
