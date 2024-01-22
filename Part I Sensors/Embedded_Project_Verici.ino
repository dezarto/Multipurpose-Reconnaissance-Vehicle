// Transmitter Module

//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "DHT.h"

#define CE_PIN 9 
#define CSN_PIN 8

#define LDR A0 // Analog LDR port
#define WATER A1 // Analog WATER SENSOR port
#define DHTPIN 2 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11
#define MQ 3 // MQ-3 port 
#define SOIL A2 // SOIL SENSOR port
#define MOTION 4 // Motion Sensor port

DHT dht(DHTPIN, DHTTYPE);

//create an RF24 object
RF24 radio(CE_PIN, CSN_PIN);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "111111";

int datas[7];
int ldrValue, waterValue, mq3Value, soilValue, motionValue;
float h, t, f, hif, hic;

void setup()
{
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  // begin port 9600 serial port
  while (!Serial);
    Serial.begin(9600);
  
  dht.begin();
  pinMode(MQ, INPUT);
  pinMode(MOTION, INPUT);
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{
  // LDR Start----------
  ldrValue = analogRead(A0);
  datas[0] = analogRead(LDR);
  Serial.print("LDR Value:");
  Serial.println(ldrValue);
  // LDR End----------

  // WATER Start----------
  waterValue = analogRead(A1);
  datas[1] = analogRead(WATER);
  Serial.print("WATER Value:");
  Serial.println(waterValue);
  // WATER End----------

  // --------- DHT Start ---------
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
  }
  

  // Compute heat index in Fahrenheit (the default)
  hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  hic = dht.computeHeatIndex(t, h, false);
  datas[2] = t;
  datas[3] = h;

  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(F("Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));
  // --------- DHT End -----------

  // --------- MQ-3 Start -----------
  mq3Value = digitalRead(MQ);
  datas[4] = mq3Value;
  Serial.print("MQ-3 Value: ");
  Serial.println(mq3Value);
  // --------- MQ-3 End -----------

  // --------- SOIL Start -----------
  soilValue = analogRead(SOIL);
  datas[5] = soilValue;
  Serial.print("SOIL Value: ");
  Serial.println(soilValue);
  // --------- SOIL End -----------

  // --------- Motion Start -----------
  motionValue = digitalRead(MOTION);
  datas[6] = motionValue;
  Serial.print("Motion Value: ");
  Serial.println(motionValue);
  // --------- Motion End -----------

  // Send data via radio
  radio.write(datas, sizeof(datas));

  //delay(1);
}