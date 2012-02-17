/*
 * IluminacionMaterial.h
 *
 *  Created on: 15/02/2012
 *      Author: amalia
 */

#ifndef ILUMINACIONMATERIAL_H_
#define ILUMINACIONMATERIAL_H_

#include "../FuncOpenGL.h"

#define LUZ_ROJA 	0
#define LUZ_VERDE 	1
#define LUZ_AZUL 	2

class IluminacionMaterial {
public:
	IluminacionMaterial(float diffuseColor[3]);
	void setPropiedadesMaterial();
	void setLuzAmbienteColor(float ambientColor[3]);
	void setLuzEspecualarColor(float specularColor[3]);
	void setLuzDifusaColor(float diffuseColor[3]);
	void setBrillo(float shininess);
	virtual ~IluminacionMaterial();

//private:
	void initColor (float color[3], const float valorCte );
	float *ambientColor;
	float *specularColor;
	float *diffuseColor;
	float shininess;
};

#endif /* ILUMINACIONMATERIAL_H_ */
