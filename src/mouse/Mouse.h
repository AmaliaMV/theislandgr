/*
 * Mouse.h
 *
 *  Created on: 21/04/2011
 *      Author: Amalia
 */

#ifndef MOUSE_H_
#define MOUSE_H_

#include "IMouse.h"
#include "../camaras/Camara.h"

class Mouse : public IMouse {
public:
	Mouse();
	void alMover ( int xMouse, int yMouse );
	void alMoverPresionandoBoton( int xMouse, int yMouse );
	void alPresionarBoton ( int button, int state, int xMouse, int yMouse );

	void setCamara(Camara *camara);
	virtual ~Mouse();

private:
	Camara *camara;
	static const float sensibilidad;
};

#endif /* MOUSE_H_ */
