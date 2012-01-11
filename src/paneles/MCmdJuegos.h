/*
 * MCmdJuegos.h
 *
 *  Created on: 10/01/2012
 *      Author: amalia
 */

#ifndef MCMDJUEGOS_H_
#define MCMDJUEGOS_H_

#include "../objetos/geometricos/RectanguloConTextura.h"

class MCmdJuegos {
public:
	MCmdJuegos( string nomTextMenu );
	void dibujarPanel( float anchoPantalla, float altoPantalla );
	virtual ~MCmdJuegos();

private:
	float TOP_VIEW_POSX;
	float TOP_VIEW_W;
	float TOP_VIEW_POSY;
	float TOP_VIEW_H;

	RectanguloConTextura* menu;
};

#endif /* MCMDJUEGOS_H_ */
