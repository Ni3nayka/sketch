/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 7. Динамические матрицы
*/
#include <iostream>
using namespace std;

typedef int *pInt;

void printMatrix ( pInt X[], int N, int M )
{
  int i, j;
  cout << "Массив:\n";
  for ( i=0; i<N; i++ ) {
    for ( j=0; j<M; j++ ) {
      cout.width(3);  
      cout << X[i][j];
      }
    cout << endl;
    }
  cout << "\nРазмер массива " << N*M << endl;
}

main ()
{
  pInt *A;
  int i, j, N, M;

  cout << "Введите размеры матрицы (число строк и столбцов): ";
  cin >> N >> M;

  A = new pInt[N];
  for ( i=0; i<N; i++ )
    A[i] = new int[M];
    
  for ( i=0; i<N; i++ )
    for ( j=0; j<M; j++ )
      A[i][j] = i + j;

  printMatrix ( A, N, M );

  for ( i=0; i<N; i++ )
    delete [] A[i];
  delete [] A;  
                 
  cin.get(); cin.get();
}
