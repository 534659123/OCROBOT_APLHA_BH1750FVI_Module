#ifndef BH1750FVI_H_
#define BH1750FVI_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef WIRE_H_
#define WIRE_H_
#include <Wire.h>
#endif

class BH1750FVI
{
	public:
		void begin(byte addr);
		uint16_t Illumination();
		byte _ADDR = 0;
			
	private:
		 
};

#endif