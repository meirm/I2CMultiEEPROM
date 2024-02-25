# I2CMultiEEPROM Library

The I2CMultiEEPROM library is a versatile Arduino library designed for handling multiple EEPROM devices over the I2C protocol. It simplifies the process of reading from and writing to external EEPROM chips, in addition to the Arduino's internal EEPROM. This library is particularly useful for projects requiring storage beyond the capacity of the Arduino's onboard EEPROM.

## Features

- Compatibility with both newer (>=1.0) and older versions of Arduino IDE.
- Support for multiple external EEPROM devices through I2C.
- Simplified read and write operations to EEPROMs.
- Automatic handling of Arduino version differences in I2C communication methods.
- Dynamic allocation of EEPROM devices based on user configuration.

## Installation

1. Download the library as a ZIP file.
2. Open your Arduino IDE and navigate to Sketch > Include Library > Add .ZIP Library...
3. Select the downloaded ZIP file and click Open to install.
4. Once installed, you can include it in your sketch by adding `#include <I2CMultiEEPROM.h>` at the top of your Arduino script.

## Usage

To use the I2CMultiEEPROM library in your project, you first need to create an instance of the I2CMultiEEPROM class. You must specify the size of the internal EEPROM, the size of the external EEPROMs, and an array representing the EEPROM devices in your circuit.

### Example

```cpp
#include <I2CMultiEEPROM.h>

// Define the EEPROM configuration
int eepromSizes[] = {512, 512}; // Example EEPROM sizes in bytes
I2CMultiEEPROM myEEPROM(1024, 512, eepromSizes); // 1024 bytes of internal EEPROM, 512 bytes external

void setup() {
  Serial.begin(9600);
  // Write data to EEPROM
  myEEPROM.XWrite(10, 0xFF); // Write data 0xFF to address 10
}

void loop() {
  // Read data from EEPROM
  byte data = myEEPROM.XRead(10); // Read data from address 10
  Serial.println(data, HEX); // Print the data in HEX format
  delay(1000);
}
```

## API Reference

- `I2CMultiEEPROM(int internalEepromSize, int eepromSize, int* eepromvector)`: Constructor to initialize the EEPROM configuration.
- `void XWrite(unsigned int address, byte Data)`: Write a byte of data to a specified EEPROM address.
- `byte XRead(unsigned int address)`: Read a byte of data from a specified EEPROM address.
- `int version()`: Returns the library version.

## Contributing

This library is open-source and contributions are welcome. If you'd like to contribute, please fork the repository and submit a pull request.

## License

This library is released into the public domain. Feel free to use it in any of your projects.

## Acknowledgments

Created by Meir Michanie, April 2011. This library was developed to support Arduino enthusiasts in managing larger data storage requirements efficiently.
```
