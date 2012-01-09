/*
 * TCanon.cpp
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#include "TCanon.h"

#define ESCALADOXY   7
#define ESCALADOZ    10
#define TRASLACIONZ  0.05

TCanon::TCanon(const Canon *canon, TCajaCanon *tcaja)
	:EstrategiaTransformacion()
{
	this->canon = canon;
	this->tcaja = tcaja;
}

void TCanon::ejecutar()
{
	tcaja->ejecutar();
	glRotatef(this->canon->getAngH(), 0.0, 0.0, 1.0);
	glRotatef(-90.0 + this->canon->getAngV(), 0.0, 1.0, 0.0);
	glScalef(ESCALADOXY, ESCALADOXY, ESCALADOZ);
	glTranslatef(0.0, 0.0, TRASLACIONZ);
}

void TCanon::getTPto ( const float x, const float y, const float z, float &fx, float &fy, float &fz ) const
{
	float xaux, yaux, zaux;

	// traslacion
	zaux = z + TRASLACIONZ;

	// escalado
	xaux = ESCALADOXY * x;
	yaux = ESCALADOXY * y;
	zaux *= ESCALADOZ;

	// rotacion
	xaux = - Matematica::sinHex(-90.0 + this->canon->getAngV()) * xaux + Matematica::cosHex(-90.0 + this->canon->getAngV()) * zaux;
	zaux = Matematica::cosHex(-90.0 + this->canon->getAngV()) * xaux + Matematica::sinHex(-90.0 + this->canon->getAngV()) * zaux;
//	z += TRASLACIONZ;
//	z += (TRASLACIONZ * ESCALADOZ) * Matematica::sinHex( -90.0 + this->canon->getAngulo() )
//		+ (TRASLACIONZ * ESCALADOZ) * Matematica::cosHex( -90.0 + this->canon->getAngulo() );

	tcaja->getTPto( xaux, yaux, zaux, fx, fy, fz );
}

TCanon::~TCanon() {}

float TCanon::getAnguloCanon() const
{
	return this->canon->getAngV();
}
#undef TRASLACIONZ
#undef ESCALADOXY
#undef ESCALADOZ
