/*
 * GY273.h
 *
 *  Created on: 7 Jul 2015
 *      Author: kilian
 */

#ifndef SENSORS_GY273_H_
#define SENSORS_GY273_H_

#include "I2CDevice.h"
#include <stdint.h>

#define BUFFER_SIZE 0x40


class GY273:protected I2CDevice {
private:
	unsigned int I2CBus, I2CAddress;
	unsigned char *registers;
	short magX, magY, magZ; // raw 2's complement values
	float heading, headingDeg;
	short combineRegisters(unsigned char msb, unsigned char lsb);
public:
	GY273(unsigned int I2CBus, unsigned int I2CAddress);

	virtual int readSensorState();

	uint16_t mode;

	void SetScale(uint16_t scale);
	virtual void SetOrientation(uint16_t orientation);
	virtual void SetSamplingMode(uint16_t sampling_mode);

	virtual short getMagX() { return magX; }
	virtual short getMagY() { return magY; }
	virtual short getMagZ() { return magZ; }
	virtual float getHeading() { return heading; }
	virtual float getHeadingDeg() { return headingDeg; }
	
	virtual ~GY273();
};

#endif /* SENSORS_GY273_H_ */
