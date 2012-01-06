/*
 * RectanguloConTextura.h
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 *
 *      ancho
 *      2 -- 3
 *      |    |    alto
 *      |    |
 *      0 -- 1
 *
 *      dibuja un rectangulo en el plano XY
 */

#ifndef RECTANGULOCONTEXTURA_H_
#define RECTANGULOCONTEXTURA_H_

#include "../ODTextura.h"

#include "../../grafica/textura/Textura24.h"

class RectanguloConTextura: public ODTextura {
public:
	RectanguloConTextura( string nombreTextura, float base, float altura );
	virtual ~RectanguloConTextura();

	float getBase() const;
	float getAltura() const;

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	float ALTURA;
	float BASE;
};

#endif /* RECTANGULOCONTEXTURA_H_ */
