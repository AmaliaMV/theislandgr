/*
 * PanelOpciones.cpp
 *
 *  Created on: 08/08/2011
 *      Author: amalia
 */

#include "PanelOpciones.h"

PanelOpciones::PanelOpciones(): Panel() { }

PanelOpciones::~PanelOpciones() { }

void PanelOpciones::setPanel()
{
	this->setDimensiones( TOP_VIEW_OPCION_POSX, TOP_VIEW_OPCION_POSY , (GLsizei) TOP_VIEW_OPCION_W, (GLsizei) TOP_VIEW_OPCION_H );
	Panel::setPanel();
}

void PanelOpciones::dibujarFondo()
{
	string guardar, nuevo, salir;

	guardar = 	"Ctrl + G - Guardar Archivo";
	nuevo =  	"Ctrl + N - Nuevo";
	salir =  	"Q - Salir";

	glDisable(GL_LIGHTING);

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f (0.0, 0.7);
		this->escribir(nuevo.c_str());
		glRasterPos2f (0.0, 0.3);
		this->escribir(guardar.c_str());
		glRasterPos2f (0.40, 0.7);
		this->escribir(salir.c_str());

	glEnable(GL_LIGHTING);
}
