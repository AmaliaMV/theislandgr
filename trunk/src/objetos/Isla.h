/*
 * Isla.h
 *
 *  Created on: 09/08/2011
 *      Author: amalia
 *
 *	Dibuja el contorno de un isla como una curva
 *	bspline cubica dados los puntos de control
 *
 */

#ifndef ISLA_H_
#define ISLA_H_

#include <string>

#include "../archivos/ArchivoPtosControl.h"
#include "../archivos/AdministradorArchivos/AdministradorArchivo.h"

#include "isla/BordeIsla.h"
#include "isla/Pasto.h"
#include "isla/Arena.h"
#include "Palmera.h"

using namespace std;

class Isla {
public:
	Isla( AdministradorArchivo *administrador );
	void dibujar();
	virtual ~Isla();

private:
	PuntosControl *ptos;
	BordeIsla *supBorde; // es el costado de la isla
	BordeIsla *playaBorde; // es el costado de la isla
	Pasto *pasto;
	Arena *arena;
	Palmera *palmera;

	float xc; //coord x del centro de la isla
	float yc; //coord y del centro de la isla

	static const unsigned int paso = 20; // paso para recorrer la curva y calcular el centro
	static const unsigned int cantNivelesHorizontalesIsla = 4;
	static const unsigned int cantNivelesHorizontalesPlaya = 2;

	/*
	* nombreArchPtoCtrl		ruta del archivo del cual se va a obtener los ptos de control para dibujar
	* 						la isla
	*/
	void levantarCurva( string nombreArchPtoCtrl );
	void calcularCentroIsla();
};

#endif /* ISLA_H_ */
