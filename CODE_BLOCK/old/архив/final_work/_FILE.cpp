#include <iostream>
#include <iomanip>
using namespace std;
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <fstream> // библиотека для работфы с файлами

void test1() {  // общая информация
    ifstream Fin;  // поток ввода
    ofstream Fout; // поток вывода
    Fin.open ( "input.txt" ); // F:\\input.txt
    Fout.open ( "output.txt" );
      // здесь работаем с файлами
    Fin.close();
    Fout.close();
}

void test2() { // пример работы с файлом
    ifstream F;
    F.open ( "F:\\input.txt" );
    if (F) {
      cout << "File opened";
      // здесь работаем с файлом
    }
    else cout << "File not opened";
    F.close();
}

void test3() { // чтение файла
    int a, b;
    ifstream Fin;
    Fin.open ( "input.txt" );
    Fin >> a >> b;
    if ( Fin.eof() ) printf("data is end"); // данные закончились
    Fin.close();
    Fin.open ( "input.txt" ); // в данном случае произошел переход к началу файла
    Fin.close();
}

void test4() { // запись в файл
    int a = 1, b = 2;
    ofstream Fout;
    Fout.open ( "output.txt" );
    Fout << a << "+" << b << "=" << a + b;
    Fout.close();
}

void test5() {
    //Задача: В файле записано в столбик неизвестное количество чисел. Найти их сумму.
    ifstream Fin;
    Fin.open ( "F:\\input.txt" );
    if (Fin) {
        cout << "File opened" << endl;
        int S, x;
        S = 0;
        while( !Fin.eof() ) {
          if ( Fin >> x ) S = S + x;
        }
        cout << S;
    }
    else cout << "File not opened" << endl;
    Fin.close();
}

void test6() { // вывод массива из файла
    ifstream Fin;
    Fin.open ( "input.txt" );
    int N = 0;
    const int MAX = 100;
    int A[MAX]= {0};
    while ( N < MAX  &&  !Fin.eof() && Fin) {
        if ( Fin >> A[N] ) N ++;
    }
    Fin.close();
}

void test7() { // вывод массива в файл
    ofstream Fout;
    Fout.open ( "output.txt" );
    int N = 0;
    const int MAX = 100;
    int A[MAX]= {0};
    for (int i = 0; i < N; i++ )
      Fout << A[i] << endl;
    Fout.close();
}

void test8() { // чтение строки из файла
    ifstream Fin;
    Fin.open ( "input.txt" );
    string s;
    getline( Fin, s );
    Fin.close();
}

void test9() { // чтение всех строк файла
    ifstream Fin;
    Fin.open ( "input.txt" );
    string s;
    while (getline(Fin, s)) { // F - входной поток; s - строка
      // обработать строку s
      // При неудаче getline вернет NULL!
    }
    Fin.close();
}

void test10() { // разбор строки
    ifstream Fin;
    Fin.open ( "input.txt" );
    // найти в строке пробел
    // удалить из строки кличку с первым пробелом
    // найти в строке пробел
    // выделить возраст перед пробелом
    // преобразовать возраст в числовой вид
    string s, s1;
    int p, age;
    // ...
    // мухтар 4 немецкая овчарка
    // 4 => p+1
    // "немецкая овчарка" не повлияет
    p = s.find ( ' ' );
    s1 = s.substr ( p + 1 ); // до конца строки
    age = atoi ( s1.c_str() ); // к формату стрк Си
    Fin.close();
}

void test11() {
    // Найти среднее арифметическое целых чисел, записанных в файле input.txt в столбик
    // Количество чисел неизвестно. Результат записать в файл output.txt .
    ifstream Fin;
    Fin.open ( "input.txt" );
    ofstream Fout;
    Fout.open ( "output.txt" ); /* F:\\ */
    if (Fin && Fout) {
        //cout << "File opened" << endl;
        int x, i = 0;
        float S = 0;
        while( !Fin.eof() ) {
          if ( Fin >> x ) {
            S = S + x;
            i++;
            //cout << S << " " << x << endl;
          }
        }
        if (S != 0) S /= i;
        //cout << S << endl;
        Fout << fixed << setprecision(3) << S;
    }
    //else cout << "File not opened" << endl;
    Fout.close();
    Fin.close();
}

