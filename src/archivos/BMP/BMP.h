/*
 * BMP.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 *
 *      tema de cuando se cierra el archivo
 */

#ifndef BMP_H_
#define BMP_H_

#include <stdio.h>
#include <string>
using namespace std;

#include "../EArchivoInexistente.h"

#include "BMPCABECERA.h"
#include "EBmp.h"
#include "Pixel.h"

class BMP {
public:
	BMP( string nombreArchivo, unsigned int cantColor );
	BYTE1* getImagen (unsigned int &ancho, unsigned int &alto);
	virtual ~BMP();

protected:
	virtual void cargar( )=0;

	FILE* getArchivo();
	Encabezado2 getEncabezado2();
	Encabezado3 getEncabezado3();

	/*
	 * El orden de los colores que presenta BYTE1 es el mismo de como
	 * se encuentran en el archivo
	 */
	BYTE1* leerPixel ( Pixel *pixel , unsigned int X, unsigned int Y );
	/*
	 * Los colores son escritos en el buffer en el orden que se
	 * presentan en pixel
	 */
	void escribirPixelEnBuffer ( Pixel *pixel, unsigned int X, unsigned int Y );

private:

	BYTE1 *imagen;
	FILE *archivo;

	Encabezado1 encabezado1;
	Encabezado2 encabezado2;
	Encabezado3 encabezado3;

	void leerCabecera ( );
	void testExisteArchivo ( string nombreArchivo );
	void testArchivoNoComprido ( string nombreArchivo );
	void abrirArchivo ( string nombreArchivo );
};

#endif /* BMP_H_ */
