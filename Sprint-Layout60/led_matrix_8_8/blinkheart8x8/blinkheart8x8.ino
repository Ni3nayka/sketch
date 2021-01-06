/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____  
 * / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \ 
 *| |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
 * \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
 *                  (____/ 
 *In this sketch, we will make a heart blink on the 8×8 LED matrix.
 * Tutorial URL http://osoyoo.com/2017/07/15/arduino-lesson-8x8-led-matrix/
 * CopyRight www.osoyoo.com
 */
// 2-dimensional array of row pin numbers:
int C[] = {2,7,A3,5,13,A2,12,A0};  
// 2-dimensional array of column pin numbers:
int R[] = {6,11,10,3,A1,4,8,9};    
  
unsigned char biglove[8][8] =     //the big "heart"   
{  
  0,0,0,0,0,0,0,0,  
  0,1,1,0,0,1,1,0,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  0,1,1,1,1,1,1,0,  
  0,0,1,1,1,1,0,0,  
  0,0,0,1,1,0,0,0,  
};  

unsigned char biglove2[8][8] =     //the big "heart"   
{    
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
};  

unsigned char biglove3[8][8] =     //the big "heart"   
{    
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,  
};  
  
unsigned char smalllove[8][8] =      //the small "heart" 
{  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,1,0,0,1,0,0,  
  0,1,1,1,1,1,1,0,  
  0,1,1,1,1,1,1,0,  
  0,0,1,1,1,1,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,0,0,0,0,0,  
};  
  
void setup()  
{  
   // iterate over the pins:
  for(int i = 0;i<8;i++)  
  // initialize the output pins:
  {  
    pinMode(R[i],OUTPUT);  
    pinMode(C[i],OUTPUT);  
  }  

  //=====================================================
  for(int i = 0; i < 8; i++) {
    for (int u = 0; u < 8; u++) {
      biglove3[i][u] = 1;
      //Display(biglove3);
      //delay(100);
      for(int y = 0; y < 10; y++) Display(biglove3);
    }
  }
  for(int i = 0; i < 8; i++) {
    for (int u = 0; u < 8; u++) {
      biglove3[i][u] = 0;
      //Display(biglove3);
      //delay(100);
      for(int y = 0; y < 10; y++) Display(biglove3);
    }
  }
}  
  
void loop()  
{  
  biglove3[rand()%8][rand()%8] = rand()%2;
  Display(biglove3);
  //=====================================================
  /*for(int i = 0; i < 8; i++) {
    for (int u = 0; u < 8; u++) {
      biglove3[i][u] = rand()%2;
      //Display(biglove3);
      //delay(100);
      //for(int y = 0; y < 10; y++) 
      Display(biglove3);
    }
  }*/
  //=====================================================
  //Display(biglove3);
  /*for(int i = 0; i < 8; i++) {
    for (int u = 0; u < 8; u++) {
      biglove3[i][u] = 1;
      //Display(biglove3);
      //delay(100);
      for(int y = 0; y < 10; y++) Display(biglove3);
    }
  }
  for(int i = 0; i < 8; i++) {
    for (int u = 0; u < 8; u++) {
      biglove3[i][u] = 0;
      //Display(biglove3);
      //delay(100);
      for(int y = 0; y < 10; y++) Display(biglove3);
    }
  }*/
  //=====================================================
  /*for(int i = 0 ; i < 100 ; i++)        //Loop display 100 times 
  {  
    Display(biglove);                   //Display the "Big Heart"  
  }  
  for(int i = 0 ; i < 50 ; i++)         //Loop display 50 times
  {     
    Display(smalllove);                 //Display the "small Heart" 
  }  */
  
}  
  
void Display(unsigned char dat[8][8])    
{  
  for(int c = 0; c<8;c++)  
  {  
    digitalWrite(C[c],LOW);//use thr column 
    //loop
    for(int r = 0;r<8;r++)  
    {  
      digitalWrite(R[r],dat[r][c]);  
    }  
    delay(1);  
    Clear();  //Remove empty display light
  }  
}  
  
void Clear()                          //清空显示  
{  
  for(int i = 0;i<8;i++)  
  {  
    digitalWrite(R[i],LOW);  
    digitalWrite(C[i],HIGH);  
  }  
}  
