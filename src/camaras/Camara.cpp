/*
 * Camara.cpp
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#include "Camara.h"

Camara::Camara( float fiInit, float titaInit )
{
	this->eye = new float [3];
	this->at = new float [3];
	this->up = new float [3];

	this->up[0]=0.0;
	this->up[1]=0.0;
	this->up[2]=1.0;

	this->fi = fiInit;
	this->tita = titaInit;

	this->titaMax = 170;
	this->titaMin = 1;
}

float* Camara::getEye () const
{ return this->eye; }

float* Camara::getAt () const
{ return this->at; }

float* Camara::getUp () const
{ return this->up; }

void Camara::incFi ( float num )
{
	this->fi += num;

	this->validarAnguloFi( 360.0, -360.0 );
}

void Camara::incTita ( float num )
{
	this->tita += num;

	this->validarAnguloTita( this->titaMax, this->titaMin );
}

float Camara::getFi() const
{ return this->fi; }

float Camara::getTita() const
{ return this->tita; }

void Camara::setTitaMax( float titaMax)
{ this->titaMax = titaMax; }

void Camara::setTitaMin( float titaMin)
{ this->titaMax = titaMin; }

void Camara::setCoordEye ( float x, float y, float z )
{ this->setCoord( x, y, z, this->eye ); }

void Camara::setCoordAt ( float x, float y, float z)
{ this->setCoord( x, y, z, this->at ); }

Camara::~Camara()
{
	delete [] eye;
	delete [] at;
	delete [] up;
}

void Camara::setCoord ( float x, float y, float z, float *objeto )
{
	objeto[0] = x;
	objeto[1] = y;
	objeto[2] = z;
}

void Camara::validarAnguloTita ( float max, float min )
{
	if ( tita < min )
		tita = min;
	else if ( tita > max )
		tita = max;
}
void Camara::validarAnguloFi ( float max, float min )
{
	if ( fi < min )
		fi = max;
	else if ( fi > max )
		fi = min;
}

