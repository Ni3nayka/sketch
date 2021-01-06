/*
 ��������� � �������� ����������� ��� 11 ������
 �.�. �������� � �.�. �������.
 ����� 6.
 ��������� � 9. ���������-��������� �������.
                ������������� ������ map  
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
//    L[s] ++; // ��� ��������� � ��������������� ��������
             // ���������� map �� ��������� � ������� ���������!
    /* ������ ������ - ��� �������! */
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

  cout << "\n��������� ������� � ���� output_list.txt\n";

  cin.get(); 
}
