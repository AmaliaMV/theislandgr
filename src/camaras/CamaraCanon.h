/*
 * CamaraCanon.h
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#ifndef CAMARACANON_H_
#define CAMARACANON_H_

#include "Camara.h"

#include "../objetos/TBarco.h"
#include "../objetos/barco/TCanon.h"

class CamaraCanon: public Camara {
public:
	CamaraCanon(const TBarco *tbarco, const TCanon *tcanon);
	virtual ~CamaraCanon();

	void setEye();
	void setAt();

private:
	const TBarco *posBarco;
	const TCanon *posCanon;
};

#endif /* CAMARACANON_H_ */
