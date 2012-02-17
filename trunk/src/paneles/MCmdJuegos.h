/*
 * MCmdJuegos.h
 *
 *  Created on: 10/01/2012
 *      Author: amalia
 */

#ifndef MCMDJUEGOS_H_
#define MCMDJUEGOS_H_

#include <list>
using namespace std;

#include "Panel.h"

#include "../objetos/geometricos/RectanguloConTextura32.h"

class MCmdJuegos: public Panel {
public:
	MCmdJuegos( const string nomTextMenu, list<string> *descripciones );
	void dibujar();
	void modificarMostrar();
	virtual ~MCmdJuegos();

private:
	void dibujarFondo();
	void setPanel();

	RectanguloConTextura32* menu;
	float anchoImagen;
	float altoImagen;
	bool mostrar;
	list<string>* descripciones;

	static const float MARGEN_IZQUIERDO;
	static const float MARGEN_SUPERIOR;
	static const float SEPARACION_RENGLONES;
};

#endif /* MCMDJUEGOS_H_ */
