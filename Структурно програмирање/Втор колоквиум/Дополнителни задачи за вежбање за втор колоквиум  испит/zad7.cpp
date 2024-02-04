/* Од стандарден влез се чита природен број N (N <= 100), како и низа a[ ] од N цели броеви.

Да се напише функција void premesti(а, n) која го преместува секој пронајден негативен број на крајот на низата.
 По преместувањето редоследот на позитивните броеви треба да остане ист како и во оригиналната низа, а истото важи и за редоследот на негативните.

Нaпишете програма која ќе ја повика функцијата premesti за внесената низа a[ ] и потоа ќе ја испечати новодобиената низа. */
#include <iostream>

using namespace std;

void premesti(int a[], int n) {

    int negativni =0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]<0)
            negativni++;
    }


    for (int i = 0; i < n; i++)
    {
        if(a[i]<0 && negativni>0)
        {
            negativni--;
            int temp = a[i];

            for(int j=i;j<n;j++)
            {
                a[j] = a[j+1];
            }
            a[n-1] =temp;
            i--;
        }
    }
}

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    premesti(a,n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}