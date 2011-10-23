/*
 * Textura.cpp
 *
 *  Created on: 30/05/2011
 *      Author: Amalia
 */

#include "Textura.h"

Textura::Textura( BMP *bmp, GLint internalFormat, GLenum format)
{
	BYTE1 *imagen = bmp->getImagen( this->ancho, this->alto );

	glGenTextures(1, &this->nombre);
	glBindTexture(GL_TEXTURE_2D, this->nombre);

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, this->ancho, this->alto, 0, format, GL_UNSIGNED_BYTE, imagen);

	glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

	delete bmp;
}

Textura::~Textura()
{
	glDeleteTextures(1, &this->nombre);
}

void Textura::usar() const
{
	glBindTexture(GL_TEXTURE_2D, this->nombre);
}

void Textura::habilitar()
{
	glEnable(GL_TEXTURE_2D);
}
void Textura::deshabilitar()
{
	glDisable(GL_TEXTURE_2D);
}
