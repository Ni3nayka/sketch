/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 2. Длинные числа (факториал 100) 
 Вход: 
   нет 
 Результат: 
   Факториал числа 100:
   93326215443944152681...
*/
#include <iostream>
using namespace std;
void Write6 ( long int x )
{ 
  long int M = 100000L; 
  while ( M  > 0 ) {
    cout << x / M; 
    x %= M; 
    M /= 10; 
    } 
}
main ()
{
  const int N = 33, d = 1000000L; 
  long int A[N+1];
  int i, k, s, r;
  A[0] = 1; 
  for ( i=1; i<=N; i++ )
    A[i] = 0;
  for ( k=2; k<=100; k++ ) {
    r = 0;
    for ( i=0; i<=N; i++ ) {
      s = A[i]*k + r;
      A[i] = s % d;
      r = s / d;
      }
    } 
  i = N; 
  while ( ! A[i] )  
    i --;
  cout << "Факториал числа 100:\n";  
  cout << A[i];
  for ( k=i-1; k>=0; k-- )
    Write6 ( A[k] );
  cin.get();
}
