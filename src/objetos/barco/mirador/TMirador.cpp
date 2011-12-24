/*
 * TMirador.cpp
 *
 *  Created on: 24/12/2011
 *      Author: amalia
 */

#include "TMirador.h"

TMirador::TMirador():EstrategiaTransformacion() {}

TMirador::~TMirador() {}

void TMirador::ejecutar()
{
	glTranslatef(0.0, 0.0, 30.0);
}
