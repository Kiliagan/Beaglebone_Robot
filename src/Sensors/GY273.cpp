/*
 * GY273.cpp
 *
 *  Created on: 7 Jul 2015
 *      Author: kilian
 */

#include "GY273.h"

#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

using namespace std;

//From Table 2, of the GY273 Data sheet
#define CONFIG_A 			0x00
#define CONFIG_B 			0x01
#define MODE				0x02
#define DATA_OUT_X_H		0x03
#define DATA_OUT_X_L		0x04
#define DATA_OUT_Z_H		0x05
#define DATA_OUT_Z_L		0x06
#define DATA_OUT_Y_H		0x07
#define DATA_OUT_Y_L		0x08
#define STATUS				0x09
#define ID_A				0x10
#define ID_B				0x11
#define ID_C				0x12

// MODE:
#define COMPASS_CONTINUOUS	0x00
#define COMPASS_SINGLE		0x01
#define COMPASS_IDLE		0x02

// SCALE:
#define COMPASS_SCALE_088	0x00 << 2
#define COMPASS_SCALE_130	0x01 << 2
#define COMPASS_SCALE_190	0x02 << 2
#define COMPASS_SCALE_250	0x03 << 2
#define COMPASS_SCALE_400	0x04 << 2
#define COMPASS_SCALE_470	0x05 << 2
#define COMPASS_SCALE_560	0x06 << 2
#define COMPASS_SCALE_810	0x07 << 2

// ORIENTATION:
#define COMPASS_NORTH		0x00
#define COMPASS_S0UTH		0x01
#define COMPASS_WEST		0x02
#define COMPASS_EAST		0x03
#define COMPASS_UP			0x04
#define COMPASS_DOWN		0x05

#define COMPASS_HORIZONTAL_X_NORTH 	( (COMPASS_NORTH << 6) | (COMPASS_WEST  << 3) | (COMPASS_UP    )) << 5
#define COMPASS_HORIZONTAL_Y_NORTH 	( (COMPASS_EAST  << 6) | (COMPASS_NORTH << 3) | (COMPASS_UP    )) << 5
#define COMPASS_VERTICAL_X_EAST		( (COMPASS_EAST  << 6) | (COMPASS_UP	<< 3) | (COMPASS_SOUTH )) << 5
#define COMPASS_VERTICAL_X_WEST		( (COMPASS_UP	 << 6) | (COMPASS_WEST	<< 3) | (COMPASS_SOUTH )) << 5

/**
 *
 * @param msb
 * @param lsb
 */
short GY273::combineRegisters(unsigned char msb, unsigned char lsb){
   //shift the MSB left by 8 bits and OR with LSB
   return ((short)msb<<8)|(short)lsb;
}

/**
 *
 * @param I2CBus
 * @param I2CAddress
 */
GY273::GY273(unsigned int I2CBus, unsigned int I2CAddress):
	I2CDevice(I2CBus, I2CAddress){   // this member initialisation list calls the parent constructor
	this->I2CAddress = I2CAddress;
	this->I2CBus = I2CBus;
	this->magX = 0;
	this->magY = 0;
	this->magZ = 0;
	this->heading = 0;
	this->headingDeg = 0;
	this->registers = NULL;
	this->writeRegister(MODE, 0x00);
	this->mode = COMPASS_CONTINUOUS | COMPASS_SCALE_130 | COMPASS_HORIZONTAL_X_NORTH;
}

void GY273::SetSamplingMode(unsigned int sampling_mode){

	this->mode = (this->mode & ~0x03) | (sampling_mode & 0x03);

	this->writeRegister(MODE, mode & 0x03);
}

void GY273::SetScale(unsigned int scale){

	mode = (mode & ~0x1C) | (scale & 0x1C);

	this->writeRegister(CONFIG_B, ((mode >> 2) & 0x07) << 5);
}

void GY273::SetOrientation(unsigned int orientation){
	mode = (mode & ~0x3FE0) | (orientation & 0x3FE0);
}

/**
 *
 * @return
 */
int GY273::readSensorState(){
	this->registers = this->readRegisters(BUFFER_SIZE, 0x00);
	
	this->magX = -1 * this->combineRegisters(*(registers+DATA_OUT_X_H), *(registers+DATA_OUT_X_L));
	this->magY = -1 * this->combineRegisters(*(registers+DATA_OUT_Y_H), *(registers+DATA_OUT_Y_L));
	this->magZ = -1 * this->combineRegisters(*(registers+DATA_OUT_Z_H), *(registers+DATA_OUT_Z_L));

	float mag_north, mag_west;

	//Z


	return 0;
}



/**
 *
 */
GY273::~GY273() {
}

