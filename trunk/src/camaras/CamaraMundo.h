/*
 * CamaraMundo.h
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#ifndef CAMARAMUNDO_H_
#define CAMARAMUNDO_H_

#include "Camara.h"

#include "../matematica/Matematica.h"
#include "../objetos/ConstantesMundo.h"

#define ANGULO_MAX_TITA 89
class CamaraMundo : public Camara {
public:
	CamaraMundo();

	void setEye();
	void setAt ();
	void alejarCamara();
	void acercarCamara();

	virtual ~CamaraMundo();
};

#endif /* CAMARAMUNDO_H_ */
