/*void test_n() {
  navigator(3, 10);
  i = 1;
  while ((i < 40) && (dor[i][i] < 200)) { // длинна дороги до какой то точки
    Serial.print(i);
    Serial.print(" ");
    Serial.println(dor[i][i]);
    i++;
  }
  i = 1;
  Serial.println("------------");
  while ((i < 40) && (pyt[i] > 0)) { // путь по точкам
    Serial.print(pyt[i]);
    Serial.print(" ");
    i++;
  }
  Serial.println();
  Serial.println("------------");
  i = 1; 
  while ((i < 80) && (pyt_auto[i] > 0)) { // путь по действиям
    Serial.print(pyt_auto[i]);
    Serial.print(" ");
    i++;
  }
}*/

/* navigator(t_start, t_finish);
 * if (t_finish == 0) { просто длины путей до всех точек; }
 */

/* pyt_auto():
 * 1 - linia (V)
 * 2 - L
 * 3 - R
 * 4 - N 
 */

#define ras 33  // кол-во вершин + 1

byte dor[ras*4][2] {
  {0, 0},
  {1, 2},
  {2, 1},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
};
  
char ver[ras][5] { // №, x, y, посещена ли, сколько доехать до неё (mas)
  {0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0}, // обозначили стартовую локацию №1
  {2, 0, 0, 0, 0}, // обозначили вторую (переднюю локацию)
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
};

byte pyt[ras];
byte pyt_auto[ras*2];
byte napr = 1;
byte Napr;

