/*
 * CamaraCastillo.h
 *
 *  Created on: 09/02/2012
 *      Author: amalia
 */

#ifndef CAMARACASTILLO_H_
#define CAMARACASTILLO_H_

#include "Camara.h"
#include "ConstantesCamara.h"

#include "../matematica/Matematica.h"
#include "../objetos/ConstantesMundo.h"

class CamaraCastillo : public Camara  {
public:
	CamaraCastillo();
	virtual ~CamaraCastillo();

	void setEye();
	void setAt ();
	void alejarCamara();
	void acercarCamara();

};

#endif /* CAMARACASTILLO_H_ */
