#include <iostream>
#include <iomanip>
using namespace std;

int F2(int a) {
	int mas[17] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};  
	for (int i=0; i<17; i++)
		if (a<mas[i]) return mas[i];
	cout << "ERROR:" << a << endl;
}

int F(int& II, int a, bool flag) {
	if (a==45&&flag) II++; 
	if (a>=45||a==33) return 0; 
	if (a==14) flag = 1;
	//i++;
	
	F(II,a+2,flag);
	F(II,F2(a),flag); 
}

int main () {
	int II = 0;
	F(II, 2, 0);
	cout << II << endl;
    // 881
}






