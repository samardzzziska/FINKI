/* Vnesi broj n. Potoa da se pecati niza
n, n-3, n-6, n-9... n-9, n-6, n-3
Koga ke dojde do negativen broj da ne se odzima do 3 tuku da se soberi so 3 vo sekoj nareden clen */
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool flag = true;

void pecati(int n, int temp, int x) {
    cout << n << " ";
    if (n > 0 && flag) {
        return pecati(n-x,temp,x);
    }
    if (n == 0 && flag) {
        cout << n-x << " ";
        flag = false;
        return pecati(n+x,temp,x);
    }
    if (n == temp && !flag) {
        return;
    }
    if (n > 0 && !flag) {
        return pecati(n+x,temp,x);
    }
}

int main () {

    int n;
    cin >> n;
    pecati(n,n,3);

    return 0;
}
