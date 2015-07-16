/*
 * GY273.h
 *
 *  Created on: 7 Jul 2015
 *      Author: kilian
 */

#ifndef SENSORS_GY273_H_
#define SENSORS_GY273_H_

#include "I2CDevice.h"

#define BUFFER_SIZE 0x40

#define GRAVITY_EARTH (9.80665F)
#define MAGFIELD_EARTH_MAX (60.0F)
#define MAGFIELD_EARTH_MIN (30.0F)
#define GAUSS_TO_MICROTESLA (100)

class GY273:protected I2CDevice {
public:
	/// An enumeration to define the gravity range of the sensor
		enum RANGE {
			PLUSMINUS_2_G 		= 0,//!< plus/minus 2g
			PLUSMINUS_4_G 		= 1,//!< plus/minus 4g
			PLUSMINUS_8_G 		= 2,//!< plus/minus 8g
			PLUSMINUS_16_G 		= 3 //!< plus/minus 16g
		};
		/// The resolution of the sensor. High is only available in +/- 16g range.
		enum RESOLUTION {
			NORMAL = 0,//!< NORMAL 10-bit resolution
			HIGH = 1   //!< HIGH 13-bit resolution
		};
private:
	unsigned int I2CBus, I2CAddress;
	unsigned char *registers;
	short magX, magY, magZ; // raw 2's complement values
	float angX, angY, angZ;
	float heading, headingDeg;
	short offX, offY;
	short combineRegisters(unsigned char msb, unsigned char lsb);
public:
	GY273(unsigned int I2CBus, unsigned int I2CAddress);

	virtual void setGain();

	virtual int readSensorState();
	
	virtual int selfTest();

	virtual short getMagX() { return magX; }
	virtual short getMagY() { return magY; }
	virtual short getMagZ() { return magZ; }
	virtual float getAngX() { return angX; }
	virtual float getAngY() { return angY; }
	virtual float getAngZ() { return angZ; }
	virtual float getHeading() { return heading; }
	virtual float getHeadingDeg() { return headingDeg; }
	
	virtual ~GY273();
};

#endif /* SENSORS_GY273_H_ */
