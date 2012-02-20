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
	ODTextura( Textura *textura, bool compartida = false ); /* Textura = del objeto */
	virtual ~ODTextura();

protected:
	const Textura* getTextura() const;
	void init( unsigned int cantPtos, unsigned int tamIndice, GLenum mode, bool compilarNormales=false ); //debe ser llamado por las clases hijas
	void compilarNormales();
	void noCompilarNormales();

	virtual void generarCoordPtos() = 0;
	virtual void generarIndice() = 0;
	virtual void generarCoodText() = 0;
	virtual void generarNormales(){};

	virtual void displayList() const;

	unsigned int getCantPtos() const;
	unsigned int getCantTamIndice() const;
	GLenum getModo() const;

	float *ptos;
	float *text;
	float *normales;
	unsigned int *indice;

private:
	Textura *textura;
	unsigned int tamIndice;
	unsigned int cantPtos;
	GLenum mode;
	bool compartida;
};

#endif /* ODTEXTURA_H_ */
