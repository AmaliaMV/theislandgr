/*
 * VerCamaraBarco.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef VERCAMARABARCO_H_
#define VERCAMARABARCO_H_

#include "Comando.h"
#include "../camaras/AdminCamaras.h"
#include "../mouse/Mouse.h"

class VerCamaraBarco: public Comando {
public:
	VerCamaraBarco(AdminCamaras* admin, Mouse* mouse);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~VerCamaraBarco();

private:
	AdminCamaras* admin;
	Mouse* mouse;
};

#endif /* VERCAMARABARCO_H_ */
