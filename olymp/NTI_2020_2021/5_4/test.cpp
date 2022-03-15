#include <iostream>
using namespace std;
#include <vector>
//#include <windows.h>
//#include <fstream>

#define FILE  1  // 1 - file; 0 - std
#define RAS   145
#define RAS_g 157

typedef vector<int> vint;

int graf[RAS_g][2]   = {{1,2},
                        {2,3},
                        {3,4},
                        {4,5},
                        {5,6},
                        {6,7},
                        {7,8},
                        {8,9},
                        {9,10},
                        {10,11},
                        {11,12},

                        {14,15},
                        {16,17},
                        {18,19},
                        {19,20},

                        {26,27},
                        {28,29},
                        {29,30},
                        {30,31},
                        {31,32},
                        {33,34},

                        {37,38},
                        {38,39},
                        {39,40},
                        {40,41},
                        {41,42},
                        {42,43},
                        {43,44},
                        {45,46},

                        {50,51},
                        {57,58},

                        {62,63},
                        {65,66},
                        {66,67},
                        {69,70},

                        {74,75},
                        {76,77},
                        {77,78},
                        {78,79},
                        {79,80},
                        {81,82},
                        {82,83},

                        {86,87},
                        {89,90},
                        {90,91},
                        {92,93},
                        {94,95},
                        {95,96},

                        {100,101},
                        {101,102},
                        {102,103},
                        {103,104},
                        {104,105},
                        {105,106},
                        {106,107},
                        {107,108},

                        {113,114},
                        {114,115},
                        {116,117},
                        {118,119},

                        {121,122},
                        {122,123},
                        {123,124},
                        {128,129},
                        {130,131},

                        {133,134},
                        {134,135},
                        {135,136},
                        {136,137},
                        {137,138},
                        {138,139},
                        {139,140},
                        {140,141},
                        {141,142},
                        {142,143},
                        {143,144},

                        //

                        {1,13},
                        {13,25},
                        {25,37},
                        {49,61},
                        {61,73},
                        {73,85},
                        {85,97},
                        {97,109},
                        {109,121},
                        {121,133},

                        {14,26},
                        {62,74},
                        {86,98},
                        {98,110},
                        {110,122},

                        {15,27},
                        {51,63},
                        {75,87},
                        {99,111},
                        {111,123},

                        {16,28},
                        {28,40},
                        {40,52},
                        {52,64},
                        {64,76},
                        {76,88},
                        {88,100},
                        {100,112},
                        {112,124},
                        {124,136},

                        {5,17},
                        {41,53},
                        {53,65},
                        {113,125},
                        {125,137},

                        {6,18},
                        {42,54},
                        {126,138},

                        {7,19},
                        {31,43},
                        {43,55},
                        {55,67},
                        {115,127},
                        {127,139},

                        {8,20},
                        {32,44},
                        {44,56},
                        {56,68},
                        {68,80},
                        {80,92},
                        {92,104},
                        {104,116},
                        {116,128},
                        {128,140},

                        {45,57},
                        {69,81},
                        {81,93},
                        {93,105},
                        {105,117},
                        {117,129},

                        {22,34},
                        {34,46},
                        {58,70},
                        {70,82},
                        {118,130},

                        {23,35},
                        {35,47},
                        {47,59},
                        {59,71},
                        {71,83},
                        {119,131},

                        {12,24},
                        {24,36},
                        {36,48},
                        {48,60},
                        {60,72},
                        {72,84},
                        {96,108},
                        {108,120},
                        {120,132},
                        {132,144}};

void print() {
    for (int u = 0; u<RAS_g; u++) { for (int i = 0; i<2; i++) cout << graf[u][i] << " "; cout << endl; }
}

int dis(int point_1, int point_2) {
    for (int i = 0; i<RAS_g; i++)
        if (graf[i][0]==point_1 && graf[i][1]==point_2 || graf[i][1]==point_1 && graf[i][0]==point_2) return 1;
    return 0;
    //return dor[point_1][point_2];
}

int road_time(int napr, vector <int> move) {
    int time = 0, i, ras = RAS;
    for(i = ras-1; (i>=0)&&(move[i]==-1); i--);
    i--;
    for(; i>=0; i--) {
        if (move[i+1]-move[i]==12) { // up
            if      (napr==1) time+=0;
            else if (napr==2) time+=1;
            else if (napr==3) time+=2;
            else if (napr==4) time+=1;
            napr = 1;
        }
        if (move[i+1]-move[i]==1) { // left
            if      (napr==1) time+=1;
            else if (napr==2) time+=0;
            else if (napr==3) time+=1;
            else if (napr==4) time+=2;
            napr = 2;
        }
        if (move[i+1]-move[i]==-12) { // down
            if      (napr==1) time+=2;
            else if (napr==2) time+=1;
            else if (napr==3) time+=0;
            else if (napr==4) time+=1;
            napr = 3;
        }
        if (move[i+1]-move[i]==-1) { // right
            if      (napr==1) time+=1;
            else if (napr==2) time+=2;
            else if (napr==3) time+=1;
            else if (napr==4) time+=0;
            napr = 4;
        }
        time++;
    }
    return time;
}

