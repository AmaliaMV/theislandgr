/*
 * NodoPalmera.cpp
 *
 *  Created on: 20/06/2012
 *      Author: amalia
 */

#include "NodoPalmera.h"

NodoPalmera::NodoPalmera(Palmera* dibujo, float x, float y)
{
	this->X = x;
	this->Y = y;
	this->distancia = distancia;
	this->dibujo = dibujo;
}

void NodoPalmera::calcularDistancia(float xEye, float yEye)
{
	float d_x, d_y;

	d_x = X - xEye;
	d_y = Y - yEye;

	this->distancia = d_x * d_x + d_y * d_y;
}

void NodoPalmera::dibujar()
{
	glPushMatrix();
		glTranslatef(X, Y, CteMundo::ALTURA_ISLA);
		this->dibujo->dibujar();
	glPopMatrix();
}

float NodoPalmera::getDistancia()
{
	return this->distancia;
}
NodoPalmera::~NodoPalmera()
{
}

