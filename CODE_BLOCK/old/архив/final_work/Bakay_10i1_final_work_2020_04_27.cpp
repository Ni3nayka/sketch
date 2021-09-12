#include <iostream>
#include <iomanip>
using namespace std;
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <vector>

bool znak(char F) {
    if ((F == ' ') || (F == '.') || (F == ',') || (F == ':') || (F == ';') || (F == '!') || (F == '?') || (F == '«') || (F == '»') || (F == 0)) return 1; //
    else return 0;
}

int number(char F) { // for (i = 0; S[i] != 0; i++) a = a*10 + decoding(S[i]);
    int c = -1;
    if      (F == '1') c = 1;
    else if (F == '2') c = 2;
    else if (F == '3') c = 3;
    else if (F == '4') c = 4;
    else if (F == '5') c = 5;
    else if (F == '6') c = 6;
    else if (F == '7') c = 7;
    else if (F == '8') c = 8;
    else if (F == '9') c = 9;
    else if (F == '0') c = 0;
    return c;
}

bool num(char F) {
    if ((F == '1') || (F == '2') || (F == '3') || (F == '4') || (F == '5') || (F == '6') || (F == '7') || (F == '8') || (F == '9') || (F == '0')) return 1;
    else return 0;
}

int mg(char f) {
    int m = 0;
    if (f == 'a') m = 1;
    if (f == 'b') m = 2;
    if (f == 'c') m = 3;
    if (f == 'd') m = 4;
    if (f == 'e') m = 5;
    if (f == 'f') m = 6;
    if (f == 'g') m = 7;
    if (f == 'h') m = 8;
    if (f == 'i') m = 9;
    if (f == 'j') m = 10;
    if (f == 'k') m = 11;
    if (f == 'l') m = 12;
    if (f == 'm') m = 13;
    if (f == 'n') m = 14;
    if (f == 'o') m = 15;
    if (f == 'p') m = 16;
    if (f == 'q') m = 17;
    if (f == 'r') m = 18;
    if (f == 's') m = 19;
    if (f == 't') m = 20;
    if (f == 'u') m = 21;
    if (f == 'v') m = 22;
    if (f == 'w') m = 23;
    if (f == 'x') m = 24;
    if (f == 'y') m = 25;
    if (f == 'z') m = 26;
    if (f == 'A') m = 101;
    if (f == 'B') m = 102;
    if (f == 'C') m = 103;
    if (f == 'D') m = 104;
    if (f == 'E') m = 105;
    if (f == 'F') m = 106;
    if (f == 'G') m = 107;
    if (f == 'H') m = 108;
    if (f == 'I') m = 109;
    if (f == 'J') m = 110;
    if (f == 'K') m = 111;
    if (f == 'L') m = 112;
    if (f == 'M') m = 113;
    if (f == 'N') m = 114;
    if (f == 'O') m = 115;
    if (f == 'P') m = 116;
    if (f == 'Q') m = 117;
    if (f == 'R') m = 118;
    if (f == 'S') m = 119;
    if (f == 'T') m = 120;
    if (f == 'U') m = 121;
    if (f == 'V') m = 122;
    if (f == 'W') m = 123;
    if (f == 'X') m = 124;
    if (f == 'Y') m = 125;
    if (f == 'Z') m = 126;
    return m;
}

