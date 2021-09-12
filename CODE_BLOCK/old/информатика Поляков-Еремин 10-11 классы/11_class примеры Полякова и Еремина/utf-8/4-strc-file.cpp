/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 4. Структуры и файлы
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
  TBook Books[N];
  int i, M;
  ifstream Fin;
  ofstream Fout;
  string s;
  
  Fin.open ( "books.dat", ios::binary );  
  Fin.read ( (char*) Books, sizeof(TBook)*N );
  M = Fin.gcount() / sizeof(TBook);
  Fin.close();

  cout << "Имеющиеся данные о книгах:\n";
  for ( i=0; i<M; i++ )
    cout << Books[i].author << ", " << 
            Books[i].title << ", " << Books[i].count << endl;
            
  if ( M < N ) {
    cout << "\nВведите поля новой структуры:\n";
    cout << "author: ";
    getline ( cin, s );
    strcpy ( Books[M].author, s.c_str() );
    cout << " title: ";
    getline ( cin, s );
    strcpy ( Books[M].title, s.c_str() );
    cout << " count: ";
    cin >> s;
    Books[M].count = atoi ( s.c_str() );
    
    M ++;
    Fout.open ( "books.dat", ios::binary );
    Fout.write ( (char*) Books, sizeof(TBook)*M );
    Fout.close();        
    }   
 
  cin.get(); cin.get();
}
