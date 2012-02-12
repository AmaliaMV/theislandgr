/*
 * MoverCanonAbajo.h
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#ifndef MOVERCANONABAJO_H_
#define MOVERCANONABAJO_H_

#include "Comando.h"
#include "../objetos/barco/canon/Canon.h"

class MoverCanonAbajo: public Comando {
public:
	MoverCanonAbajo(Canon *canon);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~MoverCanonAbajo();

private:
	Canon* canon;
};

#endif /* MOVERCANONABAJO_H_ */
