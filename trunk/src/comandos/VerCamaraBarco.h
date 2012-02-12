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

class VerCamaraBarco: public Comando {
public:
	VerCamaraBarco(AdminCamaras* admin);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~VerCamaraBarco();

private:
	AdminCamaras* admin;
};

#endif /* VERCAMARABARCO_H_ */
