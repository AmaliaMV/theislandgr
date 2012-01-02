/*
 * Pixel.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "PixelRGB.h"

const unsigned int PixelRGB::CANT_COLOR = 3 ;

PixelRGB::PixelRGB(): Pixel( CANT_COLOR )
{
	this->colores = new BYTE1 [ CANT_COLOR ];

	this->setRed( 0 );
	this->setGreen( 0 );
	this->setBlue( 0 );
}

BYTE1* PixelRGB::getColor()
{
	return this->colores;
}

void PixelRGB::setPixelRGB( BYTE1 *pixel )
{
	this->setRed( pixel [0] );
	this->setGreen( pixel [1] );
	this->setBlue( pixel [2] );

}

void PixelRGB::setPixelBGR( BYTE1 *pixel )
{
	this->setRed( pixel [2] );
	this->setGreen( pixel [1] );
	this->setBlue( pixel [0] );
}

void PixelRGB::getPixelRGB( BYTE1 * (&pixel) )
{
	pixel [0] = this->getRed();
	pixel [1] = this->getGreen();
	pixel [2] = this->getBlue();
}

void PixelRGB::getPixelBGR( BYTE1 * (&pixel) )
{
	pixel [0] = this->getBlue();
	pixel [1] = this->getGreen();
	pixel [2] = this->getRed();
}

PixelRGB::~PixelRGB()
{
	delete [] this->colores;
}

BYTE1 PixelRGB::getRed()
{
	return this->colores[ROJO];
}
void PixelRGB::setRed( BYTE1 cant )
{
	this->colores[ROJO] = cant;
}
BYTE1 PixelRGB::getGreen()
{
	return this->colores[VERDE];
}
void PixelRGB::setGreen( BYTE1 cant )
{
	this->colores[VERDE] = cant;
}
BYTE1 PixelRGB::getBlue()
{
	return this->colores[AZUL];
}
void PixelRGB::setBlue( BYTE1 cant )
{
	this->colores[AZUL] = cant;
}
