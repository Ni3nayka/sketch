#include <iostream>
#include <iomanip>
using namespace std;

//int F(int& II, int N1, int N2, int i, int a) { // , int i
int F(int& II, int a) {
	if (a==33) II++; //cout << a << endl; //II++;
	if (a>=33) return 0;
	
	//i++;
	
	F(II,a+1);
	F(II,a+10);
	//F(II,a*2);
}

int main () {
	int II = 0;
	F(II, 10);
    cout << II << endl;
    // 25
}





