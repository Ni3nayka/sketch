/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 6. Динамические массивы.
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
  int i, N;

  cout << "Введите размер массива: ";
  cin >> N;
  for ( i=0; i<N; i++ )
    A.push_back(i+1);

  printArray ( A );
                 
  cin.get(); cin.get();
}
