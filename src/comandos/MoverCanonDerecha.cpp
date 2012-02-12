/*
 * MoverCanonDerecha.cpp
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#include "MoverCanonDerecha.h"

MoverCanonDerecha::MoverCanonDerecha(Canon *canon): Comando()
{
	this->canon = canon;
}

void MoverCanonDerecha::ejecutar()
{
	this->canon->derecha();
}
const string MoverCanonDerecha::getDescripcion() const
{
	return "Mover Canon a la Derecha";
}

MoverCanonDerecha::~MoverCanonDerecha() {}
