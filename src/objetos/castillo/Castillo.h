/*
 * Castillo.h
 *
 *  Created on: 15/01/2012
 *      Author: amalia
 */

#ifndef CASTILLO_H_
#define CASTILLO_H_

#include "../../fisica/CuerpoFisicoRigido.h"

#include "BuildLadrillo.h"
#include "Puerta.h"

class Castillo {
public:
	Castillo( Fisica* fisica );
	void dibujar();
	virtual ~Castillo();

private:
	void dibujarTorre( unsigned int &indice, Fisica *fisica, Textura* textura );
	void dibujarMuros( unsigned int &indice, Fisica *fisica, Textura* textura );
	void agregarCuerposAlModelo( btDiscreteDynamicsWorld* dynamicsWorld );

	CuerpoFisicoRigido** cuerpos;
	Textura24* textura;
};

#endif /* CASTILLO_H_ */
