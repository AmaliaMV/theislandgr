/*
 * PixelRGBA.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "PixelRGBA.h"

const unsigned int PixelRGBA::CANT_COLOR = 4;

PixelRGBA::PixelRGBA(): Pixel( CANT_COLOR )
{
	this->colores = new BYTE1 [ CANT_COLOR ];

	this->setRed( 0 );
	this->setGreen( 0 );
	this->setBlue( 0 );
	this->setAlpha( 0 );
}

BYTE1* PixelRGBA::getColor()
{
	return this->colores;
}

void PixelRGBA::setPixelRGBA( BYTE1 *pixel )
{
	this->setRed( pixel [0] );
	this->setGreen( pixel [1] );
	this->setBlue( pixel [2] );
	this->setAlpha( pixel [3] );
}

void PixelRGBA::setPixelBGRA( BYTE1 *pixel )
{
	this->setRed( pixel [2] );
	this->setGreen( pixel [1] );
	this->setBlue( pixel [0] );
	this->setAlpha( pixel [3] );
}

void PixelRGBA::getPixelRGBA( BYTE1 * (&pixel) )
{
	pixel [0] = this->getRed();
	pixel [1] = this->getGreen();
	pixel [2] = this->getBlue();
	pixel [3] = this->getAlpha();
}

void PixelRGBA::getPixelBGRA( BYTE1 * (&pixel) )
{
	pixel [0] = this->getBlue();
	pixel [1] = this->getGreen();
	pixel [2] = this->getRed();
	pixel [3] = this->getAlpha();
}

PixelRGBA::~PixelRGBA()
{
	delete [] this->colores;
}

BYTE1 PixelRGBA::getRed()
{
	return this->colores[ROJO];
}
void PixelRGBA::setRed( BYTE1 cant )
{
	this->colores[ROJO] = cant;
}
BYTE1 PixelRGBA::getGreen()
{
	return this->colores[VERDE];
}
void PixelRGBA::setGreen( BYTE1 cant )
{
	this->colores[VERDE] = cant;
}
BYTE1 PixelRGBA::getBlue()
{
	return this->colores[AZUL];
}
void PixelRGBA::setBlue( BYTE1 cant )
{
	this->colores[AZUL] = cant;
}

BYTE1 PixelRGBA::getAlpha()
{
	return this->colores[ALPHA];
}

void PixelRGBA::setAlpha( BYTE1 cant )
{
	this->colores[ALPHA] = cant;
}
