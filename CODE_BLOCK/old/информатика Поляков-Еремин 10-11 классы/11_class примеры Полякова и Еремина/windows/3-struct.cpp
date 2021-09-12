/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 3. Структуры (записи)
*/
#include <iostream>
#include <fstream>
using namespace std;
struct TBook {
    char author[40];  // автор, строка 
    char title[80];   // название, строка
    int count;        // количество, целое 
    }; 
main ()
{
  const int N = 100;
  TBook B;
  TBook Books[N];
  string s;
  int p;
  
  cout << "Размер структуры TBook: " << sizeof(TBook) << endl;
  cout << "Размер переменной B типа Book: " << sizeof(B) << endl;
  cout << "Размер поля author: " << sizeof(B.author) << endl;
  cout << "Размер поля title: " << sizeof(B.title) << endl;
  cout << "Размер поля count: " << sizeof(B.count) << endl;
  cout << "Размер массива Books: " << sizeof(Books) << endl;
  
  strcpy ( B.author, "Пушкин А.С." );
  strcpy ( B.title, "Полтава" );
  B.count = 1;
  cout << "Структура B:\n";
  cout << "author: " << B.author << endl;
  cout << " title: " << B.title << endl;
  cout << " count: " << B.count << endl;
  p = s.find ( " " );
  cout << "Фамилия автора: " << s.substr(0,p) << endl;
  B.count --;
  if ( B.count == 0 )
    cout << "Этих книг больше нет!" << endl;
 
  cout << "\nВведите поля структуры B:\n";
  cout << "author: ";
  cin >> B.author;
  cout << " title: ";
  cin >> B.title;
  cout << " count: ";
  cin >> B.count;

  cout << "Теперь структура B:" << endl;
  cout << "author: " << B.author << endl;
  cout << " title: " << B.title << endl;
  cout << " count: " << B.count << endl;
 
  cin.get(); cin.get();
}
