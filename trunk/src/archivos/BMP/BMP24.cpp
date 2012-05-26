/*
 * BMP.cpp
 *
 *  Created on: 30/05/2011
 *      Author: Amalia
 */

#include "BMP24.h"
/* 3 es la cant de colores q tiene el arch RGB */
BMP24::BMP24( string nombreArchivo ): BMP( nombreArchivo, 3 )
{
	this->cargar( );

	fclose (this->getArchivo());
}

BMP24::~BMP24() { }

void BMP24::cargar( )
{
	unsigned int y, x;
	PixelRGB *pixel;
	BYTE1 *pixTemp;

	pixel = new PixelRGB();

	for (y = 0; y < this->getEncabezado3().alto; y ++)
	{
		for (x = 0; x < this->getEncabezado3().ancho ; x++)
		{
			pixTemp = this->leerPixel( pixel, this->getEncabezado3().ancho - 1 - y, x);
			pixel->setPixelBGR( pixTemp );
			escribirPixelEnBuffer (pixel, x, y);
			delete []pixTemp;
		}
	}
	delete pixel;
}