char mg2(int m) {
    char f = 0;
    if (m == 1  ) f = 'a';
    if (m == 2  ) f = 'b';
    if (m == 3  ) f = 'c';
    if (m == 4  ) f = 'd';
    if (m == 5  ) f = 'e';
    if (m == 6  ) f = 'f';
    if (m == 7  ) f = 'g';
    if (m == 8  ) f = 'h';
    if (m == 9  ) f = 'i';
    if (m == 10 ) f = 'j';
    if (m == 11 ) f = 'k';
    if (m == 12 ) f = 'l';
    if (m == 13 ) f = 'm';
    if (m == 14 ) f = 'n';
    if (m == 15 ) f = 'o';
    if (m == 16 ) f = 'p';
    if (m == 17 ) f = 'q';
    if (m == 18 ) f = 'r';
    if (m == 19 ) f = 's';
    if (m == 20 ) f = 't';
    if (m == 21 ) f = 'u';
    if (m == 22 ) f = 'v';
    if (m == 23 ) f = 'w';
    if (m == 24 ) f = 'x';
    if (m == 25 ) f = 'y';
    if (m == 26 ) f = 'z';
    if (m == 101) f = 'A';
    if (m == 102) f = 'B';
    if (m == 103) f = 'C';
    if (m == 104) f = 'D';
    if (m == 105) f = 'E';
    if (m == 106) f = 'F';
    if (m == 107) f = 'G';
    if (m == 108) f = 'H';
    if (m == 109) f = 'I';
    if (m == 110) f = 'J';
    if (m == 111) f = 'K';
    if (m == 112) f = 'L';
    if (m == 113) f = 'M';
    if (m == 114) f = 'N';
    if (m == 115) f = 'O';
    if (m == 116) f = 'P';
    if (m == 117) f = 'Q';
    if (m == 118) f = 'R';
    if (m == 119) f = 'S';
    if (m == 120) f = 'T';
    if (m == 121) f = 'U';
    if (m == 122) f = 'V';
    if (m == 123) f = 'W';
    if (m == 124) f = 'X';
    if (m == 125) f = 'Y';
    if (m == 126) f = 'Z';
    return f;
}

bool probel(char F) {
    if (F == ' ') return 1;
    else return 0;
}

bool file_test(int a1, int a2, int a3, int a4) { // marks student subject output
    ifstream Fin;
    bool E = 0;
    if ((a1 == 1) || (a1 == 2)) {
        Fin.open("marks.txt");
        if (!Fin) {
            if (!E) E = 1;
            cout << "Error: file <marks.txt> does not exist" << endl;
        }
        else if (a1 == 2) {
            string S;
            int j = 1;
            bool error = 0;
            while (getline(Fin, S)) {
                int i = 0, a;
                for(; probel(S[i]); i++);
                a = i;
                for(; num(S[i]); i++);    if (i - a == 0) error = 1; a = i;
                for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
                for(; num(S[i]); i++);    if (i - a == 0) error = 1; a = i;
                for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
                for(; num(S[i]); i++);
                if (i - a == 0) error = 1; //a = i;
                else if ((i - 1 != a) && !error) {
                    for(int y = 0; S[y] != 0; y++) if (S[y] != ' ') error = 1;
                    if (error) {
                        if (!E) E = 1;
                        cout << "Error: in file <marks.txt> in " << j << " line - semantic error" << endl;
                    }
                    error = 0;
                }
                for(; probel(S[i]); i++);
                if (S[i] != 0) error = 1;
                if (error) {
                    error = 0;
                    for(int y = 0; S[y] != 0; y++) if (S[y] != ' ') error = 1;
                }
                if (error) {
                    if (!E) E = 1;
                    cout << "Error: in file <marks.txt> in " << j << " line - syntax error" << endl;
                }
                j++;
                error = 0;
            }
        }
        Fin.close();
    }
    if ((a2 == 1) || (a2 == 2)) {
        Fin.open("student.txt");
        if (!Fin) {
            if (!E) E = 1;
            cout << "Error: file <student.txt> does not exist" << endl;
        }
        else if (a2 == 2) {
            string S;
            int j = 1;
            bool error = 0;
            while (getline(Fin, S)) {
                int i = 0, a;
                for(; probel(S[i]); i++);
                a = i;
                for(; num(S[i]); i++);    if (i - a == 0) error = 1; a = i;
                for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
                for(; mg(S[i]); i++);     if (i - a == 0) error = 1; a = i;
                for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
                for(; mg(S[i]); i++);     if (i - a == 0) error = 1; a = i;
                for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
                for(; mg(S[i]); i++);     if (i - a == 0) error = 1; a = i;
                for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
                for(; num(S[i]); i++);    if (i - a == 0) error = 1; a = i;
                for(; probel(S[i]); i++);
                if (S[i] != 0) error = 1;
                if (error) {
                    error = 0;
                    for(int y = 0; S[y] != 0; y++) if (S[y] != ' ') error = 1;
                }
                if (error) {
                    if (!E) E = 1;
                    cout << "Error: in file <student.txt> in " << j << " line - syntax error" << endl;
                }
                j++;
                error = 0;
            }
        }
        Fin.close();
    }
    if ((a3 == 1) || (a3 == 2)) {
        Fin.open("subject.txt");
        if (!Fin) {
            if (!E) E = 1;
            cout << "Error: file <subject.txt> does not exist" << endl;
        }
        else if (a3 == 2) {
            string S;
            int j = 1;
            bool error = 0;
            while (getline(Fin, S)) {
                int i = 0, a;
                for(; probel(S[i]); i++);
                a = i;
                for(; num(S[i]); i++);    if (i - a == 0) error = 1; a = i;
                for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
                for(; mg(S[i]); i++);     if (i - a == 0) error = 1; a = i;
                for(; probel(S[i]); i++);
                if (S[i] != 0) error = 1;
                if (error) {
                    error = 0;
                    for(int y = 0; S[y] != 0; y++) if (S[y] != ' ') error = 1;
                }
                if (error) {
                    if (!E) E = 1;
                    cout << "Error: in file <subject.txt> in " << j << " line - syntax error" << endl;
                }
                j++;
                error = 0;
            }
        }
        Fin.close();
    }
    if ((a4 == 1) || (a4 == 2)) {
        Fin.open("output.txt");
        if (!Fin) {
            if (!E) E = 1;
            cout << "Error: file <output.txt> does not exist" << endl;
        }
        Fin.close();
    }
    return E;
}

