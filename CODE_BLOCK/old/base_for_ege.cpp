#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file;
    file.open("output.txt");
    if (file) {
        string S;
        int I = 0;
        while (getline(file,S)) I++;
        file.close();

        ofstream answer;
        answer.open("answer.txt");
        answer << "left\n";
        answer.close();
    }
    cin.get();
}
