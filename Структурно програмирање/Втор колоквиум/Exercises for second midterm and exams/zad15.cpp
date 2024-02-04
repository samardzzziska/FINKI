/* From SI read lines of text, none of which is longer than 80 characters. Write e program that will transform the input and print it out on the standard output.
 * The output should contain only letters (all other characters are discarded), and each word should be printed in a separate line. */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {

    char c;
    char pom[80];
    pom[0] = '\0';
    int len = 0;
    while (cin.get(c)) {
        if (isalpha(c)) {
            pom[len] = c;
            len++;
        } else if (len > 0 && isalpha(c)) {
            pom[len] = c;
            len++;
        } else if ((c == ' ' || c == '\n') && len > 0) {
            pom[len] = '\0';
            cout << pom << endl;
            len = 0;
        }
    }

    return 0;
}
