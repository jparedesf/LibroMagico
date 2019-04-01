
//Importacion de librerias
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522

void setup() {
  Serial.begin(9600); //Iniciamos la comunicación  serial
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos  el MFRC522
}

//proceso que se ejecutara de manera continua
void loop() {
  //se comprueba de que haya conectada un lector RFID al arduino
  if ( ! mfrc522.PICC_IsNewCardPresent())
        return;
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;
    //llama al método para leer el codigo de la tarjeta RFID
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
}

//método que lee el codigo de la tarjeta RFID y lo muestra por el cable serial
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? "0" : "");
        Serial.print(buffer[i], HEX);
    }
    Serial.println();
   
  
}
