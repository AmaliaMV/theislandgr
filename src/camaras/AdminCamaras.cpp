/*
 * AdminCamaras.cpp
 *
 *  Created on: 11/01/2012
 *      Author: amalia
 */

#include "AdminCamaras.h"

AdminCamaras::AdminCamaras()
{
	camaras = new map<TIPO_CAMARA, Camara*>();
}

AdminCamaras::~AdminCamaras()
{
	map<TIPO_CAMARA, Camara* >::iterator it = camaras->begin();

	for( ; it != camaras->end() ; it++ )
	 	 delete (*it).second;

	delete camaras;
}

void AdminCamaras::agregarCamara ( TIPO_CAMARA idCamara, Camara* camara )
{
	if ( this->buscarCamara( idCamara ) != NULL )
	{
		throw new ECamara ("Ya se encuentra en uso el identificador de camara: " + idCamara );
	}

	camaras->insert(pair<TIPO_CAMARA, Camara*>(idCamara, camara));
}

void AdminCamaras::setCamaraActual ( TIPO_CAMARA idCamara )
{
	Camara *camara;

	if ( (camara = this->buscarCamara( idCamara )) == NULL )
	{
		stringstream mensaje;
		mensaje << "El identificador de camara: ";
		mensaje<< idCamara;
		mensaje<< " no esta en uso.";

		throw new ECamara ( mensaje.str() );
	}

	camActual = camara;
}

void AdminCamaras::actualizarVista()
{
	camActual->setEye();
	camActual->setAt();

	gluLookAt (camActual->getEye()[0], camActual->getEye()[1], camActual->getEye()[2],
			   camActual->getAt()[0], camActual->getAt()[1], camActual->getAt()[2],
			   camActual->getUp()[0], camActual->getUp()[1], camActual->getUp()[2]
			   );
}

Camara* AdminCamaras::getCamaraActual() const
{
	return camActual;
}

Camara* AdminCamaras::buscarCamara ( TIPO_CAMARA idCamara )
{
	map<TIPO_CAMARA, Camara* >::iterator it = camaras->begin();

	 for( ; it != camaras->end() ; it++ )
	 {
		 if ( (*it).first == idCamara )
			 return (*it).second;
	 }

	 return NULL;
}
