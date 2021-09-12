#include <iostream>
#include <iomanip>
using namespace std;

#include <math.h>
#include <cmath>
#include <stdlib.h>

#include <vector>
#include <fstream>

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
    if (f == 'J') m = 110;
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
    m = m%100;
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
    if (m == 110) f = 'J';
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

typedef struct {
    string S;
    int i;
} book;

bool ravno(string S1, string S2) {
    if (S1.size()==S2.size()) {
        for (int i = S1.size()-1; i>0; i--) if (S1[i]!=S2[i]) return 0;
        return 1;
    }
    else return 0;
}

bool alphabet(string S1, string S2) {
    int s1 = S1.size();
    int s2 = S2.size();
    for (int i = 0; i<s2 && i<s1; i++) {
        if (mg(S1[i])>mg(S2[i])) return 1;
        else if (mg(S1[i])<mg(S2[i])) return 0;
    }
    return 0;
}

int main () {
    ifstream input;
    ofstream output;
    //typedef vector<char> vchar;
    //vector <vchar> A;
    vector <book> mas;
    mas.resize(1);
    unsigned int mas_i = 1; // размер mas
    mas[mas_i-1].i = 1;
    string S;
    //int i = 0;

    input.open("input.txt");
    output.open("output.txt");

    // запись из файла в массив
    int i = 0, u = 0;
    while (getline(input, S)) {
        unsigned int r = S.size();
        for (i = 0; i<r; i++) {
            for (;i<r && mg(S[i]); i++) mas[mas_i-1].S += mg2(mg(S[i])); //cout << S[i];
            //cout << endl;
            if (mas[mas_i-1].S.size()>0) {
                mas.resize(mas_i+1);
                mas_i++;
                mas[mas_i-1].i = 1;
            }
        }
    }

    // удаление пустот
    for (i = mas.size()-1; i>0; i--) {
        if (ravno(mas[i].S, "")) mas[i].i = 0; // mas[i].delete();
    }

    // суммирование элементов
    for (i = mas.size()-1; i>0; i--) {
        for (u = i-1; u>=0; u--) {
            if (ravno(mas[i].S, mas[u].S)) {
                mas[i].i += mas[u].i;
                mas[u].i = 0;
            }
        }
    }

    // раставить по алфавиту
    for (i = mas.size()-1; i>0; i--) {
        for (u = i-1; u>=0; u--) {
            if (alphabet(mas[i].S, mas[u].S)) {
                mas_i    = mas[i].i;
                S        = mas[i].S;
                mas[i].i = mas[u].i;
                mas[i].S = mas[u].S;
                mas[u].i = mas_i;
                mas[u].S = S;
            }
        }
    }

    // поиск максимума
    mas_i = 0;
    for (i = mas.size()-1; i>0; i--) if (mas[i].i>mas_i) mas_i = mas[i].i;

    // вывод массива
    while (mas_i>0 && 1) {
        //for (u = 1; u<=26; u++)  && mas[i].S[0]==mg2(u)
        for (i = mas.size()-1; i>=0; i--)  if (mas[i].i==mas_i) output << mas[i].S << " " << mas[i].i << endl;
        mas_i--;
    }


    //for (i = mas.size()-1; i>=0; i--) if (mas[i].i>0) cout << mas[i].S << " " << mas[i].i << endl;

    //for (i = 0; i<r; i++) if (mas[i].i>0) cout << mas[i].S << " " << mas[i].i << endl;

    input.close();
    output.close();
}
