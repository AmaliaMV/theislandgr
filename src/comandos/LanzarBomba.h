/*
 * LanzarBomba.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef LANZARBOMBA_H_
#define LANZARBOMBA_H_

#include "Comando.h"
#include "../objetos/Mundo.h"

class LanzarBomba: public Comando {
public:
	LanzarBomba(Mundo* mundo);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~LanzarBomba();

private:
	Mundo* mundo;
};

#endif /* LANZARBOMBA_H_ */
