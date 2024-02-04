/* Да се напише рекурзивна функција за наоѓање на максималната цифра од даден цел број.

Од стандарден влез се внесуваат непознат број цели броеви се додека не се внесе нешто што не е број. За секој од нив да се испечати максималната цифра во посебен ред.

Забелешка: Решението со рекурзивна функција носи 100% од поените, а со нерекурзивна функција 70% од поените.

Забелешка: ЗАБРАНЕТО е користење на глобални променливи. */
#include <iostream>
#include <cstring>

using namespace std;

int max_digit_rek(int number, int max_digit) {
    int digit = number%10;
    if (number == 0) {
        return max_digit;
    }
    if (digit > max_digit) {
        max_digit = digit;
    }
    return max_digit_rek(number/10,max_digit);
}

int main() {

    int number;
    while (cin >> number) {
        int max_cifra = max_digit_rek(number,0);
        cout << max_cifra << endl;
    }

    return 0;
}
