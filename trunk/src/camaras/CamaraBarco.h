/*
 * CamaraBarco.h
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#ifndef CAMARABARCO_H_
#define CAMARABARCO_H_

#include "Camara.h"
#include "ConstantesCamara.h"
#include "../matematica/Matematica.h"

#include "../objetos/TBarco.h"
#include <iostream>
using namespace std;
class CamaraBarco: public Camara {
public:
	CamaraBarco( const TBarco *tbarco );
	virtual ~CamaraBarco();

	void setEye();
	void setAt ();

	void alejarCamara();
	void acercarCamara();

private:
	const TBarco *posBarco;
};

#endif /* CAMARABARCO_H_ */
