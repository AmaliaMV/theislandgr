/*
 * Pixel.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef PIXEL_H_
#define PIXEL_H_

#include "BMPCABECERA.h"
class Pixel {
public:
	Pixel( unsigned int cantColor );
	virtual unsigned int getCantColores();
	virtual BYTE1* getColor() = 0;
	virtual ~Pixel();

private:
	unsigned int cantColor;
};

#endif /* PIXEL_H_ */
