#include <iostream>
#include <iomanip>
using namespace std;

#include <math.h>
#include <cmath>
#include <stdlib.h>

#include <vector>

int fact (int n) {
	unsigned long int r = 1;
	int i = 1;
	if (n%2==0) i = 2;
	for (;i <= n; i+=2) r *= i;
	cout << r;
}

void ultra_fact(unsigned long int x) {
    //char mas[1000] = {0};
    vector <unsigned char> mas;
    vector <unsigned char> mas_s;
    vector <unsigned char> mas2;
    int i = 0;
    //cout << mas.size();
    //for (i=0; i<6; i++) mas.push_back(i+1);
    unsigned long int x_c = x;
    //for (i=0; x>0; x/=10) mas.push_back(x%10);
    mas.push_back(1);


    //for (i=0; mas.size()>i; i++) mas2.push_back(0);
    //for (i=0; mas.size()>i; i++) mas2.push_back(0);
    //for (i=mas.size()-1; 0<=i; i--) cout << int(mas[i]);
    //cout << mas.size();
    //for (;x>0;x/=10) mas.push_back( i + 1 );

    unsigned long int ii = 1;
    //if (x_c%2==0) ii = 2;

    i = 0;
    for (;ii <= x_c && 1; ii+=1){ // += 2
        // копируем массив
        for (i=0; mas2.size()>i; i++) mas2[i] = 0; // чистим массив
        for (i=mas2.size(); mas.size()>i; i++) mas2.push_back(0); // добавляем элементы, если не хватает
        for (i=0; mas.size()>i; i++) mas2[i] = mas[i]; // копируем массив

        // на влякий случай
        //mas.push_back(0);

        //cout << "!";

        // производим умножение
        for (int ii2 = ii; ii2 > 1 && 1; ii2--) { // mas+mas2 *ii2 раз

            // складываем все ячейки
            for (i=0; i<mas2.size(); i++) mas[i] += mas2[i];

            // на влякий случай
            if (mas[mas.size()-2]>0 || mas[mas.size()-1]>0) mas.push_back(0);

            // переносим разряды чисел
            for (i=0; i<mas.size() && 1; i++) {
                if (mas[i]>9) {
                    while (mas[i]>9) {
                        mas[i] -= 10;
                        mas[i+1]++;
                    }
                }
            }
        }

        // выводим для теста
        //for (i=mas.size()-1; 0<=i; i--) cout << int(mas[i]); cout << endl;

    } //mas *= ii;
    //cout << endl;

    for (i=mas.size()-1; 0<=i && mas[i]==0; i--);
    for (; 0<=i; i--) cout << int(mas[i]); cout << endl;
    //for (i=mas2.size()-1; 0<=i; i--) cout << int(mas2[i]); cout << endl;
}

int main () {
	unsigned long int x = 0;
	cin >> x;
	ultra_fact(x);
}
