/*
 ��������� � �������� ����������� ��� 11 ������
 �.�. �������� � �.�. �������.
 ����� 6.
 ��������� � 7. ������������ �������
*/
#include <iostream>
using namespace std;

typedef int *pInt;

void printMatrix ( pInt X[], int N, int M )
{
  int i, j;
  cout << "������:\n";
  for ( i=0; i<N; i++ ) {
    for ( j=0; j<M; j++ ) {
      cout.width(3);  
      cout << X[i][j];
      }
    cout << endl;
    }
  cout << "\n������ ������� " << N*M << endl;
}

main ()
{
  pInt *A;
  int i, j, N, M;

  cout << "������� ������� ������� (����� ����� � ��������): ";
  cin >> N >> M;

  A = new pInt[N];
  for ( i=0; i<N; i++ )
    A[i] = new int[M];
    
  for ( i=0; i<N; i++ )
    for ( j=0; j<M; j++ )
      A[i][j] = i + j;

  printMatrix ( A, N, M );

  for ( i=0; i<N; i++ )
    delete [] A[i];
  delete [] A;  
                 
  cin.get(); cin.get();
}
