/*
 * MoverCanonDerecha.h
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#ifndef MOVERCANONDERECHA_H_
#define MOVERCANONDERECHA_H_

#include "Comando.h"
#include "../objetos/barco/canon/Canon.h"

class MoverCanonDerecha: public Comando {
public:
	MoverCanonDerecha(Canon *canon);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~MoverCanonDerecha();

private:
	Canon* canon;
};

#endif /* MOVERCANONDERECHA_H_ */
