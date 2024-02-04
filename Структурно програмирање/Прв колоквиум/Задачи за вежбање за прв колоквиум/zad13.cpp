/* Од тастатура се читаат непознат број позитивни цели броеви се додека не се внесе нешто различно од број. За секој број треба да се пресмета збирот на цифрата со максимална вредност од претходно внесениот број  и сумата на цифрите на тековниот број (за првиот внесен број се пресметува само сумата на неговите цифри). За секој внесен број резултатот треба да се испечати во следниот формат:

[број]: [сумата на цифрите на бројот + максималната цифра од претходниот број]

342: 9   //3+4+2

345: 16 //3+4+5+4

123: 11 //1+2+3+5

456: 18 //4+5+6+3 */
#include <iostream>

using namespace std;

int main () {

    int number;
    int PreviousHighest = 0;

    while (cin >> number) {

        cout << number << ": ";

        int temp = number;
        int SumaCifri = 0;
        while (temp > 0) {
            int digit = temp % 10;
            SumaCifri += digit;
            temp /= 10;
        }

        SumaCifri += PreviousHighest;

        int temp2 = number;
        int MaxDigit = 0;
        while (temp2 > 0) {
            int digit2 = temp2 % 10;
            if (digit2 > MaxDigit) {
                MaxDigit = digit2;
            }
            temp2 /= 10;
        }

        PreviousHighest = MaxDigit;

        cout << SumaCifri << endl;

    }

    return 0;
}
