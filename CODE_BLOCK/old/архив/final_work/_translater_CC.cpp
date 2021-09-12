#include <iostream>  // ввод вывод
#include <iomanip>   // исп. значений переменных
using namespace std; // исп. переменных

#include <math.h>    // исп. математических действий  M_PI - это п (окр)
#include <cmath>     // исп. син. кос. тан. модуль и т.п.
#include <stdlib.h>  // рандомные числа rand();\

void perevod_10_2(bool *mas, int t_start, int t_finish, long int a) {
    int i = t_start;
    bool A = 0; if(a < 0) A = 1;
    a = abs(a);
    for (; i <= t_finish; i++) mas[i] = 0;
    i = t_finish;
    while(a > 0) {
        mas[i] = a%2;
        i--;
        a /= 2;
    }
    if (A) {
        i = t_finish;
        while (mas[i] != 1) i--;
        i--;
        for(; i >= t_start; i--) {
            if (mas[i]) mas[i] = 0;
            else mas[i] = 1;
        }
    }
}

void perevod_2_10(bool* mAs, int t_start, int t_finish, long int& a) {
    int i;
    int T = t_finish - t_start;
    bool mas[50] = {0};
    for (i = t_start; i <= t_finish; i++) mas[i-t_start] = mAs[i];
    int A = 1;
    a = 0;
    if (mas[0]) { // a < 0
        A *= -1;
        i = T;
        while (mas[i] != 1) i--;
        i--;
        for(; i >= 0; i--) {
            if (mas[i]) mas[i] = 0;
            else mas[i] = 1;
        }
    }
    int ii = 0;
    for(i = T; i >= 0; i--) {
        if (mas[i]) a += pow(2*1, ii); //
        ii++;
    }
    a *= A;
}

main() {
    int a = 21;
    long int b = 0;
    bool signal[10] = {0}; // начинаем с 1-ого элемента
    perevod_10_2(signal, 2, 9, a); // включая концы
    perevod_2_10(signal, 2, 9, b); // включая концы
    for(int i = 0; i < 10; i++) cout << signal[i];
    cout << endl << b;
}


