/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 12. Очередь. Заливка области
                 Использование класса queue 
*/
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

const int XMAX = 5, YMAX = 5, NEW_COLOR = 2;

typedef struct {
       int x, y;
     } TPoint;   
     
TPoint Point( int x, int y )
{
  TPoint P;      
  P.x = x; P.y = y;
  return P;
}

void ShowMatrix ( int A[YMAX][XMAX] )
{
  int i, j;
  cout << "--------------------\n";
  for ( i=0; i<YMAX; i++ ) {
    for ( j=0; j<XMAX; j++ ) {
      cout.width(3);  
      cout << A[i][j];
      }
    cout << endl;;
    }
  cout << "--------------------\n";
}

main ()
{
  int A[YMAX][XMAX];   
  int i, j, x0, y0, color;
  TPoint pt;
  queue<TPoint> Q;
  ifstream F;

  F.open ( "input_map.dat" );
  for ( i=0; i<YMAX; i++ ) 
    for ( j=0; j<XMAX; j++ )
      F >> A[i][j];
  F.close();
 
  printf ( "Исходная матрица:\n" );
  ShowMatrix ( A );
     
  y0 = 0; x0 = 1;
  color = A[y0][x0];
  Q.push ( Point(x0,y0) );

  while ( ! Q.empty() ) {
    pt = Q.front(); Q.pop();
    if ( A[pt.y][pt.x] == color ) {
      A[pt.y][pt.x] = NEW_COLOR;
      if ( pt.x > 0 ) Q.push ( Point(pt.x-1,pt.y));
      if ( pt.y > 0 ) Q.push ( Point(pt.x,pt.y-1));
      if ( pt.x < XMAX-1 ) Q.push ( Point(pt.x+1,pt.y) );
      if ( pt.y < YMAX-1 ) Q.push ( Point(pt.x,pt.y+1) );
      }
    }

  printf ( "Матрица после заливки:\n" );
  ShowMatrix ( A );

  cin.get(); 
}
