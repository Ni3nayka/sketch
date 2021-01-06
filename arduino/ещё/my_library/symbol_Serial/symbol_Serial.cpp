#include <symbol_Serial.h>
#include <Arduino.h>

char symbol_read() {
    if (Serial.available() > 0) {
        char f = Serial.read();
        if (symbol_test(f)) return f;
    }
    else return 0;
}

char abc_read() {
    if (Serial.available() > 0) {
        char f = Serial.read();
        if (abc_test(f)) return f;
    }
    else return 0;
}

char sign_read() {
    if (Serial.available() > 0) {
        char f = Serial.read();
        if (sign_test(f)) return f;
    }
    else return 0;
}

bool symbol_test(char f) {
  bool a = 0;
  if (abc_test(f) || sign_test(f)) a = 1;
  return(a);
}

bool abc_test(char f) {
  bool a = 0;
  if      ((f == 'q') || (f == 'w') || (f == 'e') || (f == 'r') || (f == 't') || (f == 'y') || (f == 'u') || (f == 'i') || (f == 'o') || (f == 'p') || (f == 'a') || (f == 's') || (f == 'd') || (f == 'f') || (f == 'g') || (f == 'h') || (f == 'j') || (f == 'k') || (f == 'l') || (f == 'z') || (f == 'x') || (f == 'c') || (f == 'v') || (f == 'b') || (f == 'n') || (f == 'm')) a = 1;
  else if ((f == 'Q') || (f == 'W') || (f == 'E') || (f == 'R') || (f == 'T') || (f == 'Y') || (f == 'U') || (f == 'I') || (f == 'O') || (f == 'P') || (f == 'A') || (f == 'S') || (f == 'D') || (f == 'F') || (f == 'G') || (f == 'H') || (f == 'J') || (f == 'K') || (f == 'L') || (f == 'Z') || (f == 'X') || (f == 'C') || (f == 'V') || (f == 'B') || (f == 'N') || (f == 'M')) a = 1;
  return a;
}

bool sign_test(char f) {
    bool a = 0;
    if ((f == '`') || (f == '~') || (f == '!') || (f == '@') || (f == '#') || (f == '$') || (f == '%') || (f == '^') || (f == '&') || (f == '*') || (f == '(') || (f == ')') || (f == '-') || (f == '_') || (f == '+') || (f == '=') || (f == '{') || (f == '}') || (f == '[') || (f == ']') || (f == ';') || (f == ':') || (f == '"') || (f == '|') || (f == '/') || (f == ',') || (f == '<') || (f == '.') || (f == '>') || (f == '?') || (f == ' ') || (f == '1') || (f == '2') || (f == '3') || (f == '4') || (f == '5') || (f == '6') || (f == '7') || (f == '8') || (f == '9') || (f == '0'))  a = 1;
    return a;
}
