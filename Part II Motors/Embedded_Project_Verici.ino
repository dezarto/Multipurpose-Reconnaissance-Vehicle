// Transmitter Module

//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9

#define CE_PIN 8
#define CSN_PIN 7

#define yPosition A1 // yPosition Analog port
#define xPosition A0 // xPosition Analog port
#define swJoistic 2 // Joistic pus button port
#define ledButtons 4 // Led port

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
//create an RF24 object
RF24 radio(CE_PIN, CSN_PIN);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "11100";
int datas[4];

void setup()
{
 Serial.begin(9600); 
  radio.begin(); // starting connection
  
  pinMode(yPosition, INPUT);
  pinMode(xPosition, INPUT);
  pinMode(swJoistic, INPUT_PULLUP);
  pinMode(ledButtons, INPUT);

  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  //set the address
  radio.openWritingPipe(address);
}

void loop()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  //to find card uid go to the serial moniter, scan your card and copy uid into the section
  if (content.substring(1) == "13 C0 2B AD")
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(2000);
    while(1){
      // write datas
      datas[0] = analogRead(xPosition);
      datas[1] = analogRead(yPosition);
      datas[2] = digitalRead(swJoistic);
      datas[3] = digitalRead(ledButtons);
      
      Serial.print("X Position: ");
      Serial.print(datas[0]);
      Serial.print(" | Y Position: ");
      Serial.print(datas[1]);
      Serial.print(" | Button state: ");
      Serial.print(datas[2]);
      Serial.print(" | Light buton: ");
      Serial.print(datas[3]);
      Serial.println("  ");

      radio.write( datas, sizeof(datas) ); //We print the data to the output to be sent
    }
  }
 else   {
  Serial.println(" Access denied");
  delay(2000);
  }
delay(500);
}