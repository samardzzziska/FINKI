/* Од стандарден влез се читаат непознат број на хексадецимални цифри се додека не се внесе точка (.).
 * Ваша задача е да го пресметате декадниот збир на внесените хексадецимални цифри. Доколку добиениот декаден збир е делив со 16 се печати Pogodok.
 * Доколку истиот тој збир покрај што е делив со 16 плус завршува на 16 (последните цифри му се 1 и 6), се печати Poln pogodok инаку се печати самиот збир. */
#include <iostream>

using namespace std;

int main () {

    char hexNum;
    int zbir = 0;

    while (cin >> hexNum) {
        if (hexNum == '.') {
            break;
        }
        if (hexNum >= '0' && hexNum <= '9') zbir += hexNum - '0';
        if (hexNum >= 'a' && hexNum <= 'f') zbir += hexNum - 'a' + 10;
        if (hexNum >= 'A' && hexNum <= 'F') zbir += hexNum - 'A' + 10;
    }
    if (zbir % 16 == 0) {
        if ((zbir/10)%10 == 1 && zbir%10 == 6) {
            cout << "Poln pogodok" << endl;
        } else {
            cout << "Pogodok" << endl;
        }
    } else {
        cout << zbir << endl;
    }

    return 0;
}
