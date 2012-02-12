/*
 * VerCamaraCanon.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef VERCAMARACANON_H_
#define VERCAMARACANON_H_

#include "Comando.h"
#include "../camaras/AdminCamaras.h"

class VerCamaraCanon: public Comando {
public:
	VerCamaraCanon(AdminCamaras* admin);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~VerCamaraCanon();

private:
	AdminCamaras* admin;
};

#endif /* VERCAMARACANON_H_ */
