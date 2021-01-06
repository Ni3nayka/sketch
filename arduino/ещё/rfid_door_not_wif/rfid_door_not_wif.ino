/*Alex Kuznetsov  
 * ************************************************************
 * http://vk.com/a2kuz
 * Канал Ютуб http://youtube.com/a2kuz
 * Скетчи, проекты ардуино , по всем вопросам писать в группу
 * http://vk.com/arduino_ekb
****************************************************************/
    #include <SPI.h>
    #include <MFRC522.h>
    #define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF}
    #define SS_PIN 10
    #define RST_PIN 9
    #define DD 4 // Pin D4 --> выход на реле
    #define ZZ 5 // Pin D4 --> выход на активный зумер
    #define REL DD // REL - открывает дверь
    MFRC522 mfrc522(SS_PIN, RST_PIN);        // MFRC522
    MFRC522::MIFARE_Key key;

    // готовим массив карт с флагами доступа 0-нет доступа, 1-естьдоступ (спец пропуска)
    struct Cards { 
      String id;
      int flag;
    };
    struct Cards cards[8] ={{"2037128757",1},{"543869824",1},{"2245597766",0},{"20371287",1},{"4067496491",1},{"1645645646",1}};// записываем наши карты, если хотим временно закрыть доступ то можно или удалить карту или поставить 0
boolean work=false;
unsigned int CUR_TIME;
unsigned int ALL_TIME;

void setup(void)
{

    while (!Serial);           // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();               // Init SPI bus
    mfrc522.PCD_Init();        // Init MFRC522 card
  
    pinMode(4,OUTPUT);
    digitalWrite(4,HIGH);
    pinMode(5,OUTPUT);
    digitalWrite(5,LOW);
    Serial.begin(115200);
    Serial.print("setup begin\r\n");
}
void loop(void)
{
  ALL_TIME=(millis()/1000);
  if ((ALL_TIME - CUR_TIME)>=5){
     work=true;
     work=false;
     CUR_TIME=ALL_TIME;
    }  
    if (work==false){
          work=true;
       //------------------------РАБОТАЕМ СО СЧИТЫВАТЕЛЕМ КАРТ----------------------------
       // Look for new cards, and select one if present
            if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
                delay(50);
                work=false;
                return;
            }
    
            String UID = dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
         //   mfrc522.PICC_HaltA();
    
            Serial.print(F("Card UID: "));
            Serial.print(UID);
            Serial.println();
            
    //----------------------------------открытие дверей по спец пропускам--------------------------------
        if (UID!=""){
              for (int i = 0; i <= 7; i++) {
                    if (cards[i].id==UID && cards[i].flag==1) {
                      DoorOpen(UID);
                      work=false;
                      return;
                    }
              }
              
          }
    }
    work=false;
} //это конец LOOPа
//------------------------выуживаем UID из карты как числовое значение----------------------------

String dump_byte_array(byte *buffer, byte bufferSize) {
 //   String s;
    unsigned long uiddec = 0;
//    unsigned long temp;
    char uid[8];
    for (byte m = (bufferSize > 4 ? (bufferSize - 4) : 0); m < bufferSize; m++) { //берем только последние 4 байта и переводим в десятичную систему
        unsigned long p = 1;
        for(int k = 0; k < bufferSize-m-1; k++) {
          p = p*256;
        }
        uiddec += p*buffer[m];
     //   s = s + (buffer[m] < 0x10 ? "0" : "");
     //   s = s + String(buffer[m], HEX);
    }
//    s.toCharArray(uid, 8);    
    return String(uiddec);
}

//-----------открытие двери
void DoorOpen(String uid){
    Serial.print(F("DOOR-OPEN!"));
    Serial.println();
    digitalWrite( REL, LOW );
    for (int i = 0; i <= 6; i++) {
          digitalWrite( ZZ, HIGH ); delay(250);digitalWrite( ZZ, LOW );delay(250);
          digitalWrite( ZZ, HIGH ); delay(250);digitalWrite( ZZ, LOW );delay(250);
       }
     digitalWrite( REL, HIGH );
}
