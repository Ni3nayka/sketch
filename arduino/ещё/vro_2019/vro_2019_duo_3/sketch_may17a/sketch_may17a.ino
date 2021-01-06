void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void linia() {
  if (ROOT == 1) {
    Serial.println("l");
  A = 0;
  while (A == 0) {
    if (Serial.available() > 0) {
      F = Serial.read();
      if (F == '1') { A = 2.1; }
      if (F == '2') { A = 2.2; }
      if (F == '3') { A = 3.1; }
      if (F == '4') { A = 3.2; }
      if (F == '5') { A = 5;   }
      if (F == '6') { A = 5.1; }
      if (F == '7') { A = 5.2; }
      if (F == '8') { A = 6;   }
      if (F == '9') { A = 4;   }
    }
  }
  //a = 0;
  a = 10;
  while (a == 10) {
    if (Serial.available() > 0) {
      F = Serial.read();
      if (F == '0') { a = 0; }
      if (F == '1') { a = 1; }
      if (F == '2') { a = 2; }
      if (F == '3') { a = 3; }
      if (F == '4') { a = 4; }
      if (F == '5') { a = 5; }
      if (F == '6') { a = 6; }
      if (F == '7') { a = 7; }
      if (F == '8') { a = 8; }
      if (F == '9') { a = 9; }
    }
  }
  }
  else {
    
  }
}

void V() {
  if (ROOT == 1) {
    
  }
  else {
    
  }
}

void N() {
  if (ROOT == 1) {
    Serial.println
  }
  else {
    
  }
  n();
}

void L() {
  if (ROOT == 1) {
    
  }
  else {
    
  }
  l();
}

void R() {
  if (ROOT == 1) {
    
  }
  else {
    
  }
  r();
}

/*
void linia() {
  if (ROOT == 1) {
  Serial.println("l");
  A = 0;
  while (A == 0) {
    if (Serial.available() > 0) {
      F = Serial.read();
      if (F == '1') { A = 2.1; }
      if (F == '2') { A = 2.2; }
      if (F == '3') { A = 3.1; }
      if (F == '4') { A = 3.2; }
      if (F == '5') { A = 5;   }
      if (F == '6') { A = 5.1; }
      if (F == '7') { A = 5.2; }
      if (F == '8') { A = 6;   }
      if (F == '9') { A = 4;   }
    }
  }
  //a = 0;
  a = 10;
  while (a == 10) {
    if (Serial.available() > 0) {
      F = Serial.read();
      if (F == '0') { a = 0; }
      if (F == '1') { a = 1; }
      if (F == '2') { a = 2; }
      if (F == '3') { a = 3; }
      if (F == '4') { a = 4; }
      if (F == '5') { a = 5; }
      if (F == '6') { a = 6; }
      if (F == '7') { a = 7; }
      if (F == '8') { a = 8; }
      if (F == '9') { a = 9; }
    }
  }
  }
  else {
    
  }
}

void V() {
  Serial.println("V");
  SoftSerial.println("V");
  otklik();
}

void N() {
  n();
  if ((A == 5) || (A == 6)) {
    Serial.println("N");
    SoftSerial.println("N"); 
  }
  else if ((A == 2.2) || (A == 3.2) || (A == 5.2) || (A == 4)) {
    Serial.println("L");
    SoftSerial.println("L");
  }
  else if ((A == 2.1) || (A == 3.1) || (A == 5.1)) {
    Serial.println("R");
    SoftSerial.println("R");
  }
  otklik();
}

void L() {
  l();
  Serial.println("L");
  SoftSerial.println("L");
  otklik();
}

void R() {
  r();
  Serial.println("R");
  SoftSerial.println("R");
  otklik();
}
