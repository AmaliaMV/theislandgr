/*
 * Coord2DMouse.cpp
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#include "Coord2DMouse.h"

Coord2DMouse::Coord2DMouse() : x(0), y(0) {}
Coord2DMouse::Coord2DMouse ( int xMouse, int yMouse ) : x(xMouse), y(yMouse) {}
Coord2DMouse::~Coord2DMouse() { }
int Coord2DMouse::getxMouse () const { return this->x; }
int Coord2DMouse::getyMouse () const { return this->y; }
void Coord2DMouse::setxMouse( int x ) { this->x = x; }
void Coord2DMouse::setyMouse( int y ) { this->y = y; }
