/* Од стандарден влез се читаат низи од знаци се додека не се прочита знакот #.
 * Да се напише програма во која од за секој прочитан ред ќе се отпечати бројот на цифри во тој ред, знакот :,
 * па самите цифри подредени според ASCII кодот во растечки редослед. Низите од знаци не се подолги од 100 знаци. */
#include <iostream>
#include <cstring>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubblesort(int a[], int n) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < n-1; i++) {
            if (a[i] > a[i+1]) {
                swap(a[i],a[i+1]);
                swapped = true;
            }
        }
    }
}

int main() {

    char a[101];
    int cifri[100];
    while (true) {
        cin.getline(a,100);
        if (a[0] == '#') {
            break;
        }
        int len = 0;
        for (int i = 0; i < strlen(a); i++) {
            if (isdigit(a[i])) {
                cifri[len] = a[i] - '0';
                len++;
            }
        }
        bubblesort(cifri,len);
        cout << len << ":";
        for (int i = 0; i < len; i++) {
            cout << cifri[i];
        }
        cout << endl;
    }

    return 0;
}
