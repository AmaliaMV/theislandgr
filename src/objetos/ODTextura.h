/*
 * ObjetoDibujable.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef ODTEXTURA_H_
#define ODTEXTURA_H_

#include "../grafica/textura/Textura.h"
#include "../grafica/FuncOpenGL.h"

#include "../matematica/Matematica.h"

#include "../ConstantesObjeto.h"

#include "ObjetoDibujable.h"

#define GIRO_COMPLETO		360.0f

using namespace std;

class ODTextura: public ObjetoDibujable {
public:
	ODTextura( Textura *textura ); /* Textura = del objeto */
	virtual ~ODTextura();

protected:
	const Textura* getTextura() const;
	void init( unsigned int cantPtos, unsigned int tamIndice, GLenum mode ); //debe ser llamado por las clases hijas

	virtual void generarCoordPtos() = 0;
	virtual void generarIndice() = 0;
	virtual void generarCoodText() = 0;

	virtual void displayList() const;

	unsigned int getCantPtos() const;
	unsigned int getCantTamIndice() const;

	float *ptos;
	float *text;
	unsigned int *indice;

private:
	Textura *textura;
	unsigned int tamIndice;
	unsigned int cantPtos;
	GLenum mode;
};

#endif /* ODTEXTURA_H_ */
