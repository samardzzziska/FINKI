/* Од стандарден влез се внесуваат непознат број на реченици претставени преку текстуални низи (стрингови) секоја не подолга од 100 знаци и секоја во нов ред.
 * Програмата треба да го најде стрингот кој содржи најмногу сврзници и да го испечати заедно со бројот на најдените сврзници.
 * За сврзници се сметаат сите зборови составени од една, две или три букви. Зборовите во текстуалната низа се одделени со едно или повеќе прзани места и/или интерпункциски знак.

Броењето на сврзници во дадена текстуална низа треба да се реализира во посебна функција. Решенијата без користење функција ќе бидат оценети со најмногу 40% од поените.

Ако има повеќе реченици со ист максимален број на сврзници, се печати прво најдената.

Објаснување на тест примерот:
Бројот на сврзници по реченици е 2, 3, 4, 2, 4 и 7 соодветно. Најмногу сврзници има по последната реченица па се печати бројот 7 и содржината на таа реченица. */
#include <iostream>

#include <cstring>

using namespace std;

int broisvrznici(char a[]) {
    int len = 0;
    int zborovi[100], count = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (isalpha(a[i])) { //dali e bukva
            count++; //kolku karakteri e
        } else {
            zborovi[len] = count; //stavame vo niza len[0] = 7;
            len++; // sleden clen
            count = 0; //sleden zbor
        }
    }
    //proveri go posledniot zbor
    if (count > 0) {
        zborovi[len] = count;
        len++;
    }
    int svrznik = 0;
    for (int i = 0; i < len; i++) {
        if (zborovi[i] == 1 || zborovi[i] == 2 || zborovi[i] == 3) {
            svrznik++;
        }
    }
    return svrznik;
}

int main()
{
    int najgolem = 0;
    char najgolema[1000];
    while (true) {
        char a[1000];
        cin.getline(a,999);
        if (strlen(a) == 0) {
            break;
        }
        int svrznik = broisvrznici(a);
        if (najgolem < svrznik) {
            najgolem = svrznik;
            strcpy(najgolema,a);
        }
    }
    cout << najgolem << ": " << najgolema << endl;

    return 0;
}

