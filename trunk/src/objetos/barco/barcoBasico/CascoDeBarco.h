/*
 * CascoDeBarco.h
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#ifndef CASCODEBARCO_H_
#define CASCODEBARCO_H_

#include "../ConstantesBarco.h"

#include "../../ODTextura.h"

#include "../../../grafica/textura/Textura24.h"
#include "../../../matematica/Matematica.h"

class CascoDeBarco: public ODTextura
{
public:

	CascoDeBarco( string nombreTextura );
	virtual ~CascoDeBarco();

protected:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

private:
	static const int cantPasosFi;
	static const int cantPasosTita;
};

#endif /* CASCODEBARCO_H_ */
