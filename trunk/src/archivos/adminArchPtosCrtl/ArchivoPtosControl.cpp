/*
 * ArchivoPtosControl.cpp
 *
 *  Created on: 09/08/2011
 *      Author: amalia
 */

#include "ArchivoPtosControl.h"

void ArchivoPtosControl::guardarPtosControl (PuntosControl *ptos, string nombre)
{
	archEncabezado encabezado;
	regPtosControl reg;
	float *v;
	FILE *arch;

	arch = fopen (nombre.c_str(), "w+");
	testNoErrorAlAbrirArchivo( arch, nombre );

	encabezado.version = 1;
	encabezado.cantPtos = ptos->getCantPtos();

	fwrite( &encabezado, sizeof(archEncabezado), 1, arch);

	for (unsigned int i = 0; i < ptos->getCantPtos(); i++)
	{
		v = ptos->getPto(i);
		reg.x = v[0];
		reg.y = v[1];
		reg.z = v[2];
		fwrite( &reg, sizeof(regPtosControl), 1, arch);

		delete v;
	}

	fclose(arch);
}
void ArchivoPtosControl::cagarPtosControl ( PuntosControl *ptos, string nombre )
{
	archEncabezado encabezado;
	regPtosControl reg;
	int cantPtos;
	float v[3];
	FILE *arch;

	arch = fopen (nombre.c_str(), "r+");
	testNoErrorAlAbrirArchivo( arch, nombre );

	fread( &encabezado, sizeof(archEncabezado), 1, arch);

	if ( encabezado.version != 1 )
	{
		printf("Error. El archivo %s no es del tipo esperado o no es de la version esperada", nombre.c_str());
		exit(1);
	}

	cantPtos = encabezado.cantPtos;

	while ( cantPtos > 0 )
	{
		fread ( &reg, sizeof(regPtosControl), 1, arch);
		v[0] = reg.x;
		v[1] = reg.y;
		v[2] = reg.z;
		ptos->agregarPto(v);
		cantPtos --;
	}

	fclose(arch);
}

void ArchivoPtosControl::testNoErrorAlAbrirArchivo ( FILE *archivo, string nombre )
{
	if ( archivo == NULL )
		throw new EArchivoInexistente( nombre );
}