void deleted_marks(int n_file, int t) { // t - line in n_file for deleted
    //cout << "dfgdfdfdffyhujikolplkoijhygurijpkltef> " << t << endl;
    ofstream ofile;
    ifstream ifile;
    //if (n_file == 1) ifile.open("marks.txt");
    //if (n_file == 2) ifile.open("student.txt");
    //if (n_file == 3) ifile.open("subject.txt");
    ifile.open("marks.txt");
    typedef vector<char> vchar;
    vector <vchar> A;
    string S;
    int j = 0;
    while (getline(ifile, S)) { // input in array
        A.resize(j+1);
        for (int y = 0; S[y] != 0; y++) {
            A[j].resize(y+1);
            A[j][y] = S[y];
        }
        j++;
    }
    ifile.close();

    if (n_file == 2) ifile.open("student.txt");
    if (n_file == 3) ifile.open("subject.txt");
    int u = 0;
    for (int l = 0; l+1 <= t; l++) getline(ifile, S);
    int i = 0;
    for(; probel(S[i]); i++);
    for(; num(S[i]); i++) u = u*10 + number(S[i]);
    ifile.close();

    ifile.open("marks.txt");
    if (n_file == 2) {
        int j = 0;
        while (getline(ifile, S)) {
            int i = 0, a = 0;
            for(; probel(S[i]); i++);
            for(; num(S[i]); i++) a = a*10 + number(S[i]);
            if (a == u) for(int y = 0; y < A[j].size(); y++) A[j][y] = 0;
            j++;
        }
    }
    if (n_file == 3) {
        int j = 0;
        while (getline(ifile, S)) {
            int i = 0, a = 0;
            for(; probel(S[i]); i++);
            for(; num(S[i]); i++);
            for(; probel(S[i]); i++);
            for(; num(S[i]); i++) a = a*10 + number(S[i]);
            if (a == u) for(int y = 0; y < A[j].size(); y++) A[j][y] = 0;
            j++;
        }
    }
    ifile.close();

    ofile.open("marks.txt"); // <<<=========================================== uncomment
    for (int i = 0; i < A.size(); i++ ) {
        bool fl = 0;
        for (int j = 0; j < A[i].size(); j++ ) if (A[i][j] != 0) fl = 1;
        if (fl) {
            for (int j = 0; j < A[i].size(); j++ )
                ofile << A[i][j]; // <<<========================================================== cout => ofile
            ofile << endl;
        }
    }
    ofile.close();
}

