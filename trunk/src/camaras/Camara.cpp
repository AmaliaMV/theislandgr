/*
 * Camara.cpp
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#include "Camara.h"

Camara::Camara( float angHInit, float angVInit, float distancia )
{
	this->eye = new float [3];
	this->at = new float [3];
	this->up = new float [3];

	this->up[0]=0.0;
	this->up[1]=0.0;
	this->up[2]=1.0;

	this->angH = angHInit;
	this->angV = angVInit;

	this->distancia = distancia;
	this->distMin = 5.0;
	this->distMax = 50.0;

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

	this->validarAngV();
}

float Camara::getAngH() const
{ return this->angH; }

float Camara::getAngV() const
{ return this->angV; }

float Camara::getDist() const
{ return this->distancia; }

void Camara::setAngVMax( float angVMax )
{ this->angVMax = angVMax; }

void Camara::setAngVMin( float angVMin)
{ this->angVMin = angVMin; }

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

void Camara::validarAngV ()
{
	if ( angV < this->angVMin )
		angV = this->angVMin;
	else if ( angV > this->angVMax )
		angV = this->angVMax;
}
void Camara::validarAngH ( float max, float min )
{
	if ( angH < min )
		angH = max;
	else if ( angH > max )
		angH = min;
}

void Camara::alejarCamara() {}

void Camara::acercarCamara() {}

void Camara::subirCamara() {}

void Camara::bajarCamara() {}

void Camara::setDistMax ( float distMax )
{ this->distMax = distMax; }

void Camara::setDistMin ( float distMin )
{ this->distMin = distMin; }

void Camara::aumentarDist ( float aumento )
{
	if ( this->distancia + aumento < this->distMax )
		this->distancia += aumento;
}

void Camara::disminuirDist ( float disminucion )
{
	if ( this->distancia - disminucion > this->distMin )
		this->distancia -= disminucion;
}
