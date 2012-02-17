/*
 * VerMenuComandos.h
 *
 *  Created on: 16/02/2012
 *      Author: amalia
 */

#ifndef VERMENUCOMANDOS_H_
#define VERMENUCOMANDOS_H_

#include "Comando.h"
#include "../objetos/Mundo.h"
#include "../paneles/MCmdJuegos.h"

class VerMenuComandos: public Comando {
public:
	VerMenuComandos(MCmdJuegos* menuComandos, Mundo* mundo);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~VerMenuComandos();

private:
	MCmdJuegos* menuComandos;
	Mundo* mundo;
};

#endif /* VERMENUCOMANDOS_H_ */
