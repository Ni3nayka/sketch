#include <iostream>
#include <iomanip>
using namespace std;

//#include <math.h>
//#include <cmath>
//#include <stdlib.h>

//#include <vector>
#include <fstream>
#include <stack>

int main() {
    ifstream Fin;
    ofstream Fout;
    stack <int> stak;
    string S;
    int x;
    Fin.open("input.txt");
    Fout.open("output.txt");
    //while ( Fin >> x ) stak.push ( x );
    bool flag = 1;
    while (getline(Fin, S)) {
        if (S[0]=='-') {
            if ( stak.empty() ) { // стек пуст
                Fout << "ERROR" << endl;
                return 0;
            }
            else {
                stak.pop();
            }

        }
        else if (S[0]=='+') {
            int mas = 0;
            for (int i = 1; i<S.size(); i++) {
				if (S[i]=='0') mas = mas*10+0;
				if (S[i]=='1') mas = mas*10+1;
				if (S[i]=='2') mas = mas*10+2;
				if (S[i]=='3') mas = mas*10+3;
				if (S[i]=='4') mas = mas*10+4;
				if (S[i]=='5') mas = mas*10+5;
				if (S[i]=='6') mas = mas*10+6;
				if (S[i]=='7') mas = mas*10+7;
				if (S[i]=='8') mas = mas*10+8;
				if (S[i]=='9') mas = mas*10+9;
			}
            //cout << mas << " ";
            stak.push(mas);
        }

    }

    if (stak.empty()) {
        Fout << "EMPTY" << endl;
        return 0;
    }
    else {
        stack <int> stak2;
        while ( ! stak.empty() ) {
            stak2.push(stak.top());
            stak.pop();
        }
        while ( ! stak2.empty() ) {
            Fout << stak2.top() << " ";
            stak2.pop();
        }
    }
    Fin.close();
    Fout.close();
    return 0;
}
