#include <iostream>
#include <iomanip>
using namespace std;

//int F(int& II, int N1, int N2, int i, int a) { // , int i
int F(int& II, int a, bool flag1,bool flag2) {
	if (a==2) II++; // &&flag1&&flag2 //cout << a << endl; //II++;
	if (a<=2) return 0; // ||a==12
	//if (a==6) flag1 = 1;
	//if (a==10) flag2 = 1;
	//i++;
	
	F(II,a-1,flag1,flag2);
	F(II,a-3,flag1,flag2);
	F(II,a/3,flag1,flag2);
}

int main () {
	int II = 0;
	F(II, 22, 0,0);
    cout << II << endl;
    // 2196
}






