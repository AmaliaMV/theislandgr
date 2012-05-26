/*
 * BMP.cpp
 *
 *  Created on: 30/05/2011
 *      Author: Amalia
 */

#include "BMP32.h"
/* 4 es la cant de colores q tiene el arch RGBA */
BMP32::BMP32( string nombreArchivo ): BMP( nombreArchivo, 4 )
{
	this->cargar( );

	fclose (this->getArchivo());
}

BMP32::~BMP32() { }

void BMP32::cargar( )
{
	unsigned int y, x;
	PixelRGBA *pixel;
	BYTE1 *pixTemp;

	pixel = new PixelRGBA();

	for (y = 0; y < this->getEncabezado3().alto; y ++)
	{
		for (x = 0; x < this->getEncabezado3().ancho ; x++)
		{
			pixTemp = this->leerPixel( pixel, this->getEncabezado3().ancho - 1 - y, x);
			pixel->setPixelBGRA( pixTemp );
//			pixel->setAlpha(255);
			escribirPixelEnBuffer (pixel, x, y);
		//	cout<<"trasn: "<< (int)pixel->getAlpha()<<" rojo: "<< (int)pixel->getRed()<<" azul: "<<(int) pixel->getBlue()<<" verde: "<<(int ) pixel->getGreen()<<endl;
			delete []pixTemp;
		}
	}
	delete pixel;
}
