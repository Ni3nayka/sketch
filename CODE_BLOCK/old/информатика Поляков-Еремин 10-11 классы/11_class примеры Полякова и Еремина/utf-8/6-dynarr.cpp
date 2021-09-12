/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 6. Динамические массивы
*/
#include <iostream>
using namespace std;
void printArray ( int X[], int N )
{
  int i;
  cout << "Массив:\n";
  for ( i=0; i<N; i++ )
    cout << X[i] << " ";
  cout << "\nРазмер массива " << N << endl;
}
main ()
{
  int *A;
  int i, N;

  cout << "Введите размер массива: ";
  cin >> N;
  A = new int[N];
  for ( i=0; i<N; i++ )
    A[i] = i;
  printArray ( A, N );

  delete [] A;
                 
  cin.get(); cin.get();
}
