/*
 * CilindroConTextura.cpp
 *
 *  Created on: 01/01/2012
 *      Author: amalia
 */

#include "CilindroConTextura.h"

CilindroConTextura::CilindroConTextura( string nombreTextura, float radio, float altura )
	:ObjetoDibujable()
{
	this->lado = new LadoCilindroConTextura( nombreTextura, radio, altura );
	this->tapa = new CirculoConTextura ( nombreTextura, radio );
	this->ALTURA = altura;

	this->compilarDisplayList();
}

CilindroConTextura::~CilindroConTextura()
{
	delete this->lado;
	delete this->tapa;
}

void CilindroConTextura::displayList() const
{
	this->lado->dibujar();
	this->tapa->dibujar();
	glPushMatrix();
		glTranslatef( 0.0, 0.0, this->ALTURA );
		this->tapa->dibujar();
	glPopMatrix();
}
