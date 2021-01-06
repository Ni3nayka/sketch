/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 10. Реверс массива из файла
                 Использование класса stack  
*/
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

main ()
{
  ifstream Fin;
  ofstream Fout;
  stack<int> S;
  int x;

  Fin.open ( "input_arr.dat" );
  while ( Fin >> x ) 
    S.push ( x );
  Fin.close();     

  Fout.open ( "output_arr.dat" );
  while ( ! S.empty() ) {
    Fout << S.top() << "\n";
    S.pop();
    }
  Fout.close();     

  cout << "\nРезультат записан в файл output_arr.dat\n";
  cin.get(); 
}
