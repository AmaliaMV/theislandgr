/*
 * PisoDeMirador.h
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#ifndef PISODEMIRADOR_H_
#define PISODEMIRADOR_H_

#include "BordePisoMirador.h"

#include "../../geometricos/CirculoConTextura.h"
#include "../../../grafica/iluminacion/IluminacionMaterial.h"

class PisoDeMirador: public ObjetoDibujable {
public:
	PisoDeMirador(const string nombreTexturaBorde, const string nombreTexturaPiso, const float radio);
	virtual ~PisoDeMirador();

private:
	void displayList() const;

	/*para el dibujo*/
	void inicializarObjetos(const string nombreTexturaBorde, const string nombreTexturaPiso, const float radio);
	void eliminarObjetos();
	float RADIO;
	float ESPESOR;

	CirculoConTextura *piso;
	BordePisoMirador *borde;

	static const unsigned int PASO = 30;

	/*para la iluminacion*/
	IluminacionMaterial* luz;
	void inicializarLuces();
	void eliminarLuces();
};

#endif /* PISODEMIRADOR_H_ */
