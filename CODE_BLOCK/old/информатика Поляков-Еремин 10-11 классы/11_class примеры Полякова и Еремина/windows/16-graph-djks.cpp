/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 16. Графы. Кратчайшие пути. Алгоритм Дейкстры
*/
#include <iostream>
#include <fstream>
using namespace std;

const char ASCII[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int INF = 30000;

typedef int *pInt;
pInt *W;
int N;

void ReadWeightMatrix()
{
  ifstream F;     
  int i, j;
  
  F.open ( "input_graphs.dat" );
  F >> N;
  W = new pInt[N];
  for ( i=0; i<N; i++ )
    W[i] = new int[N];
  cout << "Весовая матрица графа: \n";
  cout << "    ";
  for ( j=0; j<N; j++ ) { 
    cout.width(4);
    cout << ASCII[j];
    }
  cout << endl;
  cout << "----";
  for ( j=0; j<N; j++ ) cout << "----";
  cout << endl;
  for ( i=0; i<N; i++ ) {
    cout.width(2);  
    cout << ASCII[i] << " |";
    for ( j=0; j<N; j++ ) {
      F >> W[i][j];
      if ( W[i][j] < 0 ) {
        W[i][j] = INF;
        cout << "   .";
        }
      else {
        cout.width(4);
        cout << W[i][j];
        }  
      }
    cout << endl;
    }
  F.close();
  cout << endl;;
}

main ()
{
  int i, j, k, minDist, kMin;   
  bool *active;
  int *R, *P;

  ReadWeightMatrix();
  active = (bool*) calloc ( N, sizeof(bool) );
  R = (int*) calloc ( N, sizeof(int) );
  P = (int*) calloc ( N, sizeof(int) );

  for ( i=0; i<N; i++ ) {
    active[i] = true;
    R[i] = W[0][i];
    P[i] = 0;
    }
  active[0] = false;
  P[0] = -1;

  for ( i=0; i<N-1; i++ ) {
    minDist = INF+100;    
    for ( j=0; j<N; j++ )
      if ( active[j] && R[j] < minDist) {
        minDist = R[j];
        kMin = j;
        }
    active[kMin] = false;
    for ( j=0; j<N; j++ )
      if ( R[kMin]+W[kMin][j] < R[j] ) {
        R[j] = R[kMin]+W[kMin][j];
        P[j] = kMin;
        }
  }
  
  cout << "Вспомогательные массивы:\n";
  cout << "   ";
  for ( i=0; i<N; i++ ) {
    cout.width(5);
    cout << ASCII[i];
    }
  cout << "\n";
  cout << "---";
  for ( i=0; i<N; i++ ) cout << "-----";
  cout << "\n";
  cout << "R |";
  for ( i=0; i<N; i++ ) {
    cout.width(5);
    cout << R[i];
    }
  cout << "\n";
  cout << "P |";
  for ( i=0; i<N; i++ ) {
    cout.width(5);
    if ( P[i] < 0 )
      cout << '.';
    else  
      cout << ASCII[P[i]];
    }
  cout << endl;

  cout << endl;
  cout << "Кратчайший маршрут из вершины A в вершину " << ASCII[N-1] << ":\n";
  i = N-1;
  while ( i != -1 ) {
    cout.width(2);    
    cout << ASCII[i];
    if ( i != 0 )
      cout << " <- ";
    i = P[i];
    }

  cin.get(); 
}
