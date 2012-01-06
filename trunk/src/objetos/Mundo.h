/*
 * Mundo.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef MUNDO_H_
#define MUNDO_H_

#include "Agua.h"
#include "Cielo.h"
#include "isla/Isla.h"
#include "barco/Barco.h"

#define DIRECTORIO_DE_TEXTURAS texturas

using namespace std;
class Mundo {
public:
	/*nombreArchivoNivel es el nombre del archivo que contiene los path
	 * 					 a los otros archivos que se usarn para dibujar
	 * 					 el mundo*/
	Mundo( string nombreArchivoNivel );
	void dibujar();
	void actualizar();
	virtual ~Mundo();

private:

	void incAnguloBarco();

	Agua *agua;
	Cielo *cielo;
	Isla *isla;
	Barco *barco;

	float anguloBarco;

	static const float RADIO_MUNDO;
	static const float RADIO_AGUA;
	static const float RADIO_NAVEGACION;
	static const float DELTA_ANGULO;
};

#endif /* MUNDO_H_ */
