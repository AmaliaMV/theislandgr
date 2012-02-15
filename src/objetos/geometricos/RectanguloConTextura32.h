/*
 * RectanguloConTextura32.h
 *
 *  Created on: 14/02/2012
 *      Author: amalia
 */

#ifndef RECTANGULOCONTEXTURA32_H_
#define RECTANGULOCONTEXTURA32_H_

#include "RectanguloConTextura.h"

#include "../../grafica/textura/Textura32.h"

class RectanguloConTextura32: public ODTextura {
public:
	RectanguloConTextura32( string nombreTextura, float base, float altura, Coord_text *coord_text = new Coord_text() );
	virtual ~RectanguloConTextura32();

protected:
	virtual void displayList() const;

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	float ALTURA;
	float BASE;
	Coord_text *coord_text;
};

#endif /* RECTANGULOCONTEXTURA32_H_ */
