/*
 * CilindroConTextura.h
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#ifndef LADOCILINDROCONTEXTURA_H_
#define LADOCILINDROCONTEXTURA_H_

#include "../ODTextura.h"

#include "../../grafica/textura/Textura24.h"

class LadoCilindroConTextura: public ODTextura {
public:
	LadoCilindroConTextura(string nombreTextura, float radio, float altura);
	virtual ~LadoCilindroConTextura();

	float getAltura() const;
	float getRadio() const;

protected:
	void displayList() const;

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();
	void generarNormales();

	float RADIO;
	float ALTURA;

	static const unsigned int PASO = 30;
};

#endif /* CILINDROCONTEXTURA_H_ */
