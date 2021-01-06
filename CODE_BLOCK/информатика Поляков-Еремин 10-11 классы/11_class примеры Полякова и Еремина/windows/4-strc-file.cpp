/*
 ��������� � �������� ����������� ��� 11 ������
 �.�. �������� � �.�. �������.
 ����� 6.
 ��������� � 4. ��������� � �����
*/
#include <iostream>
#include <fstream>
using namespace std;

struct TBook {
    char author[40];  // �����, ������ 
    char title[80];   // ��������, ������
    int count;        // ����������, ����� 
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

  cout << "��������� ������ � ������:\n";
  for ( i=0; i<M; i++ )
    cout << Books[i].author << ", " << 
            Books[i].title << ", " << Books[i].count << endl;
            
  if ( M < N ) {
    cout << "\n������� ���� ����� ���������:\n";
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
