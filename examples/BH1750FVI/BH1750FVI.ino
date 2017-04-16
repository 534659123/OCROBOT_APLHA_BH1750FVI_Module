#include <BH1750FVI.h>
BH1750FVI light;

byte Addr =0x23;  //LOW
//byte addr =0x5c;  //HIGH
void setup() {
  Wire.begin();
  light.begin(Addr);
  Serial.begin(9600);


}

void loop() {
  uint16_t date = light.Illumination();
  Serial.println(date);

}