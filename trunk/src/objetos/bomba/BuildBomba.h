/*
 * BuildBomba.h
 *
 *  Created on: 10/02/2012
 *      Author: amalia
 */

#ifndef BUILDBOMBA_H_
#define BUILDBOMBA_H_

#include "Bomba.h"

class BuildBomba {
public:
	BuildBomba( const string nombreTextBomba, Fisica* fisica, const float largoCanon, const float alturaCanon  );
	Bomba* construirBomba( const float angVCanon, const float angHCanon, const float angBarco, const float radio ) const;
	virtual ~BuildBomba();

private:
	Textura* textura;
	btSphereShape* shapeBomba;
	Fisica* fisica;
	float largoCanon;
	float alturaCanon;
};

#endif /* BUILDBOMBA_H_ */
