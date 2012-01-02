/*
 * ToroideConTextura.h
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#ifndef TOROIDECONTEXTURA_H_
#define TOROIDECONTEXTURA_H_

#include "../ODTextura.h"

#include "../../grafica/textura/Textura24.h"

class ToroideConTextura: public ODTextura {
public:
	ToroideConTextura(string nombreTextura, float radioXY, float radioZ);
	virtual ~ToroideConTextura();

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	float RADIO_XY;
	float RADIO_Z;

	static const unsigned int PASO_XY = 30;
	static const unsigned int PASO_Z = 30;

	float FEO;
};

#endif /* TOROIDECONTEXTURA_H_ */
