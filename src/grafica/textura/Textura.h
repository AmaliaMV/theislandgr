/*
 * Textura.h
 *
 *  Created on: 30/05/2011
 *      Author: Amalia
 */

#ifndef TEXTURA_H_
#define TEXTURA_H_

#include <GL/glut.h>

#include "../../archivos/BMP/BMP.h"

class Textura {
public:
	Textura( BMP *bmp, GLint internalFormat, GLenum format ); //carga en memoria la imagen

	void usar() const; // setea q se va a usar esta textura

	static void habilitar(); //habilita GL_TEXTURE-2D
	static void deshabilitar(); //deshabilita GL_TEXTURE-2D

	virtual ~Textura();

private:
	unsigned int ancho;
	unsigned int alto;
	GLuint nombre;
};

#endif /* TEXTURA_H_ */
