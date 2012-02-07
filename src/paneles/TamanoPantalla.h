/*
 * TamanoPantalla.h
 *
 *  Created on: 07/08/2011
 *      Author: amalia
 */

#ifndef TAMANOPANTALLA_H_
#define TAMANOPANTALLA_H_

class TamanoPantalla {
public:
	static float getAncho();
	static float getAlto();
	static void setAncho( float ancho );
	static void setAlto( float alto );
	static void setDimensiones( float ancho, float alto );
	virtual ~TamanoPantalla();

private:
	TamanoPantalla();

	static float ancho;
	static float alto;

};

#endif /* TAMANOPANTALLA_H_ */
