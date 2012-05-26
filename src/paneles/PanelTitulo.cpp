/*
 * PanelTitulo.cpp
 *
 *  Created on: 08/08/2011
 *      Author: amalia
 */

#include "PanelTitulo.h"

PanelTitulo::PanelTitulo() : Panel() { }

PanelTitulo::~PanelTitulo() { }

void PanelTitulo::setPanel()
{
	this->setDimensiones( TOP_VIEW_TITULO_POSX, TOP_VIEW_TITULO_POSY , (GLsizei) TOP_VIEW_TITULO_W, (GLsizei) TOP_VIEW_TITULO_H );
	Panel::setPanel();
}

void PanelTitulo::dibujarFondo()
{
	string titulo;

	titulo = 	"GENERADOR DE ISLAS";

	glDisable(GL_LIGHTING);

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f (0.35, 0.4);
		this->escribir(titulo.c_str());

	glEnable(GL_LIGHTING);
}

void PanelTitulo::fondoNombreArchivo()
{
	string aux = "Nombre del archivo (sin extesion): ";

	glDisable(GL_LIGHTING);

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f (0.05, 0.8);
		this->escribir(aux.c_str());

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f (0.05, 0.4);
		this->escribir(this->nombreArch.c_str());

	glEnable(GL_LIGHTING);
}
void PanelTitulo::borrarNombreArch()
{
	this->nombreArch = "";
}

void PanelTitulo::setNombreArch(string nombre)
{
	this->nombreArch = nombre;
}
