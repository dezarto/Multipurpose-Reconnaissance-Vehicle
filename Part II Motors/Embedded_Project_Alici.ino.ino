// Recever Module

//Include Libraries
#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 8

#define SERVO1 6 // Serveo 1 port
#define SERVO2 5 // Serveo 2 port
#define DCMOTOR 3 // DC Motor port
#define LEDS 2 // Leds port

// We defined for variables coming from the array
#define KEY1 0
#define KEY2 0
#define KEY3 0
#define KEY4 0

//create an RF24 object
RF24 radio(CE_PIN, CSN_PIN);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "11100";

int datas[] = { KEY1, KEY2, KEY3, KEY4 };
int servoValue1, servoValue2, swJoistic, ledStatus;
bool open = false; // this defined for car led

// Servo motor objects
Servo servoObje1;
Servo servoObje2;

void setup()
{
  // begin serial port 9600
  while (!Serial);
    Serial.begin(9600);
  delay(500);

  servoObje1.attach(SERVO2);
  servoObje2.attach(SERVO1);
  pinMode(DCMOTOR, OUTPUT);
  pinMode(LEDS, OUTPUT);
  //We communicate via radio
  Serial.println("Nrf24L01 Receiver Initializing...");
  radio.begin();
   //set the address
  radio.openReadingPipe(0, address);
  //Set module as receiver
  radio.startListening();
}

void loop()
{
  if (radio.available()) // if connection available
  {
    // reading data from the radio
    radio.read(datas, sizeof(datas));

    //We adapted the incoming information to a certain range
    servoValue1 = map(datas[0], 522, 1023, 0, 254);
    servoValue2 = map(datas[1], 0, 1023, 0, 179);
    swJoistic = datas[2];
    ledStatus = datas[3];

    Serial.print("xPosition: ");
    Serial.print(servoValue1);
    Serial.print(" | yPosition: ");
    Serial.print(servoValue2);
    Serial.print(" | Button state: ");
    Serial.print(swJoistic);
    // if joistic buton pressed servo moves
    if(datas[2] == 0){
      swJoistic = 180;
    }
    Serial.print(" | Light buton: ");
    Serial.print(ledStatus);
    Serial.println();
    
    //dc motor moves
    if(servoValue1 >=0 ){
      analogWrite(DCMOTOR, servoValue1);
    }

    // If the button is pressed, the car light turns on.
    // open will be true or false
    if(ledStatus == 1){
      open = !open;
      delay(400);
    }
    if(open){
      digitalWrite(LEDS, HIGH);
    }
    else{
      digitalWrite(LEDS, LOW);
    }

    // adjusting the degree of the servo motor
    servoObje1.write(swJoistic);
    servoObje2.write(servoValue2);
  }      
  else { // if connection not available
    Serial.println("waiting for connection...");
  }
}