/*
 * BordeIsla.h
 *
 *  Created on: 12/08/2011
 *      Author: amalia
 */

#ifndef BORDEISLA_H_
#define BORDEISLA_H_

#include "../ObjetoDibujable.h"
#include "../../grafica/textura/Textura24.h"
#include "BordeBSpline.h"

class BordeIsla: public ObjetoDibujable {
public:

	/*
	 * ptos				son los puntos de control utilizados para dibujar el borde
	 * 					de la isla
	 * nombreTextura	nombre del archivo de donde se obtiene la textura para el borde
	 * 					de la isla
	 * paso 			es el numero de puntos q se calcula por cada tramo de curva
	 *
	 *
	 *
	 * ademas, el constructor se encarga de armar la display list con el borde
	 *
	 *
	 * alturaNivel  	es la altua q qresmos que haya entre cada nivel
	 *
	 * 			________
	 * 		d =	|		\
	 * 			|________\
	 *
	 * 	nivelesH		es la cantidad de niveles horizontales q va a tener
	 * 					la superficie
	 */
	BordeIsla( PuntosControl *ptos, string nombreTextura, const int paso, const int nivelesH );
	float getAlturaMax();
	float getEscalado();
	virtual ~BordeIsla();

private:
	static const float PENDIENTE;
	static const float ESCALADOxy;
	static const float ESCALADOz;
	static const float ALTURA_ENTRE_NIVELES;

	BordeBSpline *superficie;

	void displayList();

};

#endif /* BORDEISLA_H_ */
