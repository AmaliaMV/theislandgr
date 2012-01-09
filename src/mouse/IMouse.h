/*
 * IMouse.h
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#ifndef IMOUSE_H_
#define IMOUSE_H_

#include "Coord2DMouse.h"

class IMouse {
public:
	IMouse();
	virtual void alMoverPresionandoBoton ( int xMouse, int yMouse ) = 0 ;
	virtual void alMover ( int xMouse, int yMouse ) = 0 ;
	virtual void alPresionarBoton ( int button, int state, int xMouse, int yMouse ) = 0;

	virtual bool seMovioHaciaDerecha() const; // retorna true si el mouse se desplazó hacia la derecha, false en caso contrario
	virtual bool seMovioHaciaIzquierda() const;
	virtual bool seMovioHaciaArriba() const;  // retorna true si el mouse se desplazó hacia arriba, false en caso contrario.
	virtual bool seMovioHaciaAbajo() const;

	virtual ~IMouse();

protected:
	void actualizarCooredenadas( Coord2DMouse *actual);

private:
	Coord2DMouse *anterior;
	Coord2DMouse *actual;
};

#endif /* IMOUSE_H_ */
