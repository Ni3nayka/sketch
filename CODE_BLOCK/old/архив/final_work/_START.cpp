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
float a = 123.1234567; cout << fixed << setprecision(3) << a; // => 123.123
*/
int   a,  b,  c,  d,  e,  f,  g,  h,  i,   j,  k,  l,  m,  n,  o,  p,  q,  r,  s,  t,  u,  v,  w,  x,  y,  z;
float af, bf, cf, df, ef, ff, gf, hf, ifl, jf, kf, lf, mf, nf, of, pf, qf, rf, sf, tf, uf, vf, wf, xf, yf, zf;
int mas[20];


int decoding(char F) { // for (i = 0; S[i] != 0; i++) a = a*10 + decoding(S[i]);
    int c = 0;
    if      (F == '1') c = 1;
    else if (F == '2') c = 2;
    else if (F == '3') c = 3;
    else if (F == '4') c = 4;
    else if (F == '5') c = 5;
    else if (F == '6') c = 6;
    else if (F == '7') c = 7;
    else if (F == '8') c = 8;
    else if (F == '9') c = 9;
    else             c = 0;
    return c;
}

int mg(char f) {
    int m = 0;
    if (f == 'a') m = 1;
    if (f == 'b') m = 2;
    if (f == 'c') m = 3;
    if (f == 'd') m = 4;
    if (f == 'e') m = 5;
    if (f == 'f') m = 6;
    if (f == 'g') m = 7;
    if (f == 'h') m = 8;
    if (f == 'i') m = 9;
    if (f == 'j') m = 10;
    if (f == 'k') m = 11;
    if (f == 'l') m = 12;
    if (f == 'm') m = 13;
    if (f == 'n') m = 14;
    if (f == 'o') m = 15;
    if (f == 'p') m = 16;
    if (f == 'q') m = 17;
    if (f == 'r') m = 18;
    if (f == 's') m = 19;
    if (f == 't') m = 20;
    if (f == 'u') m = 21;
    if (f == 'v') m = 22;
    if (f == 'w') m = 23;
    if (f == 'x') m = 24;
    if (f == 'y') m = 25;
    if (f == 'z') m = 26;
    if (f == 'A') m = 101;
    if (f == 'B') m = 102;
    if (f == 'C') m = 103;
    if (f == 'D') m = 104;
    if (f == 'E') m = 105;
    if (f == 'F') m = 106;
    if (f == 'G') m = 107;
    if (f == 'H') m = 108;
    if (f == 'I') m = 109;
    if (f == 'I') m = 110;
    if (f == 'K') m = 111;
    if (f == 'L') m = 112;
    if (f == 'M') m = 113;
    if (f == 'N') m = 114;
    if (f == 'O') m = 115;
    if (f == 'P') m = 116;
    if (f == 'Q') m = 117;
    if (f == 'R') m = 118;
    if (f == 'S') m = 119;
    if (f == 'T') m = 120;
    if (f == 'U') m = 121;
    if (f == 'V') m = 122;
    if (f == 'W') m = 123;
    if (f == 'X') m = 124;
    if (f == 'Y') m = 125;
    if (f == 'Z') m = 126;
    return m;
}

char mg2(int m) {
    char f = 0;
    if (m == 1  ) f = 'a';
    if (m == 2  ) f = 'b';
    if (m == 3  ) f = 'c';
    if (m == 4  ) f = 'd';
    if (m == 5  ) f = 'e';
    if (m == 6  ) f = 'f';
    if (m == 7  ) f = 'g';
    if (m == 8  ) f = 'h';
    if (m == 9  ) f = 'i';
    if (m == 10 ) f = 'j';
    if (m == 11 ) f = 'k';
    if (m == 12 ) f = 'l';
    if (m == 13 ) f = 'm';
    if (m == 14 ) f = 'n';
    if (m == 15 ) f = 'o';
    if (m == 16 ) f = 'p';
    if (m == 17 ) f = 'q';
    if (m == 18 ) f = 'r';
    if (m == 19 ) f = 's';
    if (m == 20 ) f = 't';
    if (m == 21 ) f = 'u';
    if (m == 22 ) f = 'v';
    if (m == 23 ) f = 'w';
    if (m == 24 ) f = 'x';
    if (m == 25 ) f = 'y';
    if (m == 26 ) f = 'z';
    if (m == 101) f = 'A';
    if (m == 102) f = 'B';
    if (m == 103) f = 'C';
    if (m == 104) f = 'D';
    if (m == 105) f = 'E';
    if (m == 106) f = 'F';
    if (m == 107) f = 'G';
    if (m == 108) f = 'H';
    if (m == 109) f = 'I';
    if (m == 110) f = 'I';
    if (m == 111) f = 'K';
    if (m == 112) f = 'L';
    if (m == 113) f = 'M';
    if (m == 114) f = 'N';
    if (m == 115) f = 'O';
    if (m == 116) f = 'P';
    if (m == 117) f = 'Q';
    if (m == 118) f = 'R';
    if (m == 119) f = 'S';
    if (m == 120) f = 'T';
    if (m == 121) f = 'U';
    if (m == 122) f = 'V';
    if (m == 123) f = 'W';
    if (m == 124) f = 'X';
    if (m == 125) f = 'Y';
    if (m == 126) f = 'Z';
    return f;
}

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
