/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 11. Стек. Проверка скобочных выражений
                 Использование класса stack  
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

main ()
{
  const string L = "([{", R = ")]}";
  string str;    
  stack<char> S;
  bool err;
  int i, p;
  char c;

  cout << "Введите выражения со скобками (), [], {}: ";
  cin >> str;

  for ( i=0; i<str.size(); i++ ) {
    p = L.find ( str[i] );
    if ( p >= 0 )
      S.push ( str[i] );
    p = R.find ( str[i] );
    if ( p >= 0 ) {
      if ( S.empty() ) err = true;
      else {
        c = S.top(); S.pop();
        if ( p != L.find(c) ) err = true;
        }
      if ( err ) break;
      }
    }

  if ( ! S.empty() ) err = true;

  if ( ! err )
     cout << "Скобки расставлены верно.\n";
  else
     cout << "Скобки расставлены неверно.\n";
     
  cin.get(); cin.get(); 
}
