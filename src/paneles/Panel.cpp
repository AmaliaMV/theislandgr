/*
 * Panel.cpp
 *
 *  Created on: 07/08/2011
 *      Author: amalia
 */

#include "Panel.h"

Panel::Panel()
{
	this->setDimensiones( 0, 0, 0, 0 );
	this->XMIN = 0.0;
	this->XMAX = 1.0;
	this->YMIN = 0.0;
	this->YMAX = 1.0;
}

void Panel::setProyeccion() const
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(this->XMIN, this->XMAX, this->YMIN, this->YMAX);
}

void Panel::setPanel()
{
	glViewport (topX, topY, ancho, alto);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Panel::setDimensiones ( GLint topX, GLint topY, GLsizei ancho, GLsizei alto )
{
	this->topX = topX;
	this->topY = topY;
	this->ancho = ancho;
	this->alto = alto;
}

void Panel::setEscalaReferencia( GLdouble XMIN, GLdouble XMAX, GLdouble YMIN, GLdouble YMAX)
{
	this->XMIN = XMIN;
	this->XMAX = XMAX;
	this->YMIN = YMIN;
	this->YMAX = YMAX;
}

void Panel::escribir(const char *texto)
{
	for (unsigned int i = 0; i < strlen(texto); i++ )
	{
		glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, texto[i]);
	}
}

void Panel::dibujar()
{
	this->setPanel();
	this->setProyeccion();
	this->dibujarFondo();
}
