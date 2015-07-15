/*
 * IR2Y0A21.h
 *
 *  Created on: 6 Jul 2015
 *      Author: kilian
 */

#ifndef SENSORS_IR2Y0A21_H_
#define SENSORS_IR2Y0A21_H_

class IR2Y0A21 {
public:
	IR2Y0A21();
	virtual ~IR2Y0A21();
	virtual int readAnalogue();
	virtual float getDistanceRAW();
	virtual float getDistance();
};

#endif /* SENSORS_IR2Y0A21_H_ */
