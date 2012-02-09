/*
 * AdminCamaras.h
 *
 *  Created on: 11/01/2012
 *      Author: amalia
 */

#ifndef ADMINCAMARAS_H_
#define ADMINCAMARAS_H_

#include "../grafica/FuncOpenGL.h"

#include "Camara.h"
#include "ECamara.h"

#include <map>
#include <sstream>

using namespace std;

enum TIPO_CAMARA
{
	CAMARA_MUNDO,
	CAMARA_BARCO,
	CAMARA_CANON,
	CAMARA_CASTILLO
};

class AdminCamaras {
public:
	AdminCamaras();
	void agregarCamara ( TIPO_CAMARA idCamara, Camara* camara );
	void setCamaraActual ( TIPO_CAMARA idCamara );
	Camara* getCamaraActual() const;
	void actualizarVista();
	virtual ~AdminCamaras();

private:
	Camara *buscarCamara ( TIPO_CAMARA idCamara );

	Camara* camActual;
	map<TIPO_CAMARA, Camara* > *camaras;
};

#endif /* ADMINCAMARAS_H_ */
