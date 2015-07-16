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
#define CONFIG_A 	0x00
#define CONFIG_B 	0x01
#define MODE		0x02
#define DATA_OUT_X_H	0x03
#define DATA_OUT_X_L	0x04
#define DATA_OUT_Z_H	0x05
#define DATA_OUT_Z_L	0x06
#define DATA_OUT_Y_H	0x07
#define DATA_OUT_Y_L	0x08
#define STATUS		0x09
#define ID_A		0x10
#define ID_B		0x11
#define ID_C		0x12

static float _hmc5883_Gauss_LSB_XY = 1100.0F;
static float _hmc5883_Gauss_LSB_Z = 980.0F;
/**
 *
 * @param msb
 * @param lsb
 */
short GY273::combineRegisters(unsigned char msb, unsigned char lsb){
   //shift the MSB left by 8 bits and OR with LSB
   return ((short)msb<<8)|(short)lsb;
}

void GY273::setGain(){
	writeRegister(CONFIG_B, 0x20);
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
	this->angX = 0;
	this->angY = 0;
	this->angZ = 0;
	this->offX = 250;
	this->offY = 317;
	this->heading = 0;
	this->headingDeg = 0;
	this->registers = NULL;
	this->writeRegister(MODE, 0x00);
//	this->setGain();
}

int GY273::selfTest(){

	this->writeRegister(CONFIG_A, 0xF1);
	this->writeRegister(MODE, 0x01);

	this->readSensorState();
	this->readSensorState();

	this->writeRegister(CONFIG_A, 0xF0);
	this->writeRegister(MODE, 0x00);

	return 0;
}

/**
 *
 * @return
 */
int GY273::readSensorState(){
	this->registers = this->readRegisters(BUFFER_SIZE, 0x00);
	
	this->magX = this->combineRegisters(*(registers+DATA_OUT_X_H), *(registers+DATA_OUT_X_L));
	this->magY = this->combineRegisters(*(registers+DATA_OUT_Y_H), *(registers+DATA_OUT_Y_L));
	this->magZ = this->combineRegisters(*(registers+DATA_OUT_Z_H), *(registers+DATA_OUT_Z_L));
	
	this->magX += this->offX;
	this->magY += this->offY;

	this->angX = this->magX / _hmc5883_Gauss_LSB_XY * GAUSS_TO_MICROTESLA;
	this->angY = this->magY / _hmc5883_Gauss_LSB_XY * GAUSS_TO_MICROTESLA;
	this->angZ = this->magZ / _hmc5883_Gauss_LSB_Z * GAUSS_TO_MICROTESLA;

	this->heading = magZ * atan((this->magY * this->magY) / (this->magX * this->magX));
	this->headingDeg = angZ * atan((this->angY * this->angY) / (this->angX * this->angX));

	return 0;
}

/**
 *
 */
GY273::~GY273() {
}

