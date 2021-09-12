#include <iostream>
#include <iomanip>
using namespace std;

#include <math.h>
#include <cmath>
#include <stdlib.h>

#include <vector>
#include <fstream>

/*
vector <unsigned char> long_number; // массив для хранения большого числа

void input_to_long_number(unsigned long int x) { // запись в long_number большого числа

}

int fact (int n) {
	unsigned long int r = 1;
	int i = 1;
	if (n%2==0) i = 2;
	for (;i <= n; i+=2) r *= i;
	cout << r;
}
*/

int number(char F) { // for (i = 0; S[i] != 0; i++) a = a*10 + decoding(S[i]);
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
    else if (F == '0') c = 0;
    return c;
}

void ultra_fact(unsigned long int x, unsigned long int y) {
    //char mas[1000] = {0};
    vector <unsigned char> mas;
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
    ifstream input;
    ofstream output;
    vector <unsigned char> mas;
    vector <unsigned char> mas2;
    string S;
    int i = 0;

    input.open("input.txt");
    output.open("output.txt");

    getline(input, S); //while (getline(student, S)) {}
    for (i=S.size()-1; 0<=i; i--) mas.push_back(number(S[i]));

    getline(input, S); //while (getline(student, S)) {}
    for (i=S.size()-1; 0<=i; i--) mas2.push_back(number(S[i]));

    while (mas.size()-1<=mas2.size()) mas.push_back(0);

    for (i = 0; i<mas2.size(); i++) mas[i] += mas2[i];

    /*getline(input, S);
    while (mas.size()<=S.size()) mas.push_back(0);
    for (i=mas.size()-1; 0<=i; i--) mas[mas.size()-1-i] += number(S[i]); //cout << int(mas[mas.size()-1-i]) << " "; cout << endl;

    //for (i=S.size()-1; 0<=i; i--) cout << number(S[i]) << " "; cout << endl;   //{ int y = int(mas[i]); mas[mas.size()-i-1] += number(S[i]); cout << y << " " << number(S[i]) << " " << int(mas[i]) << endl; } cout << endl;
    */

    for (i=0; i<mas.size() && 1; i++) {
        if (mas[i]>9) {
            while (mas[i]>9) {
                mas[i] -= 10;
                mas[i+1]++;
            }
        }
    }

    for (i=mas.size()-1; 0<=i && mas[i]==0; i--);
    for (; 0<=i; i--) output << int(mas[i]);// cout << endl; //  << " "

    //for (i=mas2.size()-1; 0<=i && mas2[i]==0; i--);
    //for (; 0<=i; i--) cout << int(mas2[i]); cout << endl;

    input.close();
    output.close();
}
