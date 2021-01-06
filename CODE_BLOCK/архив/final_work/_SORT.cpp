#include <iostream>  // ввод вывод
#include <iomanip>   // исп. значений переменных
using namespace std; // исп. переменных

#include <math.h>    // исп. математических действий  M_PI - это п (окр)
#include <cmath>     // исп. син. кос. тан. модуль и т.п.
#include <stdlib.h>  // рандомные числа rand();

#define ras 100000

void out(int *mas, int v) {
    for(int i = 0; i <= v; i++) cout << mas[i] << " ";
    cout << endl;
}

void random(int *mas, int i) {
    for(; i >= 0; i--) mas[i] = rand()%1000;
}

void bubble(int *mas, int v) {
    for(int i = 0; i <= v; i++) {
        for(int u = 0; u < v; u++) {
            if (mas[u+1] < mas[u]) {
                int t = mas[u+1];
                mas[u+1] = mas[u];
                mas[u] = t;
            }
        }
    }
}

void qsort(int nStart, int nEnd) {

}

void Qsort(int *A, int nStart, int nEnd) {
    int  L, R, c, x;
    if (nStart >= nEnd) return; // end;
    L = nStart;
    R = nEnd;
    x = A[(L+R)/2];
    while (L <= R) {
        while (A[L] < x) L++;
        while (A[R] > x) R--;
        if (L <= R) {
            c = A[L];
            A[L] = A[R];
            A[R] = c;
            L++;
            R--;
        }
    }
    Qsort(A, nStart, R);
    Qsort(A, L, nEnd);
}

main() {
    int mas[ras] = {0};
    const int ras1 = ras - 1;
    out(mas, ras1); // make array
    random(mas, ras1);
    out(mas, ras1); // randoming array
    //==========================================
    // sort:
    //bubble(mas, ras1);
    Qsort(mas, 0, ras1);
    //==========================================
    out(mas, ras1); // sort array
}


