/*
 * Cielo.h
 *
 *  Created on: 17/09/2011
 *      Author: amalia
 */

#ifndef CIELO_H_
#define CIELO_H_

#include "ODTextura.h"

#include "../grafica/textura/Textura24.h"
#include "../grafica/iluminacion/IluminacionMaterial.h"
#include "../matematica/Matematica.h"

class Cielo: public ODTextura {
public:
	Cielo( string nombreTextura, float radio );
	virtual ~Cielo();

protected:
	void displayList() const;

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	unsigned int cantPtosX;
	unsigned int cantPtosY;

	float RADIO;

	static const float FI_MAX;
	static const float TITA_MAX;
	static const float DELTA_FI;
	static const float DELTA_TITA;

	IluminacionMaterial* luz;
	void inicializarLuz();
	void eliminarLuz();
};

#endif /* CIELO_H_ */
