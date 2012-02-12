/*
 * Reiniciar.h
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#ifndef REINICIAR_H_
#define REINICIAR_H_

#include "Comando.h"
#include "../objetos/Mundo.h"

class Reiniciar: public Comando {
public:
	Reiniciar(Mundo* mundo);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~Reiniciar();

private:
	Mundo* mundo;
};

#endif /* REINICIAR_H_ */