void test() {
    cout << "additional function: View file <output>" << endl;
    ifstream Fin;
    Fin.open("output.txt");
    if (Fin) {
        string S;
        while (getline(Fin, S)) cout << S  << "<" << endl;
    }
    else cout << "Error: this file does not exist" << endl;
    Fin.close();
}

void additional_function_Test_files() {
    cout << "additional function: Test files" << endl;
    if(!file_test(2,2,2,2)) cout << "No syntax errors in files" << endl;
}

void function_1_View_BD() {
    cout << "function 1: View BD" << endl;
    ifstream Fin;
    for (int i = 1; i <= 3; i++) {
        if (i == 1) {
            Fin.open("marks.txt");
            cout << "File <marks.txt>:" << endl;
        }
        if (i == 2) {
            Fin.open("student.txt");
            cout << "File <student.txt>:" << endl;
        }
        if (i == 3) {
            Fin.open("subject.txt");
            cout << "File <subject.txt>:" << endl;
        }
        if (Fin) {
            string S;
            while (getline(Fin, S)) cout << S << endl;
        }
        else cout << "Error: this file does not exist" << endl;
        cout << endl;
        Fin.close();
    }
}

void function_2_Output_BD() {
    cout << "function 2: Output BD" << endl;
    //if (marks && student && subject && output) {
    if (!file_test(2,1,2,1)) {
        file_test(0,2,0,0);
        ifstream marks;   // marks.open("marks.txt");     marks.close();
        ifstream student; // student.open("student.txt"); student.close();
        ifstream subject; // subject.open("subject.txt"); subject.close();
        ofstream output;  // output.open("output.txt");   output.close();
        string S;
        vector <int> mas_s;
        //cout << "mas_s (quantity elements): " <<mas_s.size() << endl; // => 0
        mas_s.push_back(0);
        int D = 0; // max world
        int P = 0; // quantity peoples
        int Sub = 0; // quantity  subjects
        bool error = 0;
        student.open("student.txt");
        while (getline(student, S)) {  // looking for quantity peoples
            int i = 0, a;
            int d1 = 0;
            for(; probel(S[i]); i++);  a = i;
            for(; num(S[i]); i++);     a = i;
            for(; probel(S[i]); i++);  a = i;
            for(; mg(S[i]); i++);
            d1 = i - a + 6; // with probel
            if (D < d1) D = d1;
        }
        student.close();
        //cout << "max world: " << D << endl;
        output.open("output.txt");
        subject.open("subject.txt");
        for(int i = 0; i < D; i++) output << " ";
        while (getline(subject, S)) {   // looking for quantity and read subject
            int i = 0, a;
            for(; probel(S[i]); i++);  a = i;
            if (S[i] != 0) {
                Sub++;
                mas_s.push_back(Sub);
                int kostil = 0;
                for(; num(S[i]); i++) kostil = kostil*10 + number(S[i]);
                mas_s[Sub] = kostil;
                for(; probel(S[i]); i++);  a = i;
                for(; (mg(S[i]) && (a + 3 > i)); i++) output << S[i];
                for(; (a + 4 > i); i++) output << " ";
            }



            /*a = i;
            for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
            for(; mg(S[i]); i++);     if (i - a == 0) error = 1; a = i;
            for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
            for(; mg(S[i]); i++);     if (i - a == 0) error = 1; a = i;
            for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
            for(; mg(S[i]); i++);     if (i - a == 0) error = 1; a = i;
            for(; probel(S[i]); i++); if (i - a == 0) error = 1; a = i;
            for(; num(S[i]); i++);    if (i - a == 0) error = 1; a = i;
            for(; probel(S[i]); i++);
            if (S[i] != 0) error = 1;
            if (error) {
                error = 0;
                for(int y = 0; S[y] != 0; y++) if (S[y] != ' ') error = 1;
            }
            if (!error) {
                if (!E) E = 1;
                cout << "Error: in file <student.txt> in " << j << " line" << endl;
            }
            j++;
            error = 0;*/
        }
        subject.close();
        output << endl;
        //cout << "quantity subject: " << Sub << endl << "subjects numbers: ";
        //for (int i = 1; i <= Sub; i++) cout << mas_s[i] << " "; cout << endl;
        //cout << "mas_s (quantity elements): " <<mas_s.size() << endl; // => 0
        student.open("student.txt");
        while (getline(student, S)) {   // looking for quantity and read subject
            int i = 0, a;
            int d1 = 0;
            for(; probel(S[i]); i++);  a = i;
            if (S[i] != 0) {
                int N = 0; // number student
                for(; num(S[i]); i++) N = N*10 + number(S[i]);
                for(; probel(S[i]); i++);  a = i;
                for(; mg(S[i]); i++) output << S[i];
                output << " ";
                int i2 = i;
                int d = 1;
                for(; probel(S[i2]); i2++);
                if (mg(S[i2])) { output << S[i2] << "."; d -= 2; }
                for(; mg(S[i2]); i2++);
                for(; probel(S[i2]); i2++);
                if (mg(S[i2])) { output << S[i2] << "."; d -= 2; }
                for(; (D + d > i - a); i++) output << " ";
                //==========================================n============
                // marks:
                for (int Sub2 = 1; Sub2 <= Sub; Sub2++) {
                    marks.open("marks.txt");
                    int m_n = 0, m_s = 0, m_m = 0;
                    //int Sub2 = 1;
                    string S1;
                    while ((getline(marks, S1)) && (!m_n) && (!m_s)) {
                        int ii = 0;
                        for(; probel(S1[ii]); ii++);
                        if (S1[ii] != 0) {
                            for(; num(S1[ii]); ii++) m_n = m_n*10 + number(S1[ii]);
                            for(; probel(S1[ii]); ii++);
                            for(; num(S1[ii]); ii++) m_s = m_s*10 + number(S1[ii]);
                            for(; probel(S1[ii]); ii++);
                            for(; num(S1[ii]); ii++) m_m = m_m*10 + number(S1[ii]);
                            for(; probel(S1[ii]); ii++);
                            if ((m_n == N) && (m_s == mas_s[Sub2])) output << m_m;
                            else {
                                m_n = 0;
                                m_s = 0;
                                m_m = 0;
                            }
                        }
                    }
                    if ((!m_n) && (!m_s)) output << " ";
                    output << "   ";
                    marks.close();
                }
                //======================================================
                output << endl;
            }
        }
        student.close();
    }
    else cout << "File <output> not formed" << endl;
}

