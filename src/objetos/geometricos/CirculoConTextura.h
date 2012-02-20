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
	CirculoConTextura(const string nombreTextura, const float radio);
	virtual ~CirculoConTextura();

protected:
	void displayList() const;

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	float RADIO;

	static const unsigned int PASO = 30;
};

#endif /* CIRCULOCONTEXTURA_H_ */
