/*
 * Mouse.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Amalia
 */

#include "Mouse.h"

const float Mouse::sensibilidad = 0.5;

Mouse::Mouse():IMouse()
{
	this->camara = 0;
}

Mouse::~Mouse() { }

void Mouse::alMoverPresionandoBoton( int xMouse, int yMouse )
{
	Coord2DMouse *actual;

	actual= new Coord2DMouse ( xMouse, yMouse );
	this->actualizarCooredenadas( actual );

	if ( this->seMovioHaciaDerecha() == true )
		camara->incAngH( sensibilidad );
	else if ( this->seMovioHaciaIzquierda() == true )
		camara->incAngH( -sensibilidad );

	if ( this->seMovioHaciaArriba() == true )
		camara->incAngV( -sensibilidad );
	else if ( this->seMovioHaciaAbajo() == true )
		camara->incAngV( sensibilidad );
}

void Mouse::alMover ( int xMouse, int yMouse )
{
	Coord2DMouse *actual = new Coord2DMouse ( xMouse, yMouse );
	this->actualizarCooredenadas( actual );
}

void Mouse::alPresionarBoton ( int button, int state, int xMouse, int yMouse )
{
}

void Mouse::setCamara(Camara* camara) { this->camara = camara; }


