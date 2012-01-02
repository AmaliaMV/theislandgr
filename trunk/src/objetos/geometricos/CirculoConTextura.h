/*
 * CirculoConTextura.h
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#ifndef CIRCULOCONTEXTURA_H_
#define CIRCULOCONTEXTURA_H_

#include "../ODTextura.h"

#include "../../grafica/textura/Textura24.h"

class CirculoConTextura: public ODTextura {
public:
	CirculoConTextura(string nombreTextura, float radio);
	virtual ~CirculoConTextura();

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	float RADIO;

	static const unsigned int PASO = 30;
};

#endif /* CIRCULOCONTEXTURA_H_ */
