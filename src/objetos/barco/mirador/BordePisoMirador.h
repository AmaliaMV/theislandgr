/*
 * BordeMirador.h
 *
 *  Created on: 23/12/2011
 *      Author: amalia
 */

#ifndef BORDEPISOMIRADOR_H_
#define BORDEPISOMIRADOR_H_

#include "../../ODTextura.h"

#include "../../../grafica/textura/Textura24.h"

class BordePisoMirador: public ODTextura {
public:
	BordePisoMirador( const string nombreArchivo, const float radio, const float altura );
	virtual ~BordePisoMirador();

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	float RADIO;
	float ALTURA;

	static const unsigned int PASO = 30;
};

#endif /* BORDEPISOMIRADOR_H_ */
