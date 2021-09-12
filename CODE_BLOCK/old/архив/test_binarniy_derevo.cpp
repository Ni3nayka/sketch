#include <iostream>
using namespace std;
#include <vector>
#include <fstream>

int tabs = 0; //��� �������� ��������
int tabs_max = 0;
int max0 = -30000;
int max1 = -30000;
//���-�� �������� ������������� �� ���-�� ������������ ��������� ��� ������ � ������ print

struct Branch //��������� �����
{
    int Data; //���� ������
    Branch *LeftBranch; //��������� �� �������� �������
    Branch *RightBranch;
};

void Add(int aData, Branch *&aBranch) { //������� �������� ������
    //���� ����� �� ����������
    if (!aBranch) { //�������� �� � ������� � ��� ������
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = 0;
        aBranch->RightBranch = 0;
        return;
    }
    else //����� ������ ��������
        if      (aBranch->Data==aData) return;
        else if (aBranch->Data>aData)  Add(aData, aBranch->LeftBranch);  //���� ��� ������ ����, ��� � ���� ����� - ������� �����
        else                           Add(aData, aBranch->RightBranch); //����� � ����� ������
}

void counter(Branch *aBranch) { //������� ����� ������ ������
    if (!aBranch) return; //���� ����� �� ���������� - �������. �������� ������
    tabs++; //����� �������� ������� ���������� ��������� ��������
    //������� ����� ������� ��� ������� ��� ��������� ������

    if (tabs>tabs_max) tabs_max = tabs;

    counter(aBranch->LeftBranch); //������� ����� � �� �������� �����

    //for (int i = 0; i<tabs; i++) cout << " "; //����� �������
    //cout << aBranch->Data << endl; //������ ���� �����

    counter(aBranch->RightBranch);//� �����, ��� ������

    tabs--; //����� �������� ���-�� ��������
    return;
}

void print(Branch *aBranch) { //������� ������ ������
    if (!aBranch) return; //���� ����� �� ���������� - �������. �������� ������
    tabs++; //����� �������� ������� ���������� ��������� ��������
    //������� ����� ������� ��� ������� ��� ��������� ������

    if (tabs>tabs_max) tabs_max = tabs;

    print(aBranch->LeftBranch); //������� ����� � �� �������� �����

    for (int i = 0; i<tabs; i++) cout << " "; //����� �������
    cout << aBranch->Data << endl; //������ ���� �����

    print(aBranch->RightBranch);//� �����, ��� ������

    tabs--; //����� �������� ���-�� ��������
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
