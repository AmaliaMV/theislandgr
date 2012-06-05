/*
 * VerCamaraMundo.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef VERCAMARAMUNDO_H_
#define VERCAMARAMUNDO_H_

#include "Comando.h"
#include "../camaras/AdminCamaras.h"
#include "../mouse/Mouse.h"

class VerCamaraMundo: public Comando {
public:
	VerCamaraMundo(AdminCamaras* admin, Mouse* mouse);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~VerCamaraMundo();

private:
	AdminCamaras* admin;
	Mouse* mouse;

};

#endif /* VERCAMARAMUNDO_H_ */
