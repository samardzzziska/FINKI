/* Од стандарден влез се читаат непознат број на редови додека не се прочита 0.
 * Да се најде најдолгиот ред во кој има барем 2 цифри. Потоа, на стандарден излез да се испечатат знаците
 * од најдолгиот ред кои се наоѓаат помеѓу првата и последната цифра (заедно со тие 2 цифри) во истиот редослед.
 * Доколку има повеќе такви редови се печати последниот. Се претпоставува дека ниту еден ред не е подолг од 100 знаци. */
#include <iostream>
#include <cstring>

using namespace std;

bool contains_digit(char a[]) {
    int count = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (isdigit(a[i])) {
            count++;
        }
    }
    if (count > 2) {
        return true;
    } else {
        return false;
    }
}

int main () {

    char a[101];
    char najdolga[100];
    int max_len = 0;
    while (true) {
        cin.getline(a,100);
        if (a[0] == '0') {
            break;
        }
        if (contains_digit(a)) {
            int len = strlen(a);
            if (len >= max_len) {
                max_len = len;
                strcpy(najdolga,a);
            }
        }
    }
    int start = 0, end = 0;
    for (int i = 0; i < strlen(najdolga); i++) {
        if (isdigit(najdolga[i])) {
            start = i;
            break;
        }
    }
    for (int i = strlen(najdolga)-1; i >= 0; i--) {
        if (isdigit(najdolga[i])) {
            end = i;
            break;
        }
    }
    for (int i = start; i <= end; i++) {
        cout << najdolga[i];
    }

    return 0;
}
