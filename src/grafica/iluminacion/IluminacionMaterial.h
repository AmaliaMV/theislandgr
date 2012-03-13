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
	IluminacionMaterial(const float diffuseColorRed, const float diffuseColorGreen, const float diffuseColorBlue);
	void setPropiedadesMaterial();
	void setLuzAmbienteColor(const float ambientColorRed, const float ambientColorGreen, const float ambientColorBlue);
	void setLuzEspecualarColor(const float specularColorRed, const float specularColorGreen, const float specularColorBlue);
	void setLuzDifusaColor(const float diffuseColorRed, const float diffuseColorGreen, const float diffuseColorBlue);
	void setBrillo(const float shininess);
	virtual ~IluminacionMaterial();

private:
	void initColor (float color[3], const float red, const float green, const float blue);
	float *ambientColor;
	float *specularColor;
	float *diffuseColor;
	float shininess;
};

#endif /* ILUMINACIONMATERIAL_H_ */
