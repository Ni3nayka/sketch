#include <iostream>
using namespace std;
#include <fstream>
//#include <stdlib.h>
#include <vector>

#define FILE 1 // 1 - file; 0 - std

int main() {
    int K, N;
    ifstream input;
    if (FILE) input.open("input.txt");
    if (FILE) input >> N >> K;
    else cin >> N >> K;
    typedef vector<long int> vchar;
    vector <vchar> mas;
    typedef vector<long int> vchar;
    vector <vchar> area;
    mas.resize(N);
    for (int i = 0; i<N; i++) mas[i].resize(K);
    area.resize(N);
    for (int i = 0; i<N; i++)
        for (int u = 0; u<K; u++) {
            int a = 0;
            if (FILE) input >> a;
            else cin >> a;
            area[i].push_back(a);
        }

    mas[0][0] = area[0][0];
    for (int i = 1; i<N; i++) mas[i][0] = area[i][0] + mas[i-1][0];
    for (int i = 1; i<K; i++) mas[0][i] = area[0][i] + mas[0][i-1];

    for (int i = 1; i<N; i++)
        for (int u = 1; u<K; u++)
            mas[i][u] = max(mas[i][u-1],mas[i-1][u])+area[i][u];

    for (int i = 0; i<N; i++) { for (int u = 0; u<K; u++) cout << area[i][u] << " "; cout << endl; }
    for (int i = 0; i<N; i++) { for (int u = 0; u<K; u++) cout << mas[i][u] << " "; cout << endl; }

    cout << mas[N-1][K-1] << endl;

    vector <char> road;
    if (1) {
        int u = K-1, i = N-1;
        while (i>0 || u>0)
            if (!i) {
                u--;
                road.push_back('R');
            }
            else if (!u) {
                i--;
                road.push_back('D');
            }
            else {
                if (mas[i][u-1]>mas[i-1][u]) {
                    u--;
                    road.push_back('R');
                }
                else {
                   i--;
                    road.push_back('D');
                }
            }
    }
    for (int i = road.size()-1; i>=0; i--) cout << road[i]; cout << endl;

    return 0;
}
