/*
 * PanelDibujo.cpp
 *
 *  Created on: 07/08/2011
 *      Author: amalia
 */

#include "PanelDibujo.h"

PanelDibujo::PanelDibujo(): Panel () { }

PanelDibujo::~PanelDibujo() { }

void PanelDibujo::setPanel()
{
	this->setDimensiones( TOP_VIEWA_POSX, TOP_VIEWA_POSY , (GLsizei) TOP_VIEWA_W, (GLsizei) TOP_VIEWA_H );
	Panel::setPanel();
}

void PanelDibujo::dibujarFondo()
{
	glDisable(GL_LIGHTING);

	//borde
	glLineWidth (5.0);
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.4, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
	glEnd();

	//grilla
	glLineWidth (1.0);
	glColor3f(0.5f, 0.5f, 1.0f);
	glBegin(GL_LINES);
		for (float i = 0.1; i < 1.0; i+=0.1)
		{
			glVertex3f(0.0f, i, 0.0f);
			glVertex3f(1.0f, i, 0.0f);
			glVertex3f(i, 0.0f, 0.0f);
			glVertex3f(i, 1.0f, 0.0f);
		}
	glEnd();

	//fondo
	glBegin(GL_QUADS);
		glColor3f (1.0, 0.95, 0.95);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
	glEnd();

	glEnable(GL_LIGHTING);

}

