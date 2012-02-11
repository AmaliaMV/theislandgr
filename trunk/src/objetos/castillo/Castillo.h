/*
 * Castillo.h
 *
 *  Created on: 15/01/2012
 *      Author: amalia
 */

#ifndef CASTILLO_H_
#define CASTILLO_H_

#include "../../fisica/FPrismaRigido.h"

#include "BuildLadrillo.h"
#include "Puerta.h"

class Castillo {
public:
	Castillo( Fisica* fisica, float alturaPiso );
	void dibujar();
	virtual ~Castillo();

private:
	void dibujarTorre( unsigned int &indice, Fisica *fisica, float alturaPiso );
	void dibujarMuros( unsigned int &indice, Fisica *fisica, float alturaPiso );
	void agregarCuerposAlModelo( btDiscreteDynamicsWorld* dynamicsWorld );

	FPrismaRigido** cuerpos;
	Textura24* textura;
};

#endif /* CASTILLO_H_ */
