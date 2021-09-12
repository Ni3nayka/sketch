/*
 Программа к учебнику информатики для 11 класса
 К.Ю. Полякова и Е.А. Еремина.
 Глава 6.
 Программа № 14. Деревья. Вычисление арифметических выражений.
                 Хранение узлов бинарного дерева в массиве                 
*/
#include <iostream>

using namespace std;

typedef struct {    
    string *data;
    int size;
  } TTree;

void InitTree ( TTree *Tree, int size )
{
   int i;  
   Tree->size = size;
   Tree->data = new string[size];
   for ( i=0; i<size; i++ )
     Tree->data[i] = "";  
}

void ShowTree ( TTree Tree )
{
  int i;
  for ( i=0; i<Tree.size; i++ )
    cout << i+1 << ": " << Tree.data[i] << endl;
}

void AddToTree ( string s, TTree *Tree, int k )
{
  int i;
  string *temp;  
  if ( k > Tree->size ) {
    temp = Tree->data;
    Tree->data = new string[Tree->size+10];  
    for ( i=0; i<Tree->size; i++ )
      Tree->data[i] = temp[i];
    delete temp;
    for ( i=Tree->size; i<Tree->size+10; i++ )
      Tree->data[i] = "";  
    Tree->size += 10;   
    }
  Tree->data[k-1] = s;
}

int Priority ( char op )
{
  switch ( op ) {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    }
  return 100;  
}

int LastOp ( string s )
{
  int i, minPrt, res;
  minPrt = 50;
  res = -1;
  for ( i=0; i<s.size(); i++ )
    if ( Priority(s[i]) <= minPrt ) {
      minPrt = Priority(s[i]);
      res = i;
      }
  return res;
}

void MakeTree ( string s, TTree *Tree, int iRoot )
{
  int k;
  k = LastOp ( s );
  if ( k == -1 ) AddToTree ( s, Tree, iRoot);
  else {
    AddToTree ( s.substr(k,1), Tree, iRoot );
    MakeTree ( s.substr(0,k), Tree, 2*iRoot);
    MakeTree ( s.substr(k+1), Tree, 2*iRoot+1);
    }
}

int Calc ( TTree Tree, int iRoot )
{
  int n1, n2, res;
  if (2*iRoot >= Tree.size || Tree.data[2*iRoot-1][0] == '\0') 
    res = atoi ( Tree.data[iRoot-1].c_str() );
  else {
    n1 = Calc ( Tree, 2*iRoot );
    n2 = Calc ( Tree, 2*iRoot+1 );
    switch ( Tree.data[iRoot-1][0] ) {
      case '+': res = n1 + n2; break;
      case '-': res = n1 - n2; break;
      case '*': res = n1 * n2; break;
      case '/': res = n1 / n2; break;
      default: res = 99999;
    }    
  }
  return res;
}

main ()
{
  TTree Tree;
  string s;   
  cout << "Введите арифметическое выражение без скобок: \n";
  cin >> s;
  InitTree ( &Tree, 5 );
  MakeTree ( s, &Tree, 1 );
  printf ( "Двоичное дерево в массиве:\n" );
  ShowTree ( Tree );
  cout << "Результат: " << Calc(Tree,1);
     
  cin.get(); cin.get(); 
}
