/*
 * MPU6050.h
 *
 *  Created on: 7 Jul 2015
 *      Author: kilian
 */

#ifndef SENSORS_MPU6050_H_
#define SENSORS_MPU6050_H_

#include "I2CDevice.h"

#define BUFFER_SIZE 0x40

class MPU6050:protected I2CDevice {
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
	MPU6050::RANGE range;
	MPU6050::RESOLUTION resolution;
	short accelerationX, accelerationY, accelerationZ; // raw 2's complement values
	short gyroX, gyroY, gyroZ;
	float pitch, roll, yaw;                                 // in degrees
	short combineRegisters(unsigned char msb, unsigned char lsb);
	void calculatePitchAndRoll();
	//virtual int updateRegisters();

public:
	MPU6050(unsigned int I2CBus, unsigned int I2CAddress=0x68);
	virtual int readSensorState();

	//virtual void setRange(MPU6050::RANGE range);
	virtual MPU6050::RANGE getRange() { return this->range; }
	//virtual void setResolution(MPU6050::RESOLUTION resolution);
	virtual MPU6050::RESOLUTION getResolution() { return this->resolution; }

	virtual short getAccelerationX() { return accelerationX; }
	virtual short getAccelerationY() { return accelerationY; }
	virtual short getAccelerationZ() { return accelerationZ; }
	virtual short getGyroX() { return gyroX; }
	virtual short getGyroY() { return gyroY; }
	virtual short getGyroZ() { return gyroZ; }
	virtual float getPitch() { return pitch; }
	virtual float getRoll() { return roll; }
	virtual float getYaw() { return yaw; }

	// Debugging method to display and update the pitch/roll on the one line
	virtual void displayPitchAndRoll(int iterations = 600);
	virtual ~MPU6050();
};

#endif /* SENSORS_MPU6050_H_ */
