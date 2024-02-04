/* Од стандарден влез се чита еден природен број n. Меѓу природните броеви помали од n, да се најде оној чиј што збир на делителите е најголем.
 * Во пресметувањето на збирот на делителите на даден број, да не се зема предвид самиот број. */
#include <iostream>

using namespace std;

int main () {

    int n;
    cin >> n;
    int temp = 0;
    int max = 0;

    for (int i = n - 1; i > 0; i--) {
        int BrojDeliteli = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                BrojDeliteli += j;
            }
        }
        if (temp < BrojDeliteli) {
            max = i;
            temp = BrojDeliteli;
        }
    }
    cout << max << endl;


    return 0;
}