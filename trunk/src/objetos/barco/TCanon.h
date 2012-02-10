/*
 * TCanon.h
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#ifndef TCANON_H_
#define TCANON_H_

#include "TCajaCanon.h"
#include "canon/Canon.h"

class TCanon: public EstrategiaTransformacion {
public:
	TCanon( const Canon *canon, TCajaCanon *tcaja );
	void ejecutar();
	const Canon* getCanon() const;
	float getAltura() const;
	virtual ~TCanon();

private:
	void getTPto ( const float x, const float y, const float z, float &fx, float &fy, float &fz ) const;

	const Canon *canon;
	TCajaCanon *tcaja;
};

#endif /* TCANON_H_ */
