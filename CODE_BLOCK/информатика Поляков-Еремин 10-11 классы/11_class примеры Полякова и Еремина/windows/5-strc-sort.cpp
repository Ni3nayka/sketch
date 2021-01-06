/*
 ��������� � �������� ����������� ��� 11 ������
 �.�. �������� � �.�. �������.
 ����� 6.
 ��������� � 5. ���������� �������� �������������
*/
#include <iostream>
using namespace std;
struct TBookFile {
    char author[40];  // �����, ������ 
    char title[80];   // ��������, ������
    int count;        // ����������, ����� 
    }; 
struct TBook {
    string author;  // �����, ������ 
    string title;   // ��������, ������
    int count;        // ����������, ����� 
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

  cout << "��������� ������ � ������:\n";
  for ( i=0; i<M; i++ )
    cout << Books[i].author << ", " << 
            Books[i].title << ", " << Books[i].count << endl;
            
  for ( i=0; i<M-1; i++ )
    for ( j=M-2; j>=i; j-- )
      if ( Books[j].author > Books[j+1].author ) {
        B = Books[j]; Books[j] = Books[j+1];
        Books[j+1] = B;
        }
  cout << "\n����� ���������� �������������:\n";
  for ( i=0; i<M; i++ )
    cout << Books[i].author << ", " << 
            Books[i].title << ", " << Books[i].count << endl;
 
  F = fopen ( "books_sort.dat", "wb" );
  fwrite ( &Books[0], sizeof(TBook), M, F );
  fclose(F);

  cin.get();
}
