/*
 ��������� � �������� ����������� ��� 11 ������
 �.�. �������� � �.�. �������.
 ����� 6.
 ��������� � 6. ������������ �������.
                ������������� ������ vector
*/
#include <iostream>
#include <vector>
using namespace std;
void printArray ( vector<int> X )
{
  int i;
  for ( i=0; i<X.size(); i++ )
    cout << X[i] << " ";
  cout << "\n������ ������� " << X.size() << endl;
}
main ()
{
  vector<int> A;
  int i, N;

  cout << "������� ������ �������: ";
  cin >> N;
  for ( i=0; i<N; i++ )
    A.push_back(i+1);

  printArray ( A );
                 
  cin.get(); cin.get();
}
