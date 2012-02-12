/*
 * AdminBombas.cpp
 *
 *  Created on: 10/02/2012
 *      Author: amalia
 */

#include "AdminBombas.h"

AdminBombas::AdminBombas( const string nombreTextBomba, Fisica* fisica, const float largoCanon, const float alturaCanon )
{
	bombas = new list<Bomba*>;
	constructor = new BuildBomba( nombreTextBomba, fisica, largoCanon, alturaCanon );
}

AdminBombas::~AdminBombas()
{
	delete constructor;

	list<Bomba*>::iterator itBombas = bombas->begin();

	for (; itBombas != bombas->end(); itBombas++)
	{
		delete (*itBombas);
	}

	delete bombas;
}

void AdminBombas::lanzarBomba( const float angVCanon, const float angHCanon, const float angBarco, const float radio )
{
	Bomba* bomba = constructor->construirBomba( angVCanon, angHCanon, angBarco, radio );

	bombas->push_front( bomba );
}

void AdminBombas::dibujarBombas() const
{
	list<Bomba*>::iterator itBombas = bombas->begin();

	for (; itBombas != bombas->end(); itBombas++)
	{
		(*itBombas)->dibujar();
	}
}

void AdminBombas::acutalizarBombas() const
{
	list<Bomba*>::iterator itBombas = bombas->begin();

	for (; itBombas != bombas->end(); itBombas++)
	{
		(*itBombas)->actualizar();
	}
}
