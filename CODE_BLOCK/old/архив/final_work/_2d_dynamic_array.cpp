#include <iomanip>
#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

main2() {
    typedef vector<int> vint;
    vector <vint> A;
    int N = 10;
    int M = 15;
    A.resize ( N );
    for (int i = 0; i < N; i++ )
        A[i].resize ( M );
    //cout << A.size() << endl;
    //A.resize ( N - 1);
    //cout << A.size() << endl;

    for (int i = 0; i < A.size(); i++ )
      for (int j = 0; j < A[i].size(); j++ )
        A[i][j] = i + j;

    for (int i = 0; i < A.size(); i++ ) {
        for (int j = 0; j < A[i].size(); j++ )
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    A.resize ( N + 1);
    for (int i = 0; i < A.size(); i++ ) {
        for (int j = 0; j < A[i].size(); j++ )
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    A.resize ( N - 2);
    for (int i = 0; i < A.size(); i++ ) {
        for (int j = 0; j < A[i].size(); j++ )
            cout << A[i][j] << " ";
        cout << endl;
    }

}

main() {
    typedef vector<char> vchar;
    vector <vchar> A;
    ifstream student;
    string S;
    student.open("student.txt");
    int j = 0;
    while (getline(student, S)) {
        A.resize(j+1);
        for (int y = 0; S[y] != 0; y++) {
            A[j].resize(y+1);
            A[j][y] = S[y];
            cout << S[y];
        }
        cout << endl;
        j++;
    }
    cout << endl << A.size() << endl << A[0].size() << endl << endl;
    student.close();

    for (int i = 0; i < A.size(); i++ ) {
        for (int j = 0; j < A[i].size(); j++ )
            cout << A[i][j];// << " ";
        cout << endl;
    }
    //cout << A[0][2];
}
