/*
 * AcercarCamara.h
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#ifndef ACERCARCAMARA_H_
#define ACERCARCAMARA_H_

#include "Comando.h"
#include "../camaras/AdminCamaras.h"

class AcercarCamara: public Comando {
public:
	AcercarCamara(AdminCamaras* admin);
	void ejecutar();
	const string getDescripcion() const;
	virtual ~AcercarCamara();

private:
	AdminCamaras* admin;
};

#endif /* ACERCARCAMARA_H_ */
