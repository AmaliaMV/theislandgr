/*
 * PanelLetra.cpp
 *
 *  Created on: 08/08/2011
 *      Author: amalia
 */

#include "PanelLetra.h"

PanelLetra::PanelLetra(): Panel() { }

PanelLetra::~PanelLetra() { }

void PanelLetra::setPanel()
{
	this->setDimensiones( TOP_VIEW_LETRA_POSX, TOP_VIEW_LETRA_POSY , (GLsizei) TOP_VIEW_LETRA_W, (GLsizei) TOP_VIEW_LETRA_H );
	Panel::setPanel();
}
void PanelLetra::dibujarFondo()
{
	string x, y;
	x= "X";
	y = "Y";

	glDisable(GL_LIGHTING);

	// texto
	glColor3f(0.3, 0.0, 0.0);
	glRasterPos2f (0.24, 0.9);
	this->escribir(x.c_str());
	glRasterPos2f (0.74, 0.9);
	this->escribir(y.c_str());

	// borde
	glLineWidth (5.0);
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.4, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
	glEnd();
	glLineWidth (1.0);

	// fondo
	glBegin(GL_QUADS);
		glColor3f (1.0, 0.95, 0.95);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
	glEnd();

	glEnable(GL_LIGHTING);
}

