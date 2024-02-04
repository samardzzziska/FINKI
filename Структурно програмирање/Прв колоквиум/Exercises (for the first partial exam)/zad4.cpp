/* From SI are read N pairs of integers, where the first number is the students' points, and the second is the max. points.
 * Write a program where for each pair (points, max points), will print the students success in percentage and his grade following these rules:

if the student has 90% or more - "10".
if the student has 80% or more - "9".
if the student has 70% or more - "8".
if the student has 60% or more - "7".
if the student has 50% or more - "6".
If the student has less than 50% print "FAIL". */
#include <iostream>

using namespace std;

int main () {

    int points, maxpoints;
    float grade;

    int limit;
    cin >> limit;

    for (int i = 0; i < limit; i++) {

        cin >> points >> maxpoints;

        grade = (100.00 * points)/maxpoints;

        cout << grade;

        if (grade < 50) {
            cout << " FAIL" << endl;
        } else if (grade >= 50 && grade < 60) {
            cout << " 6" << endl;
        } else if (grade >= 60 && grade < 70) {
            cout << " 7" << endl;
        } else if (grade >= 70 && grade < 80) {
            cout << " 8" << endl;
        } else if (grade >= 80 && grade < 90) {
            cout << " 9" << endl;
        } else if (grade >= 90) {
            cout << " 10" << endl;
        }

    }

    return 0;
}