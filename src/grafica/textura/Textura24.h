/*
 * Textura.h
 *
 *  Created on: 30/05/2011
 *      Author: Amalia
 */

#ifndef TEXTURA24_H_
#define TEXTURA24_H_

#include "../../archivos/BMP/BMP24.h"

#include "Textura.h"

class Textura24: public Textura {
public:
	Textura24(string nombreArch); //carga en memoria la imagen
	virtual ~Textura24();
};

#endif /* TEXTURA_H_ */
