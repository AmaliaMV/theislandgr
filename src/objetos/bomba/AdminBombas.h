/*
 * AdminBombas.h
 *
 *  Created on: 10/02/2012
 *      Author: amalia
 */

#ifndef ADMINBOMBAS_H_
#define ADMINBOMBAS_H_

#include "BuildBomba.h"

#include <list>

class AdminBombas {
public:
	AdminBombas( const string nombreTextBomba, Fisica* fisica, const float largoCanon, const float alturaCanon  );
	void lanzarBomba( const float angVCanon, const float angHCanon, const float angBarco, const float radio );
	void dibujarBombas() const;
	void acutalizarBombas() const;
	virtual ~AdminBombas();

private:
	list<Bomba*>* bombas;
	BuildBomba* constructor;
};

#endif /* ADMINBOMBAS_H_ */
