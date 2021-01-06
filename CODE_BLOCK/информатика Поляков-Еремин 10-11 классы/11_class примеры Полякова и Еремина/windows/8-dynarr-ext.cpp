/*
 ��������� � �������� ����������� ��� 11 ������
 �.�. �������� � �.�. �������.
 ����� 6.
 ��������� � 8a. ���������� ������������ ��������.
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
  int i, j, x, N, length, c;
  
  cout << "������� ����� (0 - ��������� ����): \n";

  cin >> x;
  while ( x != 0 ) {
    A.push_back(x);    
    cin >> x;
    }

  cout << "������ �� ����������:\n";
  printArray ( A );
  
  N = A.size();
  for ( i=0; i<N-1; i++ )
    for ( j=N-2; j>=i; j-- )
      if ( A[j] > A[j+1] ){
        c = A[j]; A[j] = A[j+1]; 
        A[j+1] = c;
        }

  cout << "������ ����� ����������:\n";
  printArray ( A );

  cin.get(); cin.get();
}
