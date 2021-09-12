/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 9. Алфавитно-частотный словарь.
                Использование класса map  
*/
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

main ()
{
  ifstream Fin;
  ofstream Fout;
  string s;
  map<string,int> L;
  
  Fin.open ( "input_list.txt" );
  while ( Fin >> s ) {
//    L[s] ++; // при обращении к несуществующему элементу
             // контейнера map он создается с нулевым значением!
    /* полная версия - все вручную! */
      int p;
      p = L.count ( s );
      if ( p == 1 ) L[s] ++;
      else          L.insert ( pair<string,int> (s, 1) );
    /**/    
    }
  Fin.close();     

  Fout.open ( "output_list.txt" );
  map<string,int>::iterator it;
  for ( it=L.begin(); it!=L.end(); it++ )
    Fout << it->first << ": " << it->second << "\n";
  Fout.close();     

  cout << "\nРезультат записан в файл output_list.txt\n";

  cin.get(); 
}
