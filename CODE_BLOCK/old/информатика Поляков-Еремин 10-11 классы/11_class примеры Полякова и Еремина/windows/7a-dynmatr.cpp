/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 7a. Динамические матрицы
                использование класса vector 
*/
#include <iostream>
#include <vector>
using namespace std;

typedef int *pInt;

void printMatrix ( vector < vector<int> > X )
{
  int i, j;
  cout << "Массив:\n";
  for ( i=0; i<X.size(); i++ ) {
    for ( j=0; j<X[i].size(); j++ ) {
      cout.width(3);  
      cout << X[i][j];
      }
    cout << endl;
    }
  cout << "\nРазмер массива " << X.size()*X[0].size() << endl;
}

typedef vector<int> vint;

main ()
{
  vector <vint> A;
  int i, j, N, M;

  cout << "Введите размеры матрицы (число строк и столбцов): ";
  cin >> N >> M;

  A.resize(N);
  for ( i=0; i<N; i++ )
    A[i].resize(M);
    
  for ( i=0; i<N; i++ )
    for ( j=0; j<M; j++ )
      A[i][j] = i + j;

  printMatrix ( A );
                 
  cin.get(); cin.get();
}
