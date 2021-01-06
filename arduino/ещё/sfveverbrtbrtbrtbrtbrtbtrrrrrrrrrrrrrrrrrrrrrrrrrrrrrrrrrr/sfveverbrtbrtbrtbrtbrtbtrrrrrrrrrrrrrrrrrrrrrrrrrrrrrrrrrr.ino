int vec_N[55];

int vec_M[55];

int _ABVAR_1_v = 0 ;
int _ABVAR_2_i = 0 ;
int _ABVAR_3_j = 0 ;
int _ABVAR_4_temp = 0 ;

void setup()
{
  for (int i=0;i<55;i++) vec_N[i]=0;

  for (int i=0;i<55;i++) vec_M[i]=0;

  Serial.begin(115200);


}

void loop()
{
  for(_ABVAR_1_v = 1; 
1<=54?_ABVAR_1_v <= 54:_ABVAR_1_v >= 54; 
1<=54?_ABVAR_1_v = _ABVAR_1_v + 1:_ABVAR_1_v = _ABVAR_1_v - 1)
  {
    vec_N[_ABVAR_1_v - 1] = vec_N[( _ABVAR_1_v + 1 ) - 1] ;
  }
  vec_N[55 - 1] = 	random( 850 , 950 ) ;
  for(_ABVAR_1_v = 1; 
1<=55?_ABVAR_1_v <= 55:_ABVAR_1_v >= 55; 
1<=55?_ABVAR_1_v = _ABVAR_1_v + 1:_ABVAR_1_v = _ABVAR_1_v - 1)
  {
    vec_M[_ABVAR_1_v - 1] = vec_N[_ABVAR_1_v - 1] ;
  }
  for(_ABVAR_2_i = 1; 
1<=55?_ABVAR_2_i <= 55:_ABVAR_2_i >= 55; 
1<=55?_ABVAR_2_i = _ABVAR_2_i + 1:_ABVAR_2_i = _ABVAR_2_i - 1)
  {
    for(_ABVAR_3_j = 1; 
1<=54?_ABVAR_3_j <= 54:_ABVAR_3_j >= 54; 
1<=54?_ABVAR_3_j = _ABVAR_3_j + 1:_ABVAR_3_j = _ABVAR_3_j - 1)
    {
      if (( ( vec_M[_ABVAR_3_j - 1] ) > ( vec_M[( _ABVAR_3_j + 1 ) - 1] ) ))
      {
        _ABVAR_4_temp = vec_M[_ABVAR_3_j - 1] ;
        vec_M[_ABVAR_3_j - 1] = vec_M[( _ABVAR_3_j + 1 ) - 1] ;
        vec_M[( _ABVAR_3_j + 1 ) - 1] = _ABVAR_4_temp ;
      }
    }
  }
  for(_ABVAR_3_j = 1; 
1<=15?_ABVAR_3_j <= 15:_ABVAR_3_j >= 15; 
1<=15?_ABVAR_3_j = _ABVAR_3_j + 1:_ABVAR_3_j = _ABVAR_3_j - 1)
  {
    Serial.print("_");
    Serial.print(vec_N[_ABVAR_3_j - 1]);
  }
  Serial.println();
  for(_ABVAR_3_j = 1; 
1<=15?_ABVAR_3_j <= 15:_ABVAR_3_j >= 15; 
1<=15?_ABVAR_3_j = _ABVAR_3_j + 1:_ABVAR_3_j = _ABVAR_3_j - 1)
  {
    Serial.print("_");
    Serial.print(vec_M[_ABVAR_3_j - 1]);
  }
  Serial.println();
  Serial.print("_");
  Serial.print(vec_M[27 - 1]);
  Serial.println();
}


