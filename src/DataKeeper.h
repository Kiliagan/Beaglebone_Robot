/*
 * DataKeeper.h
 *
 *  Created on: 10 Jul 2015
 *      Author: kilian
 */

#ifndef DATAKEEPER_H_
#define DATAKEEPER_H_

#include <string>

class DataKeeper {
private:
	int currentX, currentY, destX, destY;
	float irDistance;
	float gyroAccelX, gyroAccelY, gyroAccelZ, gyroRoll, gyroPitch;
	float accelAccelX, accelAccelY, accelAccelZ, accelGyroX, accelGyroY, accelGyroZ, accelPitch, accelRoll, accelYaw;
	float magX, magY, magZ, angX, angY, angZ, heading, headingDeg;
	std::string path;
public:
	DataKeeper();

	virtual void setIRDistance(float irDistance);
	virtual float getIRDistance(){return irDistance;}

	virtual void setGyroAccelX( float gyroAccelX);
	virtual float getGyroAccelX(){return gyroAccelX;}
	virtual void setGyroAccelY( float gyroAccelY);
	virtual float getGyroAccelY(){return gyroAccelY;}
	virtual void setGyroAccelZ( float gyroAccelZ);
	virtual float getGyroAccelZ(){return gyroAccelZ;}
	virtual void setGyroRoll(float gyroRoll);
	virtual float getGyroRoll(){return gyroRoll;}
	virtual void setGyroPitch(float gyroPitch);
	virtual float getGyroPitch(){return gyroPitch;}

	virtual void setAccelAccelX( float accelAccelX);
	virtual float getAccelAccelX(){return accelAccelX;}
	virtual void setAccelAccelY( float accelAccelY);
	virtual float getAccelAccelY(){return accelAccelY;}
	virtual void setAccelAccelZ( float accelAccelZ);
	virtual float getAccelAccelZ(){return accelAccelZ;}
	virtual void setAccelGyroX( float accelGyroX);
	virtual float getAccelGyroX(){return accelGyroX;}
	virtual void setAccelGyroY( float accelGyroY);
	virtual float getAccelGyroY(){return accelGyroY;}
	virtual void setAccelGyroZ( float accelGyroZ);
	virtual float getAccelGyroZ(){return accelGyroZ;}
	virtual void setAccelRoll(float accelRoll);
	virtual float getAccelRoll(){return accelRoll;}
	virtual void setAccelPitch(float accelPitch);
	virtual float getAccelPitch(){return accelPitch;}
	virtual void setAccelYaw(float accelYaw);
	virtual float getAccelYaw(){return accelYaw;}

	virtual void setMagX( float magX);
	virtual float getMagX(){return magX;}
	virtual void setMagY( float magY);
	virtual float getMagY(){return magY;}
	virtual void setMagZ( float magZ);
	virtual float getMagZ(){return magZ;}
	virtual void setAngX( float angX);
	virtual float getAngX(){return angX;}
	virtual void setAngY( float angY);
	virtual float getAngY(){return angY;}
	virtual void setAngZ( float angZ);
	virtual float getAngZ(){return angZ;}
	virtual void setHeading( float heading);
	virtual float getHeading(){return heading;}
	virtual void setHeadingDeg( float headingDeg);
	virtual float getHeadingDeg(){return headingDeg;}

	virtual void setPath(std::string path);
	virtual std::string getPath(){return path;}

	virtual void setCurrentX(int currentX);
	virtual int getCurrentX(){return currentX;}

	virtual void setCurrentY(int currentY);
	virtual int getCurrentY(){return currentY;}

	virtual void setDestX(int destX);
	virtual int getDestX(){return destX;}

	virtual void setDestY(int destY);
	virtual int getDestY(){return destY;}

	virtual ~DataKeeper();
};

#endif /* DATAKEEPER_H_ */
