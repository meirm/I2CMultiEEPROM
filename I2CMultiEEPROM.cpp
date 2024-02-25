/*
  I2CMultiEEPROM.cpp - Library for internal use.
  Created by Meir Michanie, February 2013.
  Released into the public domain.
*/

#include <EEPROM.h>
#include "I2CMultiEEPROM.h"

I2CMultiEEPROM::I2CMultiEEPROM(int internalEepromSize, int eepromSize,  int * eepromvector){
 	 _internalEepromSize = internalEepromSize;
	 _eepromSize=eepromSize;
	 _eepromvector=eepromvector;
	Wire.begin();
 }


// Version number of this class.
int I2CMultiEEPROM::version(){
	return 1;
}

// Public command, imitates the built-in digitalWrite command. 
// It calculates the multiplexer from where to read from and the pin of the multiplexer 
// 
void I2CMultiEEPROM::XWrite (unsigned int address, byte Data){
   if (address < _internalEepromSize){
	EEPROM.write(address, Data);
	}else{
		address -= _internalEepromSize;
 		I2CMultiEEPROM::writeEEPROM(int (address/_eepromSize), address % _eepromSize, Data);
  }
}


// Public command, imitates the built-in digitalRead command. 
// It calculates the multiplexer from where to read from and the pin of the multiplexer 
// returns true or false (1 or 0)
byte I2CMultiEEPROM::XRead (unsigned int address){
	if (address < _internalEepromSize){
		return EEPROM.read(address);
	}else{
		address -= _internalEepromSize;
   		return  I2CMultiEEPROM::readEEPROM(int (address/_eepromSize), address % _eepromSize) ;
  }
}


void I2CMultiEEPROM::writeEEPROM(int Disk, unsigned int address, byte Data ) 
{
  Wire.beginTransmission(_eepromvector[Disk]);
  I2C_WRITE((int)(address >> 8));   // MSB
  I2C_WRITE((int)(address & 0xFF)); // LSB
  I2C_WRITE(Data);
  Wire.endTransmission();
  delay(5);
}
 
byte I2CMultiEEPROM::readEEPROM( int Disk, unsigned int address ){
  byte rData = 0xFF;
  Wire.beginTransmission(_eepromvector[Disk]);
  I2C_WRITE((int)(address >> 8));   // MSB
  I2C_WRITE((int)(address & 0xFF)); // LSB
  Wire.endTransmission();
 
  Wire.requestFrom(_eepromvector[Disk],1);
 
  if (Wire.available()) rData = I2C_READ();
 
  return rData;
}

