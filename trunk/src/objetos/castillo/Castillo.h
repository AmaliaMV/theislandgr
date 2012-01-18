/*
 * Castillo.h
 *
 *  Created on: 15/01/2012
 *      Author: amalia
 */

#ifndef CASTILLO_H_
#define CASTILLO_H_

#include "../../fisica/Fisica.h"

#include "Ladrillo.h"

class Castillo {
public:
	Castillo( Fisica* fisica );
	void dibujar();
	virtual ~Castillo();

private:
	void dibujarTorre( unsigned int &indice, Fisica *fisica );
	void dibujarMuros( unsigned int &indice, Fisica *fisica );
	void agregarLadrillosAlModelo( btDiscreteDynamicsWorld* dynamicsWorld );

	Ladrillo** ladrillos;
};

#endif /* CASTILLO_H_ */
