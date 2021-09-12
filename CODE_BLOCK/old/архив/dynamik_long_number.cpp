#include <iostream>
using namespace std;
#include <fstream>
//#include <stdlib.h>
#include <vector>

typedef vector<char> vchar;

#define FILE 0 // 1 - file; 0 - std

void long_plus(vector <char> &mas1, vector <char> &mas2) { // mas1 += mas2
    //if (int i = 0; i+1>mas.size()) mas.resize(i+1);

    if (mas1.size()<mas2.size()) mas1.resize(mas2.size());

    for (int i = 0; i<mas2.size(); i++) mas1[i] += mas2[i];
    if (mas1[mas1.size()-1]!=0) mas1.resize(mas1.size()+1);
    for (int i = 0; i<mas1.size(); i++) {
        if (mas1[i]>9) {
            mas1[i+1] = mas1[i]/10;
            mas1[i] = mas1[i]%10;
        }
    }
}

int main() {
    ifstream input;
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
    for (int u = mas[mas.size()-1].size()-1; u>=0; u--) {
        if (u==mas[mas.size()-1].size()-1 && mas[mas.size()-1][u]==0) u--;
        cout << int(mas[mas.size()-1][u]);
    }
    cout << endl;
    //cout << mas[mas.size()-1] << endl;

    return 0;
}


