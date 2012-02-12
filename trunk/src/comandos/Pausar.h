/*
 * Pausar.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef PAUSAR_H_
#define PAUSAR_H_

#include "Comando.h"
#include "../objetos/Mundo.h"

class Pausar: public Comando {
public:
	Pausar(Mundo* mundo);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~Pausar();

private:
	Mundo* mundo;
};

#endif /* PAUSAR_H_ */
