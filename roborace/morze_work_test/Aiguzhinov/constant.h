const int spiker = 4; // PIN

// size sound
const int tochka = 100;
const int tire = 500;
const int probel = 100;
const int probel_2 = probel * 2;
const int sound = 1000;

const int mas_size = 7;
const int azbuka[26][mas_size] = {
  {0,1,2,0,0,0,0}, // A
  {1,0,0,0,2,0,0}, // B
  {1,0,1,0,2,0,0}, // C
  {1,0,0,2,0,0,0}, // D
  {0,2,0,0,0,0,0}, // E
  {0,0,1,0,2,0,0}, // F
  {1,1,0,2,0,0,0}, // G
  {0,0,0,0,2,0,0}, // H
  {0,0,2,0,0,0,0}, // I
  {0,1,1,1,2,0,0}, // J
  {1,0,1,2,0,0,0}, // K
  {0,1,0,0,2,0,0}, // L
  {1,1,2,0,0,0,0}, // M
  {1,0,2,0,0,0,0}, // N
  {1,1,1,2,0,0,0}, // O
  {0,1,1,0,2,0,0}, // P
  {1,1,0,1,2,0,0}, // Q
  {0,1,0,2,0,0,0}, // R
  {0,0,0,2,0,0,0}, // S
  {1,2,0,0,0,0,0}, // T
  {0,0,1,2,0,0,0}, // U
  {0,0,0,1,2,0,0}, // V
  {0,1,1,2,0,0,0}, // W
  {1,0,0,1,2,0,0}, // X
  {1,0,1,1,2,0,0}, // Y
  {1,1,0,2,0,0,0}, // Z
};

char azbuka_s[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
