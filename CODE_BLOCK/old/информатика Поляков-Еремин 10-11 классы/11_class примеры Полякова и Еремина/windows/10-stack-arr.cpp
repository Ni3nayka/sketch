/*
 ��������� � �������� ����������� ��� 11 ������
 �.�. �������� � �.�. �������.
 ����� 6.
 ��������� � 10. ������ ������� �� �����
                 ������������� ������ stack  
*/
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

main ()
{
  ifstream Fin;
  ofstream Fout;
  stack<int> S;
  int x;

  Fin.open ( "input_arr.dat" );
  while ( Fin >> x ) 
    S.push ( x );
  Fin.close();     

  Fout.open ( "output_arr.dat" );
  while ( ! S.empty() ) {
    Fout << S.top() << "\n";
    S.pop();
    }
  Fout.close();     

  cout << "\n��������� ������� � ���� output_arr.dat\n";
  cin.get(); 
}
