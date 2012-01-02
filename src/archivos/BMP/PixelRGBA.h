/*
 * PixelRGBA.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef PIXELRGBA_H_
#define PIXELRGBA_H_

#include "Pixel.h"

class PixelRGBA: public Pixel {
public:
	PixelRGBA();

	virtual BYTE1* getColor();

	virtual void setPixelRGBA( BYTE1 *pixel ); // el vect debe ser de dimension 3
	virtual void setPixelBGRA( BYTE1 *pixel );

	virtual void getPixelRGBA( BYTE1* (&pixel) ); // debe tener
	virtual void getPixelBGRA( BYTE1* (&pixel) );

	BYTE1 getRed();
	void setRed( BYTE1 cant );
	BYTE1 getGreen();
	void setGreen( BYTE1 cant );
	BYTE1 getBlue();
	void setBlue( BYTE1 cant );
	BYTE1 getAlpha();
	void setAlpha( BYTE1 cant );

	virtual ~PixelRGBA();

private:

	BYTE1* colores;

	static const unsigned int CANT_COLOR;

	enum RGB { ROJO = 0, AZUL = 2, VERDE = 1, ALPHA = 3};

};

#endif /* PIXELRGBA_H_ */
