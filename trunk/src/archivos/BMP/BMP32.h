/*
 * BMP.h
 *
 *  Created on: 30/05/2011
 *      Author: Amalia
 */

#ifndef BMP32_H_
#define BMP32_H_

using namespace std;

#include "BMP.h"
#include "PixelRGBA.h"

class BMP32: public BMP {
public:
	BMP32( string nombreArchivo );
	virtual ~BMP32();

protected:

	void cargar( );
};

#endif /* BMP_H_ */
