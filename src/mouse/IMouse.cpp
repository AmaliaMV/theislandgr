/*
 * IMouse.cpp
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#include "IMouse.h"

IMouse::IMouse()
{
	this->anterior = new Coord2DMouse(0,0);
	this->actual = new Coord2DMouse(0,0);
}

IMouse::~IMouse()
{
	delete this->anterior;
	delete this->actual;
}

void IMouse::actualizarCooredenadas( Coord2DMouse *actual)
{
	delete this->anterior;
	this->anterior = this->actual;
	this->actual = actual;
}

bool IMouse::seMovioHaciaDerecha() const
{
	const int deltaX = this->actual->getxMouse() - this->anterior->getxMouse();

	if ( deltaX > 0 )
		return true;
	return false;
}
bool IMouse::seMovioHaciaIzquierda() const
{
	const int deltaX = this->actual->getxMouse() - this->anterior->getxMouse();

	if ( deltaX < 0 )
		return true;
	return false;

}

bool IMouse::seMovioHaciaArriba() const
{
	const int deltaY = this->actual->getyMouse() - this->anterior->getyMouse();

	if (deltaY < 0)
		return true;
	return false;
}

bool IMouse::seMovioHaciaAbajo() const
{
	const int deltaY = this->actual->getyMouse() - this->anterior->getyMouse();

	if (deltaY > 0)
		return true;
	return false;
}

