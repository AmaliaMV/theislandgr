/*
 * TVelaPrincipal.cpp
 *
 *  Created on: 25/12/2011
 *      Author: amalia
 */

#include "TVelaPrincipal.h"

TVelaPrincipal::TVelaPrincipal( float centroVela, float altura ): EstrategiaTransformacion()
{
	this->CENTRO = centroVela;
	this->ALTURA = altura;
}

TVelaPrincipal::~TVelaPrincipal() {}

void TVelaPrincipal::ejecutar()
{
	glRotatef(-90, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -CENTRO, ALTURA);
}
