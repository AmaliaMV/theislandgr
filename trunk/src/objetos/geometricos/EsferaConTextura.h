/*
 * EsferaConTextura.h
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#ifndef ESFERACONTEXTURA_H_
#define ESFERACONTEXTURA_H_

#include "../ODTextura.h"

#include"../../matematica/Matematica.h"
#include"../../grafica/textura/Textura24.h"

class EsferaConTextura: public ODTextura {
public:
	EsferaConTextura( string nombreTextura, float radio );
	virtual ~EsferaConTextura();

private:
	virtual void generarCoordPtos();
	virtual void generarIndice();
	virtual void generarCoodText();

	float RADIO;
	float cantPtosX;
	float cantPtosY;
	static const float TITA_MAX;
	static const float FI_MAX;
	static const float DELTA_TITA;
	static const float DELTA_FI;

};

#endif /* ESFERACONTEXTURA_H_ */
