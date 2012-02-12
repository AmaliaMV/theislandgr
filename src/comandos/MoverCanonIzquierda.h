/*
 * MoverCanonIzquierda.h
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#ifndef MOVERCANONIZQUIERDA_H_
#define MOVERCANONIZQUIERDA_H_

#include "Comando.h"
#include "../objetos/barco/canon/Canon.h"

class MoverCanonIzquierda: public Comando {
public:
	MoverCanonIzquierda(Canon *canon);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~MoverCanonIzquierda();

private:
	Canon* canon;
};

#endif /* MOVERCANONIZQUIERDA_H_ */
