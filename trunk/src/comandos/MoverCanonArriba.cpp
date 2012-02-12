/*
 * MoverCanonArriba.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "MoverCanonArriba.h"

MoverCanonArriba::MoverCanonArriba(Canon *canon): Comando()
{
	this->canon = canon;
}

void MoverCanonArriba::ejecutar()
{
	this->canon->incAngV();
}
const string MoverCanonArriba::getDescripcion() const
{
	return "Subir Canon";
}

MoverCanonArriba::~MoverCanonArriba() {}
