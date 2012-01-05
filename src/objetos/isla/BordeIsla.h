/*
 * BordeIsla.h
 *
 *  Created on: 12/08/2011
 *      Author: amalia
 */

#ifndef BORDEISLA_H_
#define BORDEISLA_H_

#include "ConstantesIsla.h"

#include "../ODTextura.h"

#include "../../grafica/textura/Textura24.h"
#include "../../matematica/curva/BSplineCerrada.h"
#include "../../matematica/curva/CalculadoraBSpline.h"
class BordeIsla: public ODTextura {
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
	BordeIsla( PuntosControl *ptos, string nombreTextura, const int nivelesH );
	float getAlturaMax() const;
	float getEscalado() const;
	virtual ~BordeIsla();

protected:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

private:
	static const float PENDIENTE;
	static const float ESCALADOxy;
	static const float ESCALADOz;
	static const float ALTURA_ENTRE_NIVELES;

	unsigned int ptosHorizontales;
	unsigned int ptosVerticales;

	BSplineCerrada *curva;

	unsigned int getCantPtos() const;
	unsigned int getCantReferencias() const;
};

#endif /* BORDEISLA_H_ */
