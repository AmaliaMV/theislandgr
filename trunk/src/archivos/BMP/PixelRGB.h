/*
 * Pixel.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef PIXELRGB_H_
#define PIXELRGB_H_

#include "Pixel.h"

class PixelRGB: public Pixel {
public:
	PixelRGB();

	virtual BYTE1* getColor();

	virtual void setPixelRGB( BYTE1 *pixel ); // el vect debe ser de dimension 3
	virtual void setPixelBGR( BYTE1 *pixel );

	virtual void getPixelRGB( BYTE1* (&pixel) ); // debe tener
	virtual void getPixelBGR( BYTE1* (&pixel) );

	BYTE1 getRed();
	void setRed( BYTE1 cant );
	BYTE1 getGreen();
	void setGreen( BYTE1 cant );
	BYTE1 getBlue();
	void setBlue( BYTE1 cant );

	virtual ~PixelRGB();

private:
	BYTE1* colores;

	static const unsigned int CANT_COLOR;

	enum RGB { ROJO = 0, AZUL = 2, VERDE = 1};
};

#endif /* PIXEL_H_ */
