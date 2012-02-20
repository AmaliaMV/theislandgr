/*
 * RectanguloConTextura.h
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 *
 *      base
 *      2 -- 3
 *      |    |    alto
 *      |    |
 *      0 -- 1
 *
 * referencia:
 *
 *     0 ----y+
 *     |
 *	   |
 *	   x+
 *
 *	   textura si el dibujo es:
 *
 *	   o.....i
 *	   /	?
 *	   /	? qda en el mismo sentido en el plano especificado anteriormnt
 *
 */

#ifndef RECTANGULOCONTEXTURA_H_
#define RECTANGULOCONTEXTURA_H_

#include "../ODTextura.h"

#include "../../grafica/textura/Textura24.h"

class RectanguloConTextura: public ODTextura {
public:
	RectanguloConTextura( string nombreTextura, float base, float altura, Coord_text *coord_text = new Coord_text() );
	RectanguloConTextura( Textura *textura, float base, float altura, Coord_text *coord_text = new Coord_text() );
	virtual ~RectanguloConTextura();

	float getBase() const;
	float getAltura() const;

protected:
	void displayList() const;

private:
	void init( float base, float altura, Coord_text *coord_text );
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	float ALTURA;
	float BASE;
	Coord_text *coord_text;
};

#endif /* RECTANGULOCONTEXTURA_H_ */
