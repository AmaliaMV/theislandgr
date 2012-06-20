/*
 * NodoPalmera.h
 *
 *  Created on: 20/06/2012
 *      Author: amalia
 */

#ifndef NODOPALMERA_H_
#define NODOPALMERA_H_

#include "Palmera.h"
#include "ConstantesMundo.h"

class NodoPalmera {

public:
	NodoPalmera(Palmera* dibujo, float x, float y);
	void calcularDistancia(float xEye, float yEye);
	float getDistancia();
	void dibujar();
	virtual ~NodoPalmera();

private:
	float X;
	float Y;
	float distancia;

	Palmera* dibujo;
};

#endif /* NODOPALMERA_H_ */
