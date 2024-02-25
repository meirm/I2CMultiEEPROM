/*
  I2CMultiEEPROM.h - Library for internal usage.
  Created by Meir Michanie, April 2011.
  Released into the public domain.
  Version 0.1
*/

#ifndef I2CMultiEEPROM_h
#define I2CMultiEEPROM_h
#include <Wire.h>    
 // Arduino version compatibility Pre-Compiler Directives
//#include<arduino.h>
#include<Arduino.h>
#if defined(ARDUINO) && ARDUINO >= 100   // Arduino v1.0 and newer
  #define I2C_WRITE Wire.write 
  #define I2C_READ Wire.read
#else                                   // Arduino Prior to v1.0 
  #define I2C_WRITE Wire.send 
  #define I2C_READ Wire.receive
#endif
class I2CMultiEEPROM
{
 public:
	I2CMultiEEPROM(int internalEepromSize, int eepromSize, int * eepromvector);
	void XWrite (unsigned int address,byte Data);
	byte XRead (unsigned int address);

	
	int version();
 private:
	void writeEEPROM(int Disk, unsigned int address, byte Data );
	byte readEEPROM( int Disk, unsigned int address );
	int _eepromSize;
	int _internalEepromSize;
	int * _eepromvector;
};


#endif