void navigator(byte t_start, byte t_finish) {
  byte t_nast = 1;
  byte ii = 1;
  byte iii = 1;
  byte gg = 1;
  byte aa = 1;
  byte t1 = 1;
  byte t2 = 1; 
  while (ii < ras) {
    ver[ii][4] = 101;
    ii++;
  }
  ii = 1;
  ver[t_nast][4] = 0;
  //while (gg > 0) {
  gg = 0;
  while (t_nast < ras) {
    t_nast++;
  }






















    
/*    while (t_nast < ras) {
      while (ii < ras) {
        while (((dor[iii][0] != t_nast) || (dor[iii][1] != ii)) && (iii < 101)) { iii++; }
        if ((iii < 100) && (ver[ii][4] < ver[t_nast][4] + 1)) {
          ver[ii][4] = ver[t_nast][4] + 1;
          //gg++;
        }
        ii++;
      }
      ii = 1;
      t_nast++;
    }
    t_nast = 1;
  //}
*/


  
  /*ii = 1;
  while (ii < ras) {
    dor[ii][ii] = 200;
    ii++;
  }
  ii = 1;
  t_nast = t_start; dor[t_nast][t_nast] = 0;
  gg = 1;
  while (gg > 0) {
    gg = 0;
    while (t_nast < ras) {
      while (ii < ras) {
        if ((dor[t_nast][ii] > 0) && (dor[ii][ii] > dor[t_nast][t_nast] + dor[t_nast][ii])) {
          dor[ii][ii] = dor[t_nast][t_nast] + dor[t_nast][ii];
          gg++;
        }
        ii++;
      }
      ii = 1;
      t_nast++;
    }
    t_nast = 1;
  }*/
  //----------------------------------------------------
  /*if (t_finish > 0) {
    t_nast = t_finish;
    pyt[1] = t_finish;
    ii = 1;
    gg = 2;
    while (t_nast != t_start) {
      while (dor[t_nast][ii] == 0) {
        ii++;
      }
      if ((dor[t_nast][ii] + dor[ii][ii]) == dor[t_nast][t_nast]) {
        t_nast = ii;
        ii = 1;
        pyt[gg] = t_nast;
        gg++;
      }
      else {
        ii++;
      }
    }
    t_nast = t_finish;
    pyt[1] = t_finish;
    ii = 1;
    gg = 2;
    while (t_nast != t_start) {
      while (dor[t_nast][ii] == 0) {
        ii++;
      }
      if ((dor[t_nast][ii] + dor[ii][ii]) == dor[t_nast][t_nast]) {
        t_nast = ii;
        ii = 1;
        pyt[gg] = t_nast;
        gg++;
      }
      else {
        ii++;
      }
    }
    ii = 1; gg = 1;
    while (pyt[gg] != 0) {
      gg++;
    }
    gg--;
    if (gg % 2 == 0) {
      while ((gg - ii) >= 1) {
        t_nast = pyt[ii];
        pyt[ii] = pyt[gg];
        pyt[gg] = t_nast;
        ii++;
        gg--;
      }
    }
    else {
      while ((gg - ii) >= 2) {
        t_nast = pyt[ii];
        pyt[ii] = pyt[gg];
        pyt[gg] = t_nast;
        ii++;
        gg--;
      }
    }
    ii = 1; gg = 1;
    while (pyt[ii] != 0) {
      if (pyt[ii] == pyt[ii+1]) {
        gg = ii;
        while (pyt[gg] != 0) {
          pyt[gg] = pyt[gg+1];
          gg++;
        }
      }
      else {
        ii++;
      }
    }
    //------------------------------ mypyt(); 
    /*
    ii = 1;
    while (pyt_auto[ii] != 0) {
      pyt_auto[ii] = 0;
      ii++;
    }
    ii = 1; gg = 1; aa = 2;
    t_nast = t_start;
    Napr = napr;
    while (t_nast != t_finish) {
      //if (((napr == 1) && (ver[t_nast][1] + 1 == ver[t_finish][1]) && (ver[t_nast][2] == ver[t_finish][2])) || ((napr == 2) && (ver[t_nast][1] == ver[t_finish][1]) && (ver[t_nast][2] + 1 == ver[t_finish][2])) || ((napr == 3) && (ver[t_nast][1] - 1 == ver[t_finish][1]) && (ver[t_nast][2] == ver[t_finish][2])) || ((napr == 4) && (ver[t_nast][1] == ver[t_finish][1]) && (ver[t_nast][2] - 1 == ver[t_finish][2]))) { pyt_auto[ii] = 1; }                             
      if (((Napr == 1) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] - 1 == ver[pyt[aa]][2])) || ((Napr == 2) && (ver[t_nast][1] + 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2])) || ((Napr == 3) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] + 1 == ver[pyt[aa]][2])) || ((Napr == 4) && (ver[t_nast][1] - 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2]))) { 
        pyt_auto[ii] = 2; 
        ii++; 
        if (Napr == 1) { Napr = 4; }
        else { Napr--; }
      }
      if (((Napr == 1) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] + 1 == ver[pyt[aa]][2])) || ((Napr == 2) && (ver[t_nast][1] - 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2])) || ((Napr == 3) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] - 1 == ver[pyt[aa]][2])) || ((Napr == 4) && (ver[t_nast][1] + 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2]))) { 
        pyt_auto[ii] = 3; 
        ii++; 
        if (Napr == 4) { Napr = 1; }
        else { Napr++; }
      }
      if (((Napr == 1) && (ver[t_nast][1] - 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2])) || ((Napr == 2) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] - 1 == ver[pyt[aa]][2])) || ((Napr == 3) && (ver[t_nast][1] + 1 == ver[pyt[aa]][1]) && (ver[t_nast][2] == ver[pyt[aa]][2])) || ((Napr == 4) && (ver[t_nast][1] == ver[pyt[aa]][1]) && (ver[t_nast][2] + 1 == ver[pyt[aa]][2]))) { 
        pyt_auto[ii] = 4; 
        ii++; 
        if (Napr == 1) { Napr = 4; }
        else { Napr--; }
        if (Napr == 1) { Napr = 4; }
        else { Napr--; }
      }                             
      pyt_auto[ii] = 1; ii++;
      //---------------------------------------------
      do {  // если есть прямые без перекрестков
        gg = 1;
        iii = 0;
        while (gg < ras) {
          if ((dor[t_nast][gg] > 0) && (gg != t_nast)) {
            if ((Napr == 1) || (Napr == 3)) {
              if (ver[t_nast][2] == ver[gg][2]) {
                iii = 3;
              }
              else {
                iii++;
              }
            }
            if ((Napr == 2) || (Napr == 4)) {
              if (ver[t_nast][1] == ver[gg][1]) {
                iii = 3;
              }
              else {
                iii++;
              }
            }
          } 
          gg++;
        } 
        t_nast = pyt[aa];
        aa++;
      } while (iii == 2); 
      //t_nast = pyt[aa]; aa++;  // если нет прямых без перекрестков
    }
    //myt = t_finish;
    //napr = Napr;
  }*/
}





//((Napr == 2) || (Napr == 4)) && (ver[t_nast][1] == ver[gg][1]) && ((ver[t_nast][2] + 1 == ver[gg][2]) || (ver[t_nast][2] - 1 == ver[gg][2]))  