void function_6_Input_new_record__choose_file() {
    cout << "function 6: Input new record - choose file" << endl; // choose - vibrat
    cout << "enter the number of the file you want to edit: " << endl;
    cout << "1 - <marks>" << endl << "2 - <student>" << endl << "3 - <subject>" << endl << "0 - exit function" << endl;
    int n_file = 0;
    do {
        cout << "==> ";
        cin >> n_file;
        if ((n_file < 0) || (n_file > 3)) cout << "This command does not exist" << endl;
    } while ((n_file < 0) || (n_file > 3));
    if (n_file) {
        cout << "if you want to enter the whole file, then enter <1>" << endl;
        cout << "(but all data from the file will be deleted)" << endl;
        cout << "if you want to escape, then enter <0>" << endl;
        int operation = 0;
        do {
            cout << "=> ";
            cin >> operation;
            if ((operation < 0) || (operation > 1)) cout << "This command does not exist" << endl;
        } while ((operation < 0) || (operation > 1));
        if (operation == 1) {
            ofstream file;
            if (n_file == 1) file.open("marks.txt");
            if (n_file == 2) file.open("student.txt");
            if (n_file == 3) file.open("subject.txt");
            //ifstream Fin;
            if (file) {
                cout << "to exit the file, enter <#>" << endl;
                cout << "enter text:" << endl;
                bool flag = 1;
                string S;
                cin.get();
                while (flag) {
                    cout << "> ";
                    getline(cin,S);
                    for (int i = 0; S[i] != 0; i++) if (S[i] == '#') flag = 0;
                    if (flag) file << S << endl;
                }
            }
            else cout << "Error: this file does not exist" << endl;
            file.close();
        }
    }
    cout << "exit function" << endl;


}

void function_7_Delete_record() {
    cout << "function 7: Delete_record" << endl;
    if (!(file_test(2,1,2,1))) {
        file_test(2,2,2,1);
        cout << "when deleting data from file <student> or <subject>," << endl;
        cout << "related data from file <marks> will be deleted" << endl;
        cout << "enter the number of the file you want to edit: " << endl;
        cout << "1 - <marks>" << endl << "2 - <student>" << endl << "3 - <subject>" << endl << "0 - exit function" << endl;
        int n_file = 0;
        do {
            cout << "==> ";
            cin >> n_file;
            if ((n_file < 0) || (n_file > 3)) cout << "This command does not exist" << endl;
        } while ((n_file < 0) || (n_file > 3));
        if (n_file) {
            ofstream ofile;
            ifstream ifile;
            if (n_file == 1) ifile.open("marks.txt");
            if (n_file == 2) ifile.open("student.txt");
            if (n_file == 3) ifile.open("subject.txt");
            if (ifile) {
                cout << "to exit the file, enter 0 or less" << endl;
                cout << "enter line number to delete" << endl;
                bool flag = 1;
                cin.get();
                typedef vector<char> vchar;
                vector <vchar> A;
                string S;
                int j = 0;
                while (getline(ifile, S)) { // input in array
                    A.resize(j+1);
                    for (int y = 0; S[y] != 0; y++) {
                        A[j].resize(y+1);
                        A[j][y] = S[y];
                    }
                    j++;
                }
                ifile.close();
                while (flag) {
                    cout << "> ";
                    int t;
                    cin >> t;
                    if (!(t > 0)) flag = 0;
                    if (flag) {
                        if ((n_file == 2) || (n_file == 3)) deleted_marks(n_file, t);
                        for (int j = 0; j < A[t-1].size(); j++ ) A[t-1][j] = 0;
                    }
                }
                if (n_file == 1) ofile.open("marks.txt"); // <<<=========================================== uncomment
                if (n_file == 2) ofile.open("student.txt");
                if (n_file == 3) ofile.open("subject.txt");
                for (int i = 0; i < A.size(); i++ ) {
                    bool fl = 0;
                    for (int j = 0; j < A[i].size(); j++ ) if (A[i][j] != 0) fl = 1;
                    if (fl) {
                        for (int j = 0; j < A[i].size(); j++ )
                            ofile << A[i][j]; // <<<========================================================== cout => ofile
                        ofile << endl;
                    }
                }
                ofile.close();
            }
            else cout << "Error: this file does not exist" << endl;
            ifile.close();
        }
    }
    cout << "exit function" << endl;

}

main() {
    cout << "This is final work made by Bakay Egor 10i1" << endl;
    cout << "enabled functions: 1, 2, +-6, 7;" << endl;
    cout << "additional function: 8, 9;" << endl;
    int a;
    do {
        cout << "===> Enter command: ";
        cin >> a;
        if      (a == 0) cout << "Exit program";
        else if (a == 1) function_1_View_BD();
        else if (a == 2) function_2_Output_BD();
        //else if (a == 3)
        //else if (a == 4)
        //else if (a == 5)
        else if (a == 6) function_6_Input_new_record__choose_file();
        else if (a == 7) function_7_Delete_record();
        else if (a == 8) additional_function_Test_files();
        else if (a == 9) test();
        else if ((a > 0) && (a <= 7)) cout << "This function is not working yet..." << endl;
        else cout << "This function does not exist" << endl;
    } while(a != 0);
    //cin.get(); cin.get();
}
