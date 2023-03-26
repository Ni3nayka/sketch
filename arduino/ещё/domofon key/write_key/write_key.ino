#include <OneWire.h>  // подключаем библиотеку
const int pin = 10;   // объявляем номер пина
OneWire iButton(pin); // объявляем объект OneWire на 10-ом пине

// номер ключа, который мы хотим записать в iButton:
// byte key_to_write[] = { 0x01, 0xF6, 0x75, 0xD7, 0x0F, 0x00, 0x00, 0x9A }; 
byte key_to_write[] = { 0x89, 0x80, 0x0A, 0x70, 0x09, 0x00, 0x50, 0xF1};

void setup(void) { 
  Serial.begin(9600); 
  pinMode(pin, OUTPUT);  
}

void loop(void) {
  delay(1000); // задержка на 1 сек  
  iButton.reset(); // сброс устройства 1-wire
  delay(50); 
  iButton.write(0x33); // отправляем команду "чтение"

  byte data[8]; // массив для хранения данных ключа
  iButton.read_bytes(data, 8); // считываем данные приложенного ключа, 8х8=64 бита
  
  if ( OneWire::crc8(data, 7) != data[7] ) { // проверяем контрольную сумму приложенного ключа
      Serial.println("CRC error!"); // если CRC не верна, сообщаем об этом
      return; // и прерываем программу
  }

  if (data[0] & data[1] & data[2] & data[3] & data[4] & data[5] & data[6] & data[7] == 0xFF) {
    return; // если ключ не приложен к считывателю, прерываем программу и ждём, пока будет приложен
  }

  Serial.print("Start programming..."); // начало процесса записи данных в ключ
  
//  for (int i = 0; i < 8; i++) {
//    // формирование 4-х байт для записи в ключ - см. рис.4 из datasheet для подробностей
//    iButton.reset(); // сброс ключа 
//    data[0] = 0x3C; // отправляем команду "копировать из буфера в ПЗУ"
//    data[1] = i; // указываем байт для записи
//    data[2] = 0;
//    data[3] = key_to_write[i]; 
//    iButton.write_bytes(data, 4); // записываем i-ый байт в ключ
//  
//    uint8_t b = iButton.read(); // считываем байт из ключа
//    
//    if (OneWire::crc8(data, 4) != b) { // при ошибке контрольной суммы
//        Serial.println("Error while programming!"); // сообщаем об этом
//        return; // и отменяем запись ключа
//    }
//    send_programming_impulse(); // если всё хорошо, посылаем импульс для записи i-го байта в ключ
//  }
//  Serial.println("Success!"); // сообщение об успешной записи данных в ключ  

delay (200);
iButton.skip();
iButton.reset();
iButton.write(0x33); // чтение текущего номера ключа
Serial.print("ID before write:");
for (byte i=0; i<8; i++){
  Serial.print(' ');
  Serial.print(iButton.read(), HEX);
}    
Serial.print("\n");

iButton.skip();
iButton.reset();
iButton.write(0xD1); // команда разрешения записи
digitalWrite(pin, LOW); 
pinMode(pin, OUTPUT); 
delayMicroseconds(60);
pinMode(pin, INPUT); 
digitalWrite(pin, HIGH); 
delay(10);

// выведем ключ, который собираемся записать:
Serial.print("Writing iButton ID: ");
for (byte i=0; i<8; i++) {
  Serial.print(key_to_write[i], HEX);
  Serial.print(" ");
}
Serial.print("\n");
                 
iButton.skip();
iButton.reset();
iButton.write(0xD5); // команда записи
for (byte i=0; i<8; i++) {
  writeByte(key_to_write[i]);
  Serial.print("*");
}
Serial.print("\n");

iButton.reset();
iButton.write(0xD1); // команда выхода из режима записи
digitalWrite(pin, LOW); 
pinMode(pin, OUTPUT); 
delayMicroseconds(10);
pinMode(pin, INPUT); 
digitalWrite(pin, HIGH); 
delay(10);

Serial.println("Success!"); 
delay(10000);
}

int writeByte(byte data) {
  int data_bit;
  for(data_bit=0; data_bit<8; data_bit++) {
    if (data & 1) {
      digitalWrite(pin, LOW); 
      pinMode(pin, OUTPUT);
      delayMicroseconds(60);
      pinMode(pin, INPUT); 
      digitalWrite(pin, HIGH);
      delay(10);
    } else {
      digitalWrite(pin, LOW); 
      pinMode(pin, OUTPUT);
      pinMode(pin, INPUT); 
      digitalWrite(pin, HIGH);
      delay(10);
    }
    data = data >> 1;
  }
  return 0;
}

// Инициализация записи данных в ключ-таблетку iButton:
void send_programming_impulse() { 
  digitalWrite(pin, HIGH); 
  delay(60);
  digitalWrite(pin, LOW); 
  delay(5);
  digitalWrite(pin, HIGH); 
  delay(50); 
}
