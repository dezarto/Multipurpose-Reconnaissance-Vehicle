// Recever Module

//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <LiquidCrystal.h>

#define CE_PIN 9
#define CSN_PIN 8
#define BUZZER 10

// We defined for variables coming from the array
#define KEY1 0
#define KEY2 0
#define KEY3 0
#define KEY4 0
#define KEY5 0
#define KEY6 0
#define KEY7 0

// create an RF24 object
RF24 radio(CE_PIN, CSN_PIN);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "11111";

int datas[] = { KEY1, KEY2, KEY3, KEY4, KEY5, KEY6, KEY7 };

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  while (!Serial);
  Serial.begin(9600);
  Serial.println("Nrf24L01 Receiver Initializing");
  radio.begin();

  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();

  lcd.begin(16, 2);
  lcd.print("System Starting"); // print to lcd screen
  delay(300);
  lcd.setCursor(0, 1);
  lcd.print("Lisining to signal...");
}

void loop()
{
  digitalWrite(BUZZER, LOW);
  lcd.cursor();
  lcd.blink();
  // if radio signal available
  if (radio.available())
  {
    lcd.setCursor(0, 0);
    lcd.print("connection good");
    lcd.setCursor(0, 1);
    lcd.print("data coming...");
    // reading data from the radio
    radio.read(datas, sizeof(datas));

    Serial.print("LDR Value:");
    Serial.println(datas[0]);

    Serial.print("WATER Value:");
    Serial.println(datas[1]);

    Serial.print("Humidity Value:");
    Serial.println(datas[3]);

    Serial.print("Temperature Value:");
    Serial.println(datas[2]);

    Serial.print("MQ-3 Value:");
    Serial.println(datas[4]);

    Serial.print("SOIL Value:");
    Serial.println(datas[5]);

    Serial.print("Motion Value:");
    Serial.println(datas[6]);
    // if motion detect
    if(datas[6] == 1){
      digitalWrite(BUZZER, HIGH);
      delay(100);
    }
    else{
      digitalWrite(BUZZER, LOW);
    }
  }
  // if radio signal not available
  else {
    Serial.println("waiting for connection...");
    lcd.setCursor(0, 1);
    lcd.print("waiting pipe...");
    lcd.setCursor(0, 0);
    lcd.print("Lost connection");
  }
}
