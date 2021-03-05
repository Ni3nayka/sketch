#include <iostream>
#include <iomanip>
using namespace std;

//int F(int& II, int N1, int N2, int i, int a) { // , int i
int F(int& II, int a, int i) {
	if (a==80&&i<=5) II++; // &&flag1&&flag2 //cout << a << endl; //II++;
	if (a>=80||i>=5) return 0; // ||a==12
	//if (a==6) flag1 = 1;
	//if (a==10) flag2 = 1;
	i++;
	
	F(II,a+1,i);
	F(II,a*2,i);
	F(II,a+a%4,i);
}

int main () {
	int III = 0;
	for (int i=0; i<=80; i++) {
		int II = 0;
		F(II, i, 0);
		if (II) III++;
		cout << i << " ) " << II << endl;
	}
	cout << "III: " << III << endl;
    // 34
}






