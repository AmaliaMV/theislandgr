/*
 * TBaupres.cpp
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#include "TBaupres.h"

TBaupres::TBaupres(): EstrategiaTransformacion() {}

TBaupres::~TBaupres() {}

void TBaupres::ejecutar()
{
	glTranslatef(0.0,CteBarco::RADIO_Y,0.0);
	glScalef(50,50,25);
	glRotatef(-45, 1.0, 0.0, 0.0);
}
