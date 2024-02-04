/* Од тастатура се читаат 2 позитивни цели броеви. Доколку се внесе барем еден негативен број или 0 треба да се печати „Invalid input“.

Треба да се определи дали помалиот број “е парен еквивалент” од поголемиот број.

Еден број “е парен еквивалент” на друг број, ако и само ако неговите цифри се наоѓаат на парните позиции од другиот број, во истиот редослед. Соодветно да се испечатат пораки „PAREN“ и „NE“.

Позициите треба да се сметаат оддесно-налево (најмалку значајната цифра е на позиција 1) */
#include <iostream>

using namespace std;

int main () {

    int broj1, broj2;
    cin >> broj1 >> broj2;
    int Pogolem = 0;
    bool Paren = true;

    if (broj2 > broj1) {
        Pogolem = broj2;
        broj2 = broj1;
        broj1 = Pogolem;
    }

    if (broj1 <= 0 || broj2 <= 0) {
        cout << "Invalid input" << endl;
    } else {
        for (; broj1 > 0; broj1 /= 100) {
            if ((broj1/10)%10 != broj2%10) {
                Paren = false;
                cout << "NE" << endl;
                break;
            }
            broj2 /= 10;
        }
        if (Paren == true) {
            cout << "PAREN" << endl;
        }
    }

    return 0;
}


