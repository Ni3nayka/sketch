char str[100];
int s = 0;
int c = 0;

int i = 0;

void setup() {
  Serial.begin(115200);
  //pinMode (13, OUTPUT);
}

void loop() {
  str1();
  if ((str[c-1] == 'h') || (str[c-1] == 'H')) {
    while (i <= c) {
      Serial.print(str[i]);
      i++;
    }
    Serial.println("");
    i = 0;
    c = 0;
  }
}

void str1() {
  if (Serial.available() > 0) {
    s = Serial.read();
    if (s == 'a') { str[c] = 'a'; }
    if (s == 'b') { str[c] = 'b'; }
    if (s == 'c') { str[c] = 'c'; }
    if (s == 'd') { str[c] = 'd'; }
    if (s == 'e') { str[c] = 'e'; }
    if (s == 'f') { str[c] = 'f'; }
    if (s == 'g') { str[c] = 'g'; }
    if (s == 'h') { str[c] = 'h'; }
    if (s == 'i') { str[c] = 'i'; }
    if (s == 'j') { str[c] = 'j'; }
    if (s == 'k') { str[c] = 'k'; }
    if (s == 'l') { str[c] = 'l'; }
    if (s == 'm') { str[c] = 'm'; }
    if (s == 'n') { str[c] = 'n'; }
    if (s == 'o') { str[c] = 'o'; }
    if (s == 'p') { str[c] = 'p'; }
    if (s == 'q') { str[c] = 'q'; }
    if (s == 'r') { str[c] = 'r'; }
    if (s == 's') { str[c] = 's'; }
    if (s == 't') { str[c] = 't'; }
    if (s == 'u') { str[c] = 'u'; }
    if (s == 'w') { str[c] = 'w'; }
    if (s == 'v') { str[c] = 'v'; }
    if (s == 'x') { str[c] = 'x'; }
    if (s == 'y') { str[c] = 'y'; }
    if (s == 'z') { str[c] = 'z'; }
    if (s == 'A') { str[c] = 'A'; }
    if (s == 'B') { str[c] = 'B'; }
    if (s == 'C') { str[c] = 'C'; }
    if (s == 'D') { str[c] = 'D'; }
    if (s == 'E') { str[c] = 'E'; }
    if (s == 'F') { str[c] = 'F'; }
    if (s == 'G') { str[c] = 'G'; }
    if (s == 'H') { str[c] = 'H'; }
    if (s == 'I') { str[c] = 'I'; }
    if (s == 'J') { str[c] = 'J'; }
    if (s == 'K') { str[c] = 'K'; }
    if (s == 'L') { str[c] = 'L'; }
    if (s == 'M') { str[c] = 'M'; }
    if (s == 'N') { str[c] = 'N'; }
    if (s == 'O') { str[c] = 'O'; }
    if (s == 'P') { str[c] = 'P'; }
    if (s == 'Q') { str[c] = 'Q'; }
    if (s == 'R') { str[c] = 'R'; }
    if (s == 'S') { str[c] = 'S'; }
    if (s == 'T') { str[c] = 'T'; }
    if (s == 'U') { str[c] = 'U'; }
    if (s == 'W') { str[c] = 'W'; }
    if (s == 'V') { str[c] = 'V'; }
    if (s == 'X') { str[c] = 'X'; }
    if (s == 'Y') { str[c] = 'Y'; }
    if (s == 'Z') { str[c] = 'Z'; }
    if (s == '0') { str[c] = '0'; }
    if (s == '1') { str[c] = '1'; }
    if (s == '2') { str[c] = '2'; }
    if (s == '3') { str[c] = '3'; }
    if (s == '4') { str[c] = '4'; }
    if (s == '5') { str[c] = '5'; }
    if (s == '6') { str[c] = '6'; }
    if (s == '7') { str[c] = '7'; }
    if (s == '8') { str[c] = '8'; }
    if (s == '9') { str[c] = '9'; }   
    if (s == '@') { str[c] = '@'; }
    if (s == '#') { str[c] = '#'; }
    if (s == '$') { str[c] = '$'; }
    if (s == '%') { str[c] = '%'; }
    if (s == '^') { str[c] = '^'; }
    if (s == '&') { str[c] = '&'; }
    if (s == '*') { str[c] = '*'; }
    if (s == '(') { str[c] = '('; }
    if (s == ')') { str[c] = ')'; }
    if (s == '+') { str[c] = '+'; }
    if (s == '-') { str[c] = '-'; }
    if (s == '_') { str[c] = '_'; }
    if (s == '=') { str[c] = '='; }
    if (s == '/') { str[c] = '/'; }
    if (s == '|') { str[c] = '|'; }
    if (s == '"') { str[c] = '"'; }
    if (s == ':') { str[c] = ':'; }
    if (s == ';') { str[c] = ';'; }
    if (s == ']') { str[c] = ']'; }
    if (s == '[') { str[c] = '['; }
    if (s == '{') { str[c] = '{'; }
    if (s == '}') { str[c] = '}'; }
    if (s == '!') { str[c] = '!'; }
    if (s == '?') { str[c] = '?'; }
    if (s == ',') { str[c] = ','; }
    if (s == '.') { str[c] = '.'; }
    if (s == '<') { str[c] = '<'; }
    if (s == '>') { str[c] = '>'; }
    if (s == '~') { str[c] = '~'; }
    c++;  // 91
  }
}