void test12() {
    //Напишите программу, которая выполняет частотный анализ, определяя долю каждой буквы английского
    //алфавита в общем количестве английских букв в тексте. Символы, не являющиеся буквами английского
    //алфавита, учитывать не нужно. Программа должна вывести доли всех букв, которые встречаются в тексте.
    //Заглавные и строчные буквы не различаются.
    //Входной файл input.txt содержит произвольный текст, в котором есть буквы английского алфавита.
    //В файл output.txt нужно вывести долю каждой буквы, встречающейся в тексте, с тремя знаками в дробной части.
    // Буквы должны быть отсортированы по убыванию их доли. Буквы с равной долей должны следовать в алфавитном порядке.

    ifstream Fin;
    Fin.open ( "input.txt" );
    ofstream Fout;
    Fout.open ( "output.txt" ); /* F:\\ */
    if (Fin && Fout) {
        int mas[27] = {0};
        string S;
        while (getline(Fin, S)) {
            for (int i = 0; S[i] != 0; i++) {
                if (S[i] == 'a') mas[1]++;
                if (S[i] == 'A') mas[1]++;
                if (S[i] == 'b') mas[2]++;
                if (S[i] == 'B') mas[2]++;
                if (S[i] == 'c') mas[3]++;
                if (S[i] == 'C') mas[3]++;
                if (S[i] == 'd') mas[4]++;
                if (S[i] == 'D') mas[4]++;
                if (S[i] == 'e') mas[5]++;
                if (S[i] == 'E') mas[5]++;
                if (S[i] == 'f') mas[6]++;
                if (S[i] == 'F') mas[6]++;
                if (S[i] == 'g') mas[7]++;
                if (S[i] == 'G') mas[7]++;
                if (S[i] == 'h') mas[8]++;
                if (S[i] == 'H') mas[8]++;
                if (S[i] == 'i') mas[9]++;
                if (S[i] == 'I') mas[9]++;
                if (S[i] == 'j') mas[10]++;
                if (S[i] == 'J') mas[10]++;
                if (S[i] == 'k') mas[11]++;
                if (S[i] == 'K') mas[11]++;
                if (S[i] == 'l') mas[12]++;
                if (S[i] == 'L') mas[12]++;
                if (S[i] == 'm') mas[13]++;
                if (S[i] == 'M') mas[13]++;
                if (S[i] == 'n') mas[14]++;
                if (S[i] == 'N') mas[14]++;
                if (S[i] == 'o') mas[15]++;
                if (S[i] == 'O') mas[15]++;
                if (S[i] == 'p') mas[16]++;
                if (S[i] == 'P') mas[16]++;
                if (S[i] == 'q') mas[17]++;
                if (S[i] == 'Q') mas[17]++;
                if (S[i] == 'r') mas[18]++;
                if (S[i] == 'R') mas[18]++;
                if (S[i] == 's') mas[19]++;
                if (S[i] == 'S') mas[19]++;
                if (S[i] == 't') mas[20]++;
                if (S[i] == 'T') mas[20]++;
                if (S[i] == 'u') mas[21]++;
                if (S[i] == 'U') mas[21]++;
                if (S[i] == 'v') mas[22]++;
                if (S[i] == 'V') mas[22]++;
                if (S[i] == 'w') mas[23]++;
                if (S[i] == 'W') mas[23]++;
                if (S[i] == 'x') mas[24]++;
                if (S[i] == 'X') mas[24]++;
                if (S[i] == 'y') mas[25]++;
                if (S[i] == 'Y') mas[25]++;
                if (S[i] == 'z') mas[26]++;
                if (S[i] == 'Z') mas[26]++;
            }
        }
        float V = 0;
        Fout << fixed << setprecision(3);
        for(int i = 1; i <= 26; i++) V += mas[i];
        int max = 0;
        for(int i = 1; i <= 26; i++) if (max < mas[i]) max = mas[i];
        for(; max > 0; max--) {
            if (mas[1]  == max) Fout << "a " << mas[1]/V  << endl;
            if (mas[2]  == max) Fout << "b " << mas[2]/V  << endl;
            if (mas[3]  == max) Fout << "c " << mas[3]/V  << endl;
            if (mas[4]  == max) Fout << "d " << mas[4]/V  << endl;
            if (mas[5]  == max) Fout << "e " << mas[5]/V  << endl;
            if (mas[6]  == max) Fout << "f " << mas[6]/V  << endl;
            if (mas[7]  == max) Fout << "g " << mas[7]/V  << endl;
            if (mas[8]  == max) Fout << "h " << mas[8]/V  << endl;
            if (mas[9]  == max) Fout << "i " << mas[9]/V  << endl;
            if (mas[10] == max) Fout << "j " << mas[10]/V << endl;
            if (mas[11] == max) Fout << "k " << mas[11]/V << endl;
            if (mas[12] == max) Fout << "l " << mas[12]/V << endl;
            if (mas[13] == max) Fout << "m " << mas[13]/V << endl;
            if (mas[14] == max) Fout << "n " << mas[14]/V << endl;
            if (mas[15] == max) Fout << "o " << mas[15]/V << endl;
            if (mas[16] == max) Fout << "p " << mas[16]/V << endl;
            if (mas[17] == max) Fout << "q " << mas[17]/V << endl;
            if (mas[18] == max) Fout << "r " << mas[18]/V << endl;
            if (mas[19] == max) Fout << "s " << mas[19]/V << endl;
            if (mas[20] == max) Fout << "t " << mas[20]/V << endl;
            if (mas[21] == max) Fout << "u " << mas[21]/V << endl;
            if (mas[22] == max) Fout << "v " << mas[22]/V << endl;
            if (mas[23] == max) Fout << "w " << mas[23]/V << endl;
            if (mas[24] == max) Fout << "x " << mas[24]/V << endl;
            if (mas[25] == max) Fout << "y " << mas[25]/V << endl;
            if (mas[26] == max) Fout << "z " << mas[26]/V << endl;
        }
    }
    Fout.close();
    Fin.close();
}

main() {
    test5();
}


