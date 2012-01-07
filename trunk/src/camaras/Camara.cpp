/*
 * Camara.cpp
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#include "Camara.h"

Camara::Camara( float angHInit, float angVInit )
{
	this->eye = new float [3];
	this->at = new float [3];
	this->up = new float [3];

	this->up[0]=0.0;
	this->up[1]=0.0;
	this->up[2]=1.0;

	this->angH = angHInit;
	this->angV = angVInit;

	this->angVMax = 170;
	this->angVMin = 1;
}

float* Camara::getEye () const
{ return this->eye; }

float* Camara::getAt () const
{ return this->at; }

float* Camara::getUp () const
{ return this->up; }

void Camara::incAngH ( float num )
{
	this->angH += num;

	this->validarAngH( 360.0, -360.0 );
}

void Camara::incAngV ( float num )
{
	this->angV += num;

	this->validarAngV( this->angVMax, this->angVMin );
}

float Camara::getAngH() const
{ return this->angH; }

float Camara::getTita() const
{ return this->angV; }

void Camara::setAngVMax( float angVMax)
{ this->angVMax = angVMax; }

void Camara::setAngVMin( float angVMin)
{ this->angVMax = angVMin; }

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

void Camara::validarAngV ( float max, float min )
{
	if ( angV < min )
		angV = min;
	else if ( angV > max )
		angV = max;
}
void Camara::validarAngH ( float max, float min )
{
	if ( angH < min )
		angH = max;
	else if ( angH > max )
		angH = min;
}

