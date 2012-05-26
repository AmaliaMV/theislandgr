/*
 * BMP.h
 *
 *  Created on: 30/05/2011
 *      Author: Amalia
 */

#ifndef BMP24_H_
#define BMP24_H_

using namespace std;

#include "BMP.h"
#include "PixelRGB.h"

class BMP24: public BMP {
public:
	BMP24( string nombreArchivo );
	virtual ~BMP24();

protected:

	void cargar( );
};

#endif /* BMP_H_ */
