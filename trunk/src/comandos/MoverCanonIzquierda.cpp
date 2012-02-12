/*
 * MoverCanonIzquierda.cpp
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#include "MoverCanonIzquierda.h"

MoverCanonIzquierda::MoverCanonIzquierda(Canon *canon): Comando()
{
	this->canon = canon;
}

void MoverCanonIzquierda::ejecutar()
{
	this->canon->izquierda();
}
const string MoverCanonIzquierda::getDescripcion() const
{
	return "Mover Canon a la Izquierda";
}

MoverCanonIzquierda::~MoverCanonIzquierda() {}
