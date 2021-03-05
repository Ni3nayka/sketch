#include <iostream>
#include <iomanip>
using namespace std;

//int F(int& II, int N1, int N2, int i, int a) { // , int i
int F(int& II, int a, bool flag) {
	if (a==30&&flag) II++; //cout << a << endl; //II++;
	if (a>=30||a==12) return 0;
	if (a==20) flag = 1;
	//i++;
	
	F(II,a+1,flag);
	//F(II,a+10);
	F(II,a*2,flag);
}

int main () {
	int II = 0;
	F(II, 3, 0);
    cout << II << endl;
    // 12
}






