/*
 * BMP.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "BMP.h"

BMP::BMP( string nombreArchivo, unsigned int cantColor )
{
	this->abrirArchivo( nombreArchivo );

	leerCabecera ( );

	imagen = new BYTE1 [this->encabezado3.alto*this->encabezado3.ancho*cantColor];

}

void BMP::escribirPixelEnBuffer ( Pixel *pixel, unsigned int X, unsigned int Y )
{
	unsigned int offset = 0; //corrimiento no need porq no estoy en arch

	offset = offset + Y * this->encabezado3.ancho * pixel->getCantColores();
	offset = offset + X * pixel->getCantColores();

	for ( unsigned int i = 0; i < pixel->getCantColores(); i ++ )
		this->imagen[offset + i] = pixel->getColor()[i];
}

BYTE1* BMP::leerPixel ( Pixel *pixel , unsigned int X, unsigned int Y)
{
	BYTE1 *pix = new BYTE1 [ pixel->getCantColores() ];
	unsigned int offset = this->getEncabezado2().inicioImagen; //corrimiento
	unsigned char relleno = this->getEncabezado3().ancho % 4;

	offset += Y * this->getEncabezado3().ancho * pixel->getCantColores() + Y * relleno * sizeof(BYTE1);
	offset = offset + X * pixel->getCantColores();


	fseek (archivo, offset, SEEK_SET);
	fread (pix, pixel->getCantColores(), 1, archivo);

	return pix;
}

BMP::~BMP()
{
	delete [] this->imagen;
}

void BMP::abrirArchivo ( string nombreArchivo )
{
	archivo = fopen ( nombreArchivo.c_str(), "r" );

	this->testExisteArchivo( nombreArchivo );
}

void BMP::leerCabecera ( )
{
	fread (&encabezado1, sizeof (struct Encabezado1), 1, archivo);
	fread (&encabezado2, sizeof (struct Encabezado2), 1, archivo);
	fread (&encabezado3, sizeof (struct Encabezado3), 1, archivo);
}

void BMP::testExisteArchivo ( string nombreArchivo )
{
	if ( archivo == NULL )
		throw new EArchivoInexistente( nombreArchivo );
}

BYTE1* BMP::getImagen (unsigned int &ancho, unsigned int &alto)
{
	ancho = this->encabezado3.ancho;
	alto  = this->encabezado3.alto;

	return this->imagen;
}

void BMP::testArchivoNoComprido ( string nombreArchivo )
{
	if ( this->encabezado3.comprimida != 0 )
	{
		string mensaje;

		mensaje = "El archivo " + nombreArchivo + " se encuentra comprimido.";

		throw new EBmp( mensaje );
	}
}

FILE* BMP::getArchivo()
{
	return this->archivo;
}
Encabezado2 BMP::getEncabezado2()
{
	return this->encabezado2;
}
Encabezado3 BMP::getEncabezado3()
{
	return this->encabezado3;
}
