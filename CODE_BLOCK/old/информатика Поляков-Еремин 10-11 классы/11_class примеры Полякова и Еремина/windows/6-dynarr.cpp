/*
 ��������� � �������� ����������� ��� 11 ������
 �.�. �������� � �.�. �������.
 ����� 6.
 ��������� � 6. ������������ �������
*/
#include <iostream>
using namespace std;
void printArray ( int X[], int N )
{
  int i;
  cout << "������:\n";
  for ( i=0; i<N; i++ )
    cout << X[i] << " ";
  cout << "\n������ ������� " << N << endl;
}
main ()
{
  int *A;
  int i, N;

  cout << "������� ������ �������: ";
  cin >> N;
  A = new int[N];
  for ( i=0; i<N; i++ )
    A[i] = i;
  printArray ( A, N );

  delete [] A;
                 
  cin.get(); cin.get();
}
