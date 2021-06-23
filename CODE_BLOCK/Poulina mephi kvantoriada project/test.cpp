#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    //cout << "Hello, world!\n";
    ifstream file;
    file.open("output.txt");
    cout << "start programm\n";
    if (file) {
        cout << "file <output.txt> is open\n";
        string S;
        int I = 0;
        while (getline(file,S)) I++;
        cout << "file have " << I << " line\n";

        file.close();
        file.open("output.txt");
        //    cout << S << endl;
        //}

        ofstream answer;
        answer.open("answer.txt");
        cout << "create file <answer.txt>\n";
        cout << "start analyzing data\n";
        cout << "====================================\n";

        double a,b,c,d=0;
        double a1,b1,c1,d1=0;
        for (int i = 0; i<I; i++) {
            file >> a >> b >> c >> d;
            cout << a << " " << b << " " << c << " " << d << "   answer: ";
            if (i>0) {
                double aa = a-a1, bb = b-b1;
                if (aa>bb) {
                    if (aa>0) cout << "left\n";
                    else cout << "right\n";
                }
                else {
                    if (bb>0) cout << "down\n";
                    else cout << "up\n";

                }
                if (aa>bb) {
                    if (aa>0) answer << "left\n";
                    else answer << "right\n";
                }
                else {
                    if (bb>0) answer << "down\n";
                    else answer << "up\n";

                }
            }
            a1 = a; b1 = b, c1 = c; d1 = d;
        }

        cout << "====================================\n";
        cout << "finish analyzing data\n";
        answer.close();
        file.close();

        cout << "close all files\n";
    }
    else cout << "ERROR: file not open\n";
    cout << "end programm\n";
    cin.get();
}
