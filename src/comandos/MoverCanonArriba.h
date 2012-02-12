/*
 * MoverCanonArriba.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef MOVERCANONARRIBA_H_
#define MOVERCANONARRIBA_H_

#include "Comando.h"
#include "../objetos/barco/canon/Canon.h"

class MoverCanonArriba: public Comando {
public:
	MoverCanonArriba(Canon *canon);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~MoverCanonArriba();

private:
	Canon* canon;
};

#endif /* MOVERCANONARRIBA_H_ */
