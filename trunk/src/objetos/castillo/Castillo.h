/*
 * Castillo.h
 *
 *  Created on: 15/01/2012
 *      Author: amalia
 */

#ifndef CASTILLO_H_
#define CASTILLO_H_

#include "Ladrillo.h"

class Castillo {
public:
	Castillo( btDiscreteDynamicsWorld* dynamicsWorld );
	void dibujar();
	virtual ~Castillo();

private:
	void dibujarTorre( unsigned int &indice );
	void dibujarMuros( unsigned int &indice );
	void agregarLadrillosAlModelo( btDiscreteDynamicsWorld* dynamicsWorld );

	Ladrillo** ladrillos;
};

#endif /* CASTILLO_H_ */
