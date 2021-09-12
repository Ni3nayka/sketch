#include <iostream>
#include <iomanip>
using namespace std;

//int F(int& II, int N1, int N2, int i, int a) { // , int i
int F(int& II, int a, int i) {
	if (a==22&&i==7) II++; // &&flag1&&flag2 //cout << a << endl; //II++;
	if (a>=22||i>=7) return 0; // ||a==12
	//if (a==6) flag1 = 1;
	//if (a==10) flag2 = 1;
	i++;
	
	F(II,a+1,i);
	F(II,a+2,i);
	F(II,a+3,i);
}

int main () {
	int II = 0;
	F(II, 3, 0);
    cout << II << endl;
    // 28
}






