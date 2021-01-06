float ei = 0;
float ed = 0;
float EI[10];
int dat[8];
int dmax[8];
int dmin[8];
int dm[8];
float kp=0; //5
float ki=0;//0
float kd=50;//3
int Mo=200;//150
float M1=0,M2=0;
float ep = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  in();
  pid();
  //serial();
  
}

void test() {
  for (int i = 0; i < 8; i++) {
    Serial.print(analogRead(i));
    Serial.print(" ");
  }
  Serial.println();
  int e = (analogRead(A7) - analogRead(A0))*0.1;
  int MM = 150;
  if (MM < e) e = MM;
  if (-MM > e) e = -MM;
  if (e > 0) {
    analogWrite(6, MM);
    analogWrite(5, MM - e);
  }
  else {
    analogWrite(6, MM - e);
    analogWrite(5, MM);
  }
    digitalWrite(4, 1);
    digitalWrite(3, 0);
    digitalWrite(7, 1);
    digitalWrite(8, 0);
}

void pid()
{
  ep = 10 * ((4 * dm[0] + 3 * dm[1] + 2 * dm[2] + dm[3]) - (dm[4] + 2 * dm[5] + 3 * dm[6] + 4 * dm[7])) / (dm[0] + dm[1] + dm[2] + dm[3] + dm[4] + dm[5] + dm[6] + dm[7]);
  //Serial.println(ep);
  EI[0] = EI[1];
  EI[1] = EI[2];
  EI[2] = EI[3];
  EI[3] = EI[4];
  EI[4] = EI[5];
  EI[5] = EI[6];
  EI[6] = EI[7];
  EI[7] = EI[8];
  EI[8] = EI[9];
  EI[9] = ep;
  ei = (EI[0] + EI[1] + EI[2] + EI[3] + EI[4] + EI[5] + EI[6] + EI[7] + EI[8] + EI[9]) / 10;
  Serial.println(ei);
  ed = ep - ei;
  float U = kp * ep + ki * ei + kd * ed;

  //float U = ep * 6;
  
  M1 = Mo - U;
  M2 = Mo + U;

  if (M1 > 255) M1 = 255;
  if (M1 < 0) M1 = 0;
  if (M2 > 255) M2 = 255;
  if (M2 < 0) M2 = 0;
  
  analogWrite(6, M1);
  analogWrite(5, M2);
  if (M1 > 0)
  {
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
  }
  else
  {
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
  }

  if (M2 > 0)
  {
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }
  else
  {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }

}
void in()
{
  for (int i = 0; i < 8; i++)
  {
    dat[i] = analogRead(i);
    if (dat[i] < dmin[i] || dmin[i] == 0) dmin[i] = dat[i];
    if (dat[i] > dmax[i]) dmax[i] = dat[i];
    dm[i] = map(dat[i], dmax[i], dmin[i], 100, 0);
  }
}

void serial()
{
  Serial.print(dm[0]);
  Serial.print("  ");
  Serial.print(dm[1]);
  Serial.print("  ");
  Serial.print(dm[2]);
  Serial.print("  ");
  Serial.print(dm[3]);
  Serial.print("  ");
  Serial.print(dm[4]);
  Serial.print("  ");
  Serial.print(dm[5]);
  Serial.print("  ");
  Serial.print(dm[6]);
  Serial.print("  ");
  Serial.print(dm[7]);
  Serial.print("    ");
  Serial.print(M1);
  Serial.print("  ");
  Serial.println(M2);
}
