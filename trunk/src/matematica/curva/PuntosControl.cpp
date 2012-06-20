/*
 * PuntosControl.cpp
 *
 *  Created on: 25/05/2011
 *      Author: Amalia
 */

#include "PuntosControl.h"

void PuntosControl::definirPto(float pto[], const int xMouse, const int yMouse, const int xBorde, const int yBorde, const int ancho, const int alto)
{
	float x, y;

	x = (floor(((float)(xMouse - xBorde))/ancho * PRECISION)) / PRECISION ;
	y = (floor(((float)(yBorde - yMouse))/alto * PRECISION)) / PRECISION ;

	pto[0] = x;
	pto[1] = y;
	pto[2] = 0.0f;
}

/* como máximo podemos tener 30 ptos de control*/
PuntosControl::PuntosControl()
{
	this->ptos = new float [MAX_PTO_CTRL * CteObjeto::CANT_COORD_PTO];
	this->cantPto = 0;
}

PuntosControl::PuntosControl( const PuntosControl &ptos )
{
	unsigned int i;

	this->ptos =  new float [MAX_PTO_CTRL * CteObjeto::CANT_COORD_PTO];
	this->cantPto = ptos.getCantPtos();

	for ( i = 0; i < this->cantPto * CteObjeto::CANT_COORD_PTO; i++ )
		this->ptos[i] = ptos.getPtos()[i];
}

void PuntosControl::agregarPto(float v[])
{
	//todo ver el -3, mepa q deberia ser 9 (3 * CANT_COORD_PTO)
	if (cantPto == MAX_PTO_CTRL-3) // como tengo una bsplice cerrada cubica, necesito 3 lugares para los ptos q repito
		return;
	for (unsigned int i = 0; i < CteObjeto::CANT_COORD_PTO; i++)
		this->ptos[CteObjeto::CANT_COORD_PTO * cantPto + i] = v [i];
	cantPto++;
}

void PuntosControl::sacarUltPto()
{
	if (cantPto > 0)
		cantPto--;
}

float* PuntosControl::getPto( unsigned int pto ) const
{
	if ( pto > cantPto)
		throw new ECurvas("PuntoControl. El pto al que se quiere acceder no existe");

	float *v = new float[CteObjeto::CANT_COORD_PTO];

	v[0] = ptos[pto*CteObjeto::CANT_COORD_PTO];
	v[1] = ptos[pto*CteObjeto::CANT_COORD_PTO+1];
	v[2] = ptos[pto*CteObjeto::CANT_COORD_PTO+2];
	return v;
}

float* PuntosControl::getPtos() const
{
	return this->ptos;
}

unsigned int PuntosControl::getCantPtos()const
{
	return this->cantPto;
}

PuntosControl::~PuntosControl()
{
	delete [] this->ptos;
}
