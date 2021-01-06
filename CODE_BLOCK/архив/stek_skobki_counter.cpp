#include <iostream>
#include <iomanip>
using namespace std;

//#include <math.h>
//#include <cmath>
//#include <stdlib.h>

//#include <vector>
//#include <fstream>
#include <stack>

int main () {
    //ifstream Fin;
    //ofstream Fout;
    string S;
    stack <int> stak;

    cin >> S;
    //int mas[4] = {0}; // () [] {} <>
    bool flag = 1;

    for (int i = 0; S[i]!=0 && flag; i++) {
        if      (S[i]=='(') stak.push(1);
        else if (S[i]=='[') stak.push(2);
        else if (S[i]=='{') stak.push(3);
        else if (S[i]=='<') stak.push(4);
        else if (!stak.empty() && (S[i]==')' || S[i]==']' || S[i]=='}' || S[i]=='>')) {
            if      (S[i]==')' && stak.top()==1) stak.pop();
            else if (S[i]==']' && stak.top()==2) stak.pop();
            else if (S[i]=='}' && stak.top()==3) stak.pop();
            else if (S[i]=='>' && stak.top()==4) stak.pop();
            else flag = 0;
        }
        else if (S[i]==')' || S[i]==']' || S[i]=='}' || S[i]=='>') flag = 0;
    }

    if (flag && stak.empty()) cout << "YES";
    else cout << "NO";

    //Fin.close();
    //Fout.close();
    return 0;
}
// ({}())[>]

