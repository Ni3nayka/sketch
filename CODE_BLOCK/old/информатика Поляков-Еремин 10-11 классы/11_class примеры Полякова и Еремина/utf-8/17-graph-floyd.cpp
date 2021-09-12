/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 17. Графы. Кратчайшие пути.
                 Алгоритм Флойда-Уоршелла
*/
#include <iostream>
#include <fstream>
using namespace std;

const char ASCII[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int INF = 30000;

typedef int *pInt;
pInt *W, *P;
int N;

void ReadWeightMatrix()
{
  ifstream F;     
  int i, j;
  
  F.open ( "input_graphs.dat" );
  F >> N;
  W = new pInt[N];
  P = new pInt[N];
  for ( i=0; i<N; i++ ) {
    W[i] = new int[N];
    P[i] = new int[N];
    }
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
  int i, j, k;   

  ReadWeightMatrix();

  for ( i=0; i<N; i++ ) {
    for ( j=0; j<N; j++ )
      P[i][j] = i;
    P[i][i] = -1;
    }

  for ( k=0; k<N; k++ ) 
    for ( i=0; i<N; i++ ) 
      for ( j=0; j<N; j++ ) 
        if ( W[i][k] + W[k][j] < W[i][j] ) {
           W[i][j] = W[i][k] + W[k][j];
           P[i][j] = P[k][j];
        }

  cout << "Матрица кратчайших расстояний:\n";
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
      if ( W[i][j] == INF )
        cout << "   .";
      else {
        cout.width(4);
        cout << W[i][j];
        }
      }
    cout << endl;
    }

  cout << endl;
  cout << "Вспомогательная матрица:\n";
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
      cout.width(4);
      cout << P[i][j];
      }
    cout << endl;
    }

  cout << endl;
  for ( i=0; i<N; i++ ) {
    cout << "Кратчайшие маршруты из вершины " << ASCII[i] << ":\n";
    for ( k=0; k<N; k++ ) 
      if ( k != i ) {
        j = k;
        while ( j != -1 ) {
          cout.width(2);    
          cout << ASCII[j];
          if ( j != i )
            cout << " <- ";
          j = P[i][j];
          }
        cout << endl;
        }
    }

  cin.get(); 
}
