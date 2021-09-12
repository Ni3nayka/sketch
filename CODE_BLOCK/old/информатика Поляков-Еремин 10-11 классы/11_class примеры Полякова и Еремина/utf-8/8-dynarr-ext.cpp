/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 8a. Расширение динамических массивов.
                 Использование класса vector
*/
#include <iostream>
#include <vector>
using namespace std;

void printArray ( vector<int> X )
{
  int i;
  for ( i=0; i<X.size(); i++ )
    cout << X[i] << " ";
  cout << "\nРазмер массива " << X.size() << endl;
}
main ()
{
  vector<int> A;
  int i, j, x, N, length, c;
  
  cout << "Вводите числа (0 - закончить ввод): \n";

  cin >> x;
  while ( x != 0 ) {
    A.push_back(x);    
    cin >> x;
    }

  cout << "Массив до сортировки:\n";
  printArray ( A );
  
  N = A.size();
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
