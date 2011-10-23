/*
 * Textura32.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef TEXTURA32_H_
#define TEXTURA32_H_

#include "../../archivos/BMP/BMP32.h"

#include "Textura.h"

class Textura32: public Textura {
public:
	Textura32( string nombreArch );
	virtual ~Textura32();
};

#endif /* TEXTURA32_H_ */