void road_generator (vector <vint> &move_mas, vector <int> mas, int t_start, int t_finish, vector <int> move) {
    int i = 0, gg = 0;
    int ras = RAS;
    //for (;i<move.size();i++) cout << move[i] << " "; cout << endl;
    int t_nast = t_finish;
    if (move[0]==0) {
        move[0] = t_finish;
        for(i = 1; i < ras; i++) move[i] = 0;
        i = 1;
    }
    else {
        for(i = 1; i<ras && move[i]; i++);
        t_nast = move[i-1];
    }
    //cout << "--" << mas[132] << " " << mas[143] << endl;
    while (t_nast != t_start) {
        for (int perebor = 1; perebor<ras; perebor++) {
            if ((dis(t_nast, perebor) > 0) && (mas[t_nast] - dis(t_nast, perebor) == mas[perebor])) {
                //cout << t_nast << " " << perebor << " " << dis(t_nast, perebor) << endl;
                //Sleep(1000);
                if (!move[i]) {
                    move[i] = perebor;
                    //t_nast = perebor;
                }
                else {
                    int aa = move[i];
                    move[i] = perebor;
                    //cout << "<=======\n";
                    road_generator (move_mas, mas, t_start, t_finish, move);
                    move[i] = aa;
                }
            }
            //else if (t_nast==144) cout << t_nast << " " << perebor << endl;

        }
        t_nast = move[i];
        i++;
    }
    for(; i < ras; i++) move[i] = -1;
    move_mas.resize(move_mas.size()+1);
    move_mas[move_mas.size()-1].resize(ras);
    for (i=0;i<ras;i++) move_mas[move_mas.size()-1][i]=move[i];
}

int deikstra (int t_start, int t_finish, int napr) {
    vector <int> mas;
    vector <int> move;
    int ras = RAS;
    mas.resize(ras);
    move.resize(ras);
    int i = 0;
    for(; i < ras; i++) mas[i] = 999;
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
                if ((dis(perebor_1, perebor_2) > 0) && (mas[perebor_1] + dis(perebor_1, perebor_2) < mas[perebor_2])) {
                    mas[perebor_2] = mas[perebor_1] + dis(perebor_1, perebor_2);
                    gg = 1;
                }
            }
        }
        //============================
    } while (gg == 1);
    //for(i = 0; i < ras; i++) cout << mas[i] << " "; cout << endl; // <=============================================

    //for (i=0;i<move.size();i++) cout << move[i] << " "; cout << endl;

    vector<vint> move_mas;
    //move_mas.resize(1);
    road_generator (move_mas, mas, t_start, t_finish, move);

    /*for (int y = 0; y<move_mas.size(); y++) {
        for (int x = 0; x<move_mas[y].size(); x++)
            cout << move_mas[y][x] << " ";
        cout << endl;
    }*/

    vector<int> time_mas;
    for (int y = 0; y<move_mas.size(); y++) time_mas.push_back(road_time(napr, move_mas[y]));

    //for (int y = 0; y<time_mas.size(); y++) cout << time_mas[y] << " "; cout << endl;

    int minimum = 999;
    for (int y = 0; y<time_mas.size(); y++)
        if (minimum>time_mas[y]) minimum = time_mas[y];
    return minimum;
    //for (i = 0; i<time_mas.size() && time_mas[i]!=minimum; i++);
    //cout << i << endl;
}

void robot_2(vector <int> &move, int t_nast, int napr) {
    bool l, f;
    move.push_back(t_nast);
    for (int i = 0; i<100; i++) {
        if (napr==1) {
            f = dis(t_nast, t_nast-12);
            l = dis(t_nast, t_nast-1);
        }
        else if (napr==2) {
            f = dis(t_nast, t_nast-1);
            l = dis(t_nast, t_nast+12);
        }
        else if (napr==3) {
            f = dis(t_nast, t_nast+12);
            l = dis(t_nast, t_nast+1);
        }
        else if (napr==4) {
            f = dis(t_nast, t_nast+1);
            l = dis(t_nast, t_nast-12);
        }

        if (!l && f) {
            if      (napr==1) t_nast-=12;
            else if (napr==2) t_nast-=1;
            else if (napr==3) t_nast+=12;
            else if (napr==4) t_nast+=1;
            move.push_back(t_nast);
        }
        else if (l) {
            napr++;
            if (napr==5) napr = 1;
            move.push_back(t_nast);
            if      (napr==1) t_nast-=12;
            else if (napr==2) t_nast-=1;
            else if (napr==3) t_nast+=12;
            else if (napr==4) t_nast+=1;
            move.push_back(t_nast);
        }
        else {
            napr--;
            if (napr==0) napr = 4;
            move.push_back(t_nast);
        }
    }
}

void my_search(vector <int> move, int T1, int D1, int N) {
    cout << N << endl;
    vector <int> mas;
    //if (move[N])
}

int main() {
    int X1 = 7, Y1 = 6, X2 = 1, Y2 = 8, D1, D2, T1, T2;
    char D1_in = 'D', D2_in = 'D';

    if (!FILE) cin >> Y1 >> X1 >> D1_in >> Y2 >> X2 >> D2_in;
    //cout << Y1 << " " << X1 << " " << D1_in << " " << Y2 << " " << X2 << " " << D2_in << endl;

    if      (D1_in=='U') D1 = 1;
    else if (D1_in=='D') D1 = 3;
    else if (D1_in=='L') D1 = 2;
    else if (D1_in=='R') D1 = 4;

    if      (D2_in=='U') D2 = 1;
    else if (D2_in=='D') D2 = 3;
    else if (D2_in=='L') D2 = 2;
    else if (D2_in=='R') D2 = 4;

    T1 = (Y1-1)*12+X1;
    T2 = (Y2-1)*12+X2;
    //cout << T1 << " " << T2 << endl;

    //print();

    //for (int i = 0; i<RAS_g; i++) cout << i << " " << graf[i][0]-graf[i][1] << endl; // test graf


    vector <int> move;
    robot_2(move, T2, D2);
    for (int i = 0; i<move.size(); i++) cout << move[i] << " "; cout << endl;

    my_search(move,T1,D1,move.size()/2);

    /*D1 = 2;
    int time = 0;
    //for (int i = 0; i<10; i++)
    time = deikstra(T1,144, D1);
    cout << time << endl;*/


    return 0;
}
