
/***************************************************************************
  This is a library for the BME280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution

  Script by Cloud Dark
  djedan.blogspot.com

  https://forum.arduino.cc/index.php?topic=451402.0
VCC --> 3V
GND --> GND
SCK/SCL --> 13 PIN
SDA/SDI --> 11 PIN
CSB --> 10 PIN
SDO --> 12 PIN
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13//  SCK to Pin 13
#define BME_MISO 12// SDO to Pin 12
#define BME_MOSI 11// SDI to Pin 11
#define BME_CS 10//   CS  to Pin 10

#define SEALEVELPRESSURE_HPA (1013.25)

//Adafruit_BME280 bme; // I2C
Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);

void setup() {
  Serial.begin(9600);
  Serial.println(F("My weather station"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature() * 9 / 5 - 32); // (reads in C) C * 9/5 + 32 to convert to "F"
  Serial.println(" *C");

  Serial.print("Pressure = ");

  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  //    Serial.print("Approx. Altitude = ");
  //    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA)+4);//   +4 to correct altitude
  //    Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" % ");

  Serial.println();
  delay(2000);
}
