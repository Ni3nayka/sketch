/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 15. Графы. Построение минимального остовного дерева графа
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
  int i, j, k, c, minDist, iMin, jMin;   
  int *col;
  pInt *ostov;

  ReadWeightMatrix();
  col = new int[N];
  ostov = new pInt[N];
  for ( i=0; i<N; i++ )
    ostov[i] = new int[2];

  for ( i=0; i<N; i++ ) col[i] = i;
  
  for ( k=0; k<N-1; k++ ){
    minDist = INF+100;
    for ( i=0; i<N; i++ )
      for ( j=0; j<N; j++ )
        if ( col[i] != col[j] && W[i][j] < minDist ) 
          {
            iMin = i; jMin = j; minDist = W[i][j];
          }
    ostov[k][0] = iMin;
    ostov[k][1] = jMin;
    c = col[jMin];
    for ( i=1; i<N; i++ )
      if ( col[i] == c ) 
        col[i] = col[iMin];
    }

  cout << "Минимальное остовное дерево графа: \n";
  for ( i=0; i<N-1; i++ )
    cout << "(" << ASCII[ostov[i][0]] << "," << 
                   ASCII[ostov[i][1]] << ")" << endl;
     
  cin.get(); 
}
