#include <iostream>
#include <iomanip>
using namespace std;

int translate(int* mas, int r) {
    int answer = 0;
    for (int i=r; i>=0; i--) {
        answer = answer << 1;
        answer += mas[i];
    }
    return answer;
}

int main() {
    int n_2[3] = {1,1,0};
    int n_10 = translate(n_2, 2);
    cout << n_10 << endl;
}
