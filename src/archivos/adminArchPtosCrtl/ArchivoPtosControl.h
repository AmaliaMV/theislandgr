/*
 * ArchivoPtosControl.h
 *
 *  Created on: 09/08/2011
 *      Author: amalia
 */

#ifndef ARCHIVOPTOSCONTROL_H_
#define ARCHIVOPTOSCONTROL_H_

#include <stdio.h>
#include <stdlib.h>

#include "../../matematica/curva/PuntosControl.h"
#include "../EArchivoInexistente.h"

struct archEncabezado
{
	int version;
	int cantPtos;
};

struct regPtosControl
{
	float x;
	float y;
	float z;
};

class ArchivoPtosControl {
public:

	static void guardarPtosControl ( PuntosControl *ptos,  string nombre ); // los ptos de control a guardar y el nombre del archivo
	static void cagarPtosControl ( PuntosControl *ptos, string nombre ); // necesita q se le pase una referencia para guardar los ptos de control y el nombre del archivo donde se sacan los datos

	virtual ~ArchivoPtosControl() {};

private:
	ArchivoPtosControl() {};
	static void testNoErrorAlAbrirArchivo ( FILE *archivo, string nombre );
};

#endif /* ARCHIVOPTOSCONTROL_H_ */
