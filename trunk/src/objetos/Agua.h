/*
 * Agua.h
 *
 *  Created on: 11/09/2011
 *      Author: amalia
 */

#ifndef AGUA_H_
#define AGUA_H_

#include "../ConstantesObjeto.h"
#include "../grafica/textura/Textura24.h"
#include "../matematica/Matematica.h"

#define PASO_ANGULO_XY 10.0 //360/10
#define PASO_RADIO 5.0
#define CANT_CURVA 0.25 // o sea, cuantos ciclos da la curva

#define INC 10.0
#define INC_REDUCIR 10.0

class Agua {
public:
	Agua( string nombreTextura, float radio );
	virtual void dibujar();
	void incrementarAngulo();
	virtual ~Agua();

private:
	void generarPtos ( float *ptos );
	void setIndice ( unsigned int *vertIndice, unsigned int ptosHorizontales, unsigned int ptosVerticales );
	void generarCoordText ( float *coordText, unsigned int cantPtos );


	const float getIncRadio() const;
	const float getIncAnguloXY() const;
	const float getIncAnguloZ() const;

	float angulo;
	float RADIO;

	static const float ANG_XY_MAX;
	static const float COORD_CENTRO_TEXTURA;
	static const float GRADO_AGUA_AGITADA;

	Textura *textura;

};

#endif /* AGUA_H_ */
