/*
 * MCmdJuegos.h
 *
 *  Created on: 10/01/2012
 *      Author: amalia
 */

#ifndef MCMDJUEGOS_H_
#define MCMDJUEGOS_H_

#include "Panel.h"

#include "../objetos/geometricos/RectanguloConTextura.h"

class MCmdJuegos: public Panel {
public:
	MCmdJuegos( string nomTextMenu );
	void dibujar();
	void modificarMostrar();
	virtual ~MCmdJuegos();

private:
	void dibujarFondo();
	void setPanel();

	RectanguloConTextura* menu;
	float anchoImagen;
	float altoImagen;
	bool mostrar;
};

#endif /* MCMDJUEGOS_H_ */
