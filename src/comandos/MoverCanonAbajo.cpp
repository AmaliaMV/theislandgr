/*
 * MoverCanonAbajo.cpp
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#include "MoverCanonAbajo.h"

MoverCanonAbajo::MoverCanonAbajo(Canon *canon): Comando()
{
	this->canon = canon;
}

void MoverCanonAbajo::ejecutar()
{
	this->canon->decAngV();
}
const string MoverCanonAbajo::getDescripcion() const
{
	return "Bajar Canon";
}

MoverCanonAbajo::~MoverCanonAbajo() {}
