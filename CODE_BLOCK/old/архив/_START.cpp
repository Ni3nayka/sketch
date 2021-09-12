#include <iostream>  // ввод вывод
#include <iomanip>   // исп. значений переменных
using namespace std; // исп. переменных

#include <math.h>    // исп. математических действий  M_PI - это п (окр)
#include <cmath>     // исп. син. кос. тан. модуль и т.п.
#include <stdlib.h>  // рандомные числа rand();

//#include <stdio.h>

/* примеры
cin >> ввод
cout <<  вывод
cout << "DDD" << endl;
int n;
a = 123;   
d = sqrt(d);   корень квадратный из d
abs(a)         модуль а
остаток от деления b = 85 % 10  ___  b = 5
float c=1.7;  c = int(c);
while (условие) {}
if (условие) {} else {}
for (a = 0; a < 10; a++) {}
//-----------------
main() { string s; int i = 0;
getline(cin,s);
while (!(s[i] == 0)) { cout << s[i] << endl; i++; }
}
*/
int   a,  b,  c,  d,  e,  f,  g,  h,  i,   j,  k,  l,  m,  n,  o,  p,  q,  r,  s,  t,  u,  v,  w,  x,  y,  z;
float af, bf, cf, df, ef, ff, gf, hf, ifl, jf, kf, lf, mf, nf, of, pf, qf, rf, sf, tf, uf, vf, wf, xf, yf, zf;
int mas[20];


main()
{
    a = rand();
    cout << a;
}

/* определение точности дроби:
float a, c, i;

main()
{
    a = 123.4567;
    a = a*100;
    while (a >= 1) {
        i++;
        a--;
    }
    c = i/100;
    cout << c;
}
*/

/* определение первого и последнего числа
main() {
    cin >> a;
    a2 = a%10;
    a1 = a;
    while (a1 >= 10) {
        a1 = a1/10;
    }
    cout << a1 << " " << a2;
}
*/
