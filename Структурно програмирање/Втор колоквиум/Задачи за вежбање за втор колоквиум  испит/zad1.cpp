/* Се внесуваат низи од значи од стандарден влез. Да се избројат и испечатат сите последнователни појавувања на соседни самогласки во речениците. Појавата на големи и мали букви да се игнорира. Пронајдените парови самогласки да се испечатат на екран, секој во нов ред со мали букви. Потоа во нов ред се печати бројот на појавувања на паровите самогласки. Читањето завршува кога ќе се прочита знакот #.

Пример:

IO is short for Input Output
medioio medIo song
#
Излез:

io
ou
io
oi
io
io
6 */
#include <iostream>
#include <cstring>

using namespace std;

bool is_samoglaska(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    } else {
        return false;
    }
}

int main() {

    char a[100];
    int count = 0;
    while (cin>>a) {
        if (a[0] == '#') {
            break;
        }
        for (int i = 0; i < strlen(a); i++) {
            a[i] = tolower(a[i]);
        }
        for (int i = 0; i < strlen(a); i++) {
            if (is_samoglaska(a[i]) && is_samoglaska(a[i+1])) {
                cout << a[i] << a[i+1] << endl;
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}