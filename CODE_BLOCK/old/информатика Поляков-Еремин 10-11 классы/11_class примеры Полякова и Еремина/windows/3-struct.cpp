/*
 ��������� � �������� ����������� ��� 11 ������
 �.�. �������� � �.�. �������.
 ����� 6.
 ��������� � 3. ��������� (������)
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
  TBook B;
  TBook Books[N];
  string s;
  int p;
  
  cout << "������ ��������� TBook: " << sizeof(TBook) << endl;
  cout << "������ ���������� B ���� Book: " << sizeof(B) << endl;
  cout << "������ ���� author: " << sizeof(B.author) << endl;
  cout << "������ ���� title: " << sizeof(B.title) << endl;
  cout << "������ ���� count: " << sizeof(B.count) << endl;
  cout << "������ ������� Books: " << sizeof(Books) << endl;
  
  strcpy ( B.author, "������ �.�." );
  strcpy ( B.title, "�������" );
  B.count = 1;
  cout << "��������� B:\n";
  cout << "author: " << B.author << endl;
  cout << " title: " << B.title << endl;
  cout << " count: " << B.count << endl;
  p = s.find ( " " );
  cout << "������� ������: " << s.substr(0,p) << endl;
  B.count --;
  if ( B.count == 0 )
    cout << "���� ���� ������ ���!" << endl;
 
  cout << "\n������� ���� ��������� B:\n";
  cout << "author: ";
  cin >> B.author;
  cout << " title: ";
  cin >> B.title;
  cout << " count: ";
  cin >> B.count;

  cout << "������ ��������� B:" << endl;
  cout << "author: " << B.author << endl;
  cout << " title: " << B.title << endl;
  cout << " count: " << B.count << endl;
 
  cin.get(); cin.get();
}
