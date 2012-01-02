/*
 * Pixel.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "Pixel.h"

Pixel::Pixel( unsigned int cantColor )
{
	this->cantColor = cantColor;
}

unsigned int Pixel::getCantColores()
{
	return this->cantColor;
}

Pixel::~Pixel()
{

}
