/*
 * VerCamaraCastillo.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef VERCAMARACASTILLO_H_
#define VERCAMARACASTILLO_H_

#include "Comando.h"
#include "../camaras/AdminCamaras.h"
#include "../mouse/Mouse.h"

class VerCamaraCastillo: public Comando {
public:
	VerCamaraCastillo(AdminCamaras* admin, Mouse* mouse);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~VerCamaraCastillo();

private:
	AdminCamaras* admin;
	Mouse* mouse;
};

#endif /* VERCAMARACASTILLO_H_ */
