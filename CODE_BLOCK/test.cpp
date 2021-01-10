#include <iostream>
using namespace std;
#include <fstream>
//#include <stdlib.h>
#include <vector>
//#include "windows.h"

#define FILE 0 // 1 - file; 0 - std

void long_plus(vector <char> &mas1, vector <char> &mas2) { // mas1 += mas2
    if (mas1.size()<mas2.size()) mas1.resize(mas2.size());
    for (int i = 0; i<mas2.size(); i++) mas1[i] += mas2[i];
    if (mas1[mas1.size()-1]!=0) mas1.resize(mas1.size()+1);
    for (int i = 0; i<mas1.size(); i++) {
        if (mas1[i]>9) {
            mas1[i+1] += mas1[i]/10;
            mas1[i] = mas1[i]%10;
        }
    }
}

void long_ost(vector <char> &mas1, vector <char> &mas2) { // mas1 %= mas2
    for (int u = mas1.size()-7; u>=0; u--) {
        bool flag = 1;
        while (flag) {
            vector <char> mas_s;
            for (int i = 0; i<mas1.size(); i++) mas_s.push_back(mas1[i]);
            for (int i = 0; i<mas2.size(); i++) mas1[i+u] -= mas2[i];
            for (int i = 0; i<mas1.size()-1; i++) {
                if (mas1[i]<0) {
                    mas1[i+1]--;
                    mas1[i]+=10;
                    //mas1[i] = mas1[i]%10;
                }
            }
            //flag = 0;
            //for (int i = mas1.size()-1; i>=0; i--) cout << int(mas1[i]) << " "; cout << endl;
            //Sleep(1000);
            for (int i = 0; i<mas1.size() && flag; i++) if (mas1[i]<0) flag = 0;
            if (!flag) for (int i = 0; i<mas1.size(); i++) mas1[i] = mas_s[i];
        }
    }
}

int main() {
    ifstream input;
    typedef vector<char> vchar;
    vector <vchar> mas;
    int N = 0, K = 0;
    if (FILE) input.open("input.txt");
    if (FILE) input >> N >> K;
    else cin >> N >> K;
    mas.resize(N); //mas.push_back(7);
    mas[0].resize(1);
    mas[0][0] = 1;

    for (int I = 0; I<N; I++) for (int i = 1; i<=K&&I+i<N; i++) long_plus(mas[i+I],mas[I]);

    /*for (int i = 0; i<mas.size(); i++) {
        for (int u = mas[i].size()-1; u>=0; u--)
          cout << int(mas[i][u]);
        cout << endl;
    }*/
    /*for (int u = mas[mas.size()-1].size()-1; u>=0; u--) {
        if (u==mas[mas.size()-1].size()-1 && mas[mas.size()-1][u]==0) u--;
        cout << int(mas[mas.size()-1][u]) << " ";
    }
    cout << endl;*/

    vector <char> mas_d;
    mas_d.push_back(7); mas_d.push_back(0); mas_d.push_back(0); mas_d.push_back(0); mas_d.push_back(0); mas_d.push_back(0); mas_d.push_back(1);
    long_ost(mas[mas.size()-1],mas_d);
    int u = mas[mas.size()-1].size()-1;
    for (; u>=0 && mas[mas.size()-1][u]==0; u--);
    for (; u>=0; u--) cout << int(mas[mas.size()-1][u]);// << " ";
    cout << endl;
    //cout << mas[mas.size()-1] << endl;

    return 0;
}
