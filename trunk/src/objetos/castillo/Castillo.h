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
	Ladrillo** ladrillos;
};

#endif /* CASTILLO_H_ */
