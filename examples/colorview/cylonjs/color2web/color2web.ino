#include <Wire.h>
#include "Adafruit_TCS34725.h"
#define PIN 10

// our RGB -> eye-recognized gamma color
byte gammatable[256];


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);

  if (tcs.begin())
    Serial.println("Found sensor");
  else
    Serial.println("No TCS34725 found ... check your connections"); while (1); // halt!
}


void loop() {

  uint16_t clear, red, green, blue;
  tcs.setInterrupt(false);      // turn on LED
  
  delay(50);  // takes 50ms to read 

  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);  // turn off LED

green=constrain(green,1100,20000);  green=map(green,1100,20000,0,255);
blue=constrain(blue,1500,20000);  blue=map(blue,1500,20000,0,255);
red=constrain(red,1500,20000);  red=map(red,1500,20000,0,255);
}


/*
  // Figure out some basic hex code for visualization
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
  Serial.print("\t");
  Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
  Serial.println();
*/
  //Serial.print((int)r ); Serial.print(" "); Serial.print((int)g);Serial.print(" ");  Serial.println((int)b );
  