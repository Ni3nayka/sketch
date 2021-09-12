/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 5. Сортировка структур
*/
#include <iostream>
using namespace std;
struct TBook {
    char author[40];  // автор, строка 
    char title[80];   // название, строка
    int count;        // количество, целое 
    }; 
typedef TBook *PBook;  
  
main ()
{
  const int N = 100;
  TBook Books[N], B;
  PBook p[N], p1;
  int i, j, M;
  FILE *F;

  for ( i=0; i<N; i++ ) p[i] = &Books[i];
  
  F = fopen ( "books.dat", "rb" );
  M = fread ( &Books[0], sizeof(TBook), N, F );
  fclose(F);

  cout << "Имеющиеся данные о книгах:\n";
  for ( i=0; i<M; i++ )
    cout << Books[i].author << ", " << 
            Books[i].title << ", " << Books[i].count << endl;
            
  for ( i=0; i<M; i++ )
    for ( j=M-2; j>=i; j-- )
      if ( strcmp(p[j]->author, p[j+1]->author) > 0 ) {
        p1 = p[j]; p[j] = p[j+1];
        p[j+1] = p1;
        }
  cout << "\nПосле сортировки через указатели:\n";
  for ( i=0; i<M; i++ )
    cout << p[i]->author << ", " << 
            p[i]->title << ", " << p[i]->count << endl;
             
  for ( i=0; i<M-1; i++ )
    for ( j=M-2; j>=i; j-- )
      if ( strcmp(Books[j].author, Books[j+1].author) > 0 ) {
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
