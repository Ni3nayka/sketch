#include <iostream>
using namespace std;
#include <vector>
#include <fstream>

#define FILE 1  // 1 - file; 0 - std

typedef vector<int> vint;

int number(char F) { // for (i = 0; S[i] != 0; i++) a = a*10 + decoding(S[i]);
    if      (F == '1') return 1;
    else if (F == '2') return 2;
    else if (F == '3') return 3;
    else if (F == '4') return 4;
    else if (F == '5') return 5;
    else if (F == '6') return 6;
    else if (F == '7') return 7;
    else if (F == '8') return 8;
    else if (F == '9') return 9;
    else if (F == '0') return 0;
    return -1;
}

//void print(vector <vint> &mas) {
//    for (int u = 0; u<mas.size(); u++) { for (int i = 0; i<mas[u].size(); i++) cout << mas[u][i] << " "; cout << endl; }
//}

int dis(vector <vint> &dor, int point_1, int point_2) {
    /*int i = 1;
    while ((i < ras*4) && ((dor[i][0] != point_1) || (dor[i][1] != point_2))) i++;
    if (i == ras*4) return 99;
    else return dor[i][2];*/
    return dor[point_1][point_2];
}

void deikstra (vector <vint> &dor, int t_start, int t_finish) {
    vector <int> mas;
    vector <int> move;
    int ras = dor.size();
    mas.resize(ras);
    move.resize(ras);
    int i = 0;
    for(; i < ras; i++) mas[i] = 9999;
    mas[t_start] = 0;
    bool gg;
    int perebor_1 = 0;
    int perebor_2 = 0;
    //cout << endl;
    do {
        gg = 0;
        //============================
        //perebor_1 = 1;
        for (perebor_1 = 0; perebor_1 < ras; perebor_1++) {
            //perebor_2 = 1;
            for (perebor_2 = 0; perebor_2 < ras; perebor_2++) {
                if ((dis(dor, perebor_1, perebor_2) > 0) && (mas[perebor_1] + dis(dor, perebor_1, perebor_2) < mas[perebor_2])) {
                    mas[perebor_2] = mas[perebor_1] + dis(dor, perebor_1, perebor_2);
                    gg = 1;
                }
            }
        }
        //============================
    } while (gg == 1);
    //for(i = 0; i < ras; i++) cout << mas[i] << " "; cout << endl; // <=============================================
    if (mas[t_finish]==9999) cout << "0" << endl; // дороги нет
    else {
        //gg = 1; // пока gg == 1 мы не на финише
        int t_nast = t_finish;
        int perebor = 1;
        move[0] = t_finish;
        for(i = 1; i < ras; i++) move[i] = 0;
        i = 1;
        while (t_nast != t_start) {
            perebor = 0;
            gg = 1;
            while (gg) {
                if ((dis(dor, t_nast, perebor) > 0) && (mas[t_nast] - dis(dor, t_nast, perebor) == mas[perebor])) gg = 0;
                else perebor++;
            }
            //cout << perebor << endl;
            move[i] = perebor;
            t_nast = perebor;
            i++;
        }
        for(; i < ras; i++) move[i] = -1;
        //for(i = 0; i < ras; i++) cout << move[i] << " "; cout << endl; // <=============================================
        // для данной задачи
        cout << mas[t_finish] << endl;
        for(i = ras-1; (i>=0)&&(move[i]==-1); i--);
        for(; i>=0; i--) cout << move[i]+1 << " "; cout << endl;
    }
}

int main() {
    // input
    vector <vint> mas;
    string S;
    int RAS = 0;
    ifstream input;
    if (FILE) input.open("input.txt");

    if (FILE) getline(input, S);
    else getline(cin, S);
    for (int i = 0; S[i]; i++) RAS = RAS*10+number(S[i]);
    //cout << RAS << endl;
    mas.resize(RAS);

    for (int u = 0; u<RAS && 1; u++) {

        if (FILE) getline(input, S);
        else getline(cin, S);

        //mas[u].resize(RAS);

        for (int i = 0; S[i];) {
            while (S[i]&&S[i]==' ') i++;
            if (S[i]) {
                int n = 0;
                if (S[i]=='-') {
                    i++;
                    for (;number(S[i])!=-1;i++) n = n*10 + number(S[i]);
                    n *= -1;
                }
                else {
                    for (;number(S[i])!=-1;i++) n = n*10 + number(S[i]);
                }
                mas[u].push_back(n);
                //if (n!=0) mas[u][n-1] = 1;
            }

        }
    }

    vector <int> mas_t;
    if (FILE) getline(input, S);
    else getline(cin, S);
    for (int i = 0; S[i];) {
        while (S[i]&&S[i]==' ') i++;
        if (S[i]) {
            int n = 0;
            if (S[i]=='-') {
                i++;
                for (;number(S[i])!=-1;i++) n = n*10 + number(S[i]);
                n *= -1;
            }
            else {
                for (;number(S[i])!=-1;i++) n = n*10 + number(S[i]);
            }
            mas_t.push_back(n);
            //if (n!=0) mas[u][n-1] = 1;
        }

    }

    if (FILE) input.close();

    //print(mas);
    //cout << mas_t[0] << " " << mas_t[1] << endl;
    deikstra(mas, mas_t[0]-1,mas_t[1]-1);

    return 0;
}
