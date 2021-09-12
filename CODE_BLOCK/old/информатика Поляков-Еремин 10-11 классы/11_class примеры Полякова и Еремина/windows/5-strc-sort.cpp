/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 5. Сортировка структур перестановкой
*/
#include <iostream>
using namespace std;
struct TBookFile {
    char author[40];  // автор, строка 
    char title[80];   // название, строка
    int count;        // количество, целое 
    }; 
struct TBook {
    string author;  // автор, строка 
    string title;   // название, строка
    int count;        // количество, целое 
    }; 
typedef TBook *PBook;  
  
main ()
{
  const int N = 100;
  TBook Books[N], B;
  TBookFile BFile;

  int i, j, M;
  FILE *F;

  F = fopen ( "books.dat", "rb" );
  M = 0;
  while ( fread(&BFile, sizeof(TBookFile), 1, F ) ) {
    Books[M].author = BFile.author;  
    Books[M].title = BFile.title;  
    Books[M].count = BFile.count;  
    M ++;    
    }
  fclose(F);

  cout << "Имеющиеся данные о книгах:\n";
  for ( i=0; i<M; i++ )
    cout << Books[i].author << ", " << 
            Books[i].title << ", " << Books[i].count << endl;
            
  for ( i=0; i<M-1; i++ )
    for ( j=M-2; j>=i; j-- )
      if ( Books[j].author > Books[j+1].author ) {
        B = Books[j]; Books[j] = Books[j+1];
        Books[j+1] = B;
        }
  cout << "\nПосле сортировки перестановкой:\n";
  for ( i=0; i<M; i++ )
    cout << Books[i].author << ", " << 
            Books[i].title << ", " << Books[i].count << endl;
 
  F = fopen ( "books_sort.dat", "wb" );
  fwrite ( &Books[0], sizeof(TBook), M, F );
  fclose(F);

  cin.get();
}
