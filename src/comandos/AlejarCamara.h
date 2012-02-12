/*
 * AlejarCamara.h
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#ifndef ALEJARCAMARA_H_
#define ALEJARCAMARA_H_

#include "Comando.h"
#include "../camaras/AdminCamaras.h"

class AlejarCamara: public Comando {
public:
	AlejarCamara(AdminCamaras* admin);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~AlejarCamara();

private:
	AdminCamaras* admin;
};

#endif /* ALEJARCAMARA_H_ */
