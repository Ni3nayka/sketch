#include <iostream>
using namespace std;
#include <vector>
#include <fstream>

int tabs = 0; //Для создания отступов
int tabs_max = 0;
int max0 = -30000;
int max1 = -30000;
//Кол-во отступов высчитывается по кол-ву рекурсивного вхождения при выводе в фукцию print

struct Branch //Структура ветки
{
    int Data; //Поле данных
    Branch *LeftBranch; //УКАЗАТЕЛИ на соседние веточки
    Branch *RightBranch;
};

void Add(int aData, Branch *&aBranch) { //Функция внесения данных
    //Если ветки не существует
    if (!aBranch) { //создадим ее и зададим в нее данные
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = 0;
        aBranch->RightBranch = 0;
        return;
    }
    else //Иначе сверим вносимое
        if      (aBranch->Data==aData) return;
        else if (aBranch->Data>aData)  Add(aData, aBranch->LeftBranch);  //Если оно меньше того, что в этой ветке - добавим влево
        else                           Add(aData, aBranch->RightBranch); //Иначе в ветку справа
}

void counter(Branch *aBranch) { //Функция счета длинны дерева
    if (!aBranch) return; //Если ветки не существует - выходим. Выводить нечего
    tabs++; //Иначе увеличим счетчик рекурсивно вызванных процедур
    //Который будет считать нам отступы для красивого вывода

    if (tabs>tabs_max) tabs_max = tabs;

    counter(aBranch->LeftBranch); //Выведем ветку и ее подветки слева

    //for (int i = 0; i<tabs; i++) cout << " "; //Потом отступы
    //cout << aBranch->Data << endl; //Данные этой ветки

    counter(aBranch->RightBranch);//И ветки, что справа

    tabs--; //После уменьшим кол-во отступов
    return;
}

void print(Branch *aBranch) { //Функция вывода дерева
    if (!aBranch) return; //Если ветки не существует - выходим. Выводить нечего
    tabs++; //Иначе увеличим счетчик рекурсивно вызванных процедур
    //Который будет считать нам отступы для красивого вывода

    if (tabs>tabs_max) tabs_max = tabs;

    print(aBranch->LeftBranch); //Выведем ветку и ее подветки слева

    for (int i = 0; i<tabs; i++) cout << " "; //Потом отступы
    cout << aBranch->Data << endl; //Данные этой ветки

    print(aBranch->RightBranch);//И ветки, что справа

    tabs--; //После уменьшим кол-во отступов
    return;
}

void FreeTree(Branch *aBranch) {
    if (!aBranch) return;
    FreeTree(aBranch->LeftBranch);
    FreeTree(aBranch->RightBranch);
    delete aBranch;
    return;
}

int number(char F) { // for (i = 0; S[i] != 0; i++) a = a*10 + decoding(S[i]);
    if      (F == '1') return 1;
    else if (F == '2') return 2;
    else if (F == '3') return 3;
    else if (F == '4') return 4;
    else if (F == '5') return 5;
    else if (F == '6') return 6;
    else if (F == '7') return 7;
    else if (F == '8') return 8;
    else if (F == '9') return 9;
    else if (F == '0') return 0;
    return -1;
}

void search_max(Branch *aBranch) {
    if (!aBranch) return;
    search_max(aBranch->LeftBranch);
    search_max(aBranch->RightBranch);
    if (aBranch->Data>max0) {
        max1 = max0;
        max0 = aBranch->Data;
    }
    else if (aBranch->Data>max1) max1 = aBranch->Data;
    return;
}

void print_increase(Branch *aBranch) {
    if (!aBranch) return;
    print_increase(aBranch->LeftBranch);
    cout << aBranch->Data << " ";
    print_increase(aBranch->RightBranch);
    return;
}

void print_leaves(Branch *aBranch) {
    if (!aBranch) return;
    print_leaves(aBranch->LeftBranch);
    if (aBranch->LeftBranch==0 && aBranch->RightBranch==0) cout << aBranch->Data << " ";
    print_leaves(aBranch->RightBranch);
    return;
}

void print_parents_with_2_children(Branch *aBranch) {
    if (!aBranch) return;
    print_parents_with_2_children(aBranch->LeftBranch);
    if (aBranch->LeftBranch!=0 && aBranch->RightBranch!=0) cout << aBranch->Data << " ";
    print_parents_with_2_children(aBranch->RightBranch);
    return;
}

void print_parents_with_1_child(Branch *aBranch) {
    if (!aBranch) return;
    print_parents_with_1_child(aBranch->LeftBranch);
    if (aBranch->LeftBranch==0 && aBranch->RightBranch!=0 || aBranch->LeftBranch!=0 && aBranch->RightBranch==0) cout << aBranch->Data << " ";
    print_parents_with_1_child(aBranch->RightBranch);
    return;
}

int main() {
    // input
    vector <int> mas;
    string S;
    if (0) getline(cin, S);
    else {
        ifstream input;
        input.open("input.txt");
        getline(input, S);
        input.close();
    }
    for (int i = 0; S[i];) {
        int n = 0;
        while (S[i]&&S[i]==' ') i++;
        if (S[i]) {
            if (S[i]=='-') {
                i++;
                for (;number(S[i])!=-1;i++) n = n*10 + number(S[i]);
                n *= -1;
            }
            else {
                for (;number(S[i])!=-1;i++) n = n*10 + number(S[i]);
            }
            if (n!=0) mas.push_back(n);
            else break;

        }
    }
    //cout << "===" << endl;
    //for (int i = 0; i<mas.size(); i++) cout << mas[i] << " "; cout << endl;

    Branch *Root = 0;
    //char s[] = "732195468";
    //char s[] = input()

    //for (int i = 0; s[i]; i++) Add(s[i], Root);
    for (int i = 0; i<mas.size(); i++) Add(mas[i], Root);

    //print(Root);
    //counter(Root);
    //FreeTree(Root);
    //search_max(Root);
    //print_increase(Root);
    //print_leaves(Root);
    //print_parents_with_2_children(Root);
    print_parents_with_1_child(Root);

    //cout << max1 << endl;

    //cin.get();
    return 0;
}
