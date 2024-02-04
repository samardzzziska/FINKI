/* Од тастатура се читаат непознат број на позитивни цели броеви (со максимум 5 цифри) се додека не се внесе нешто различно од број. За секој број треба да се најде позицијата (од десно на лево) на првото појавување на најголемата цифра во составот на бројот (цифрата на единици се наоѓа на позиција 0). Потоа, да се испечати статистика за позициите на најдените цифри со максимална вредност во следниот формат:

[позиција]: [вкупно броеви чија максимална цифра се наоѓа на таа позиција]

0: 2

1: 3

2: 1

3: 1

4: 1


за броевите 97654 48654 12345 12343 1263 12443 12643 12777 */
#include <iostream>

using namespace std;

int main () {

    int number;
    int Counter0 = 0, Counter1 = 0, Counter2 = 0, Counter3 = 0, Counter4 = 0;
    int index = 0;

    while (cin >> number) {

        int Counter = 0;
        int MaxCifra = 0;
        int temp = number;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit > MaxCifra) {
                MaxCifra = digit;
                index = Counter;
            }
            Counter++;
            temp /= 10;
        }

        if (index == 0) Counter0++;
        if (index == 1) Counter1++;
        if (index == 2) Counter2++;
        if (index == 3) Counter3++;
        if (index == 4) Counter4++;

    }

    cout << "0: " << Counter0 << endl;
    cout << "1: " << Counter1 << endl;
    cout << "2: " << Counter2 << endl;
    cout << "3: " << Counter3 << endl;
    cout << "4: " << Counter4 << endl;

    return 0;
}
