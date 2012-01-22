/*
 * LadoPrismaConTextura.h
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 *
 *
 *	  largo  ancho  largo  ancho
 *   4 - - 5 - - 6 - - 7
 *   |     |     |     |		altura
 *   |     |     |     |
 *   0 - - 1 - - 2 - - 3
 *
 */

#ifndef LADOPRISMACONTEXTURA_H_
#define LADOPRISMACONTEXTURA_H_

#include "../ODTextura.h"

#include "../../grafica/textura/Textura24.h"

class LadoPrismaConTextura: public ODTextura {
public:
	LadoPrismaConTextura(string nombreTextura, float altura, float ancho, float largo);
	virtual ~LadoPrismaConTextura();

	float getAltura() const;
	float getAncho() const;
	float getLargo() const;

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	float ALTURA;
	float ANCHO;
	float LARGO;

};

#endif /* LADOPRISMACONTEXTURA_H_ */
