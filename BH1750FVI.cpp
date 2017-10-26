#include "BH1750FVI.h"

void BH1750FVI::begin(byte addr)
{
	_ADDR = addr;
  Wire.begin();     
  Wire.beginTransmission(_ADDR);
  Wire.write(0b00000001);
  Wire.endTransmission();
	
	

}

uint16_t BH1750FVI::Illumination()
{

  uint16_t val = 0;
  delay(100);
  // reset
  Wire.beginTransmission(_ADDR);
  Wire.write(0b00000111);
  Wire.endTransmission();
 
  delay(100);
 
 
 
  Wire.beginTransmission(_ADDR);
  Wire.write(0b00100000);
  Wire.endTransmission();
 
  // typical read delay 120m
  delay(120);
 
  Wire.requestFrom((int)_ADDR, (int)2); // 2byte every time

  for (val=0; Wire.available()>=1; ) {
    char c = Wire.read();
    //Serial.println(c, HEX);
    val = (val << 8) + (c & 0xFF);
  }

 
  val = val / 1.2;
  return val;
  
}
