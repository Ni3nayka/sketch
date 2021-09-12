/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 8. Расширение динамических массивов
*/
#include <iostream>
#include <vector>
using namespace std;

void printArray ( vector <int> X )
{
  int i;
  for ( i=0; i < X.size(); i++ )
    cout << X[i] << " ";
  cout << "\nРазмер массива " << X.size() << endl;
}
main ()
{
  vector <int> A;
  int i, j, x, N, c;

  A.reserve(2);
  cout << "Вводите числа (0 - закончить ввод): \n";

  N = 0;
  cin >> x;
  while ( x != 0 ) {
    N ++;
    if ( N > A.capacity() ) {
      A.reserve ( A.capacity() + 2);
      cout << "Размер массива увеличен до " << A.capacity() << endl;
      }
    A.push_back(x);    
    cin >> x;
    }

  cout << "Массив до сортировки:\n";
  printArray ( A );
  
  for ( i=0; i<N-1; i++ )
    for ( j=N-2; j>=i; j-- )
      if ( A[j] > A[j+1] ){
        c = A[j]; A[j] = A[j+1]; 
        A[j+1] = c;
        }

  cout << "Массив после сортировки:\n";
  printArray ( A );
  
  cin.get(); cin.get();
}
