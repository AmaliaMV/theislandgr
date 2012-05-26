/*
 * IluminacionMaterial.cpp
 *
 *  Created on: 15/02/2012
 *      Author: amalia
 */

#include "IluminacionMaterial.h"

IluminacionMaterial::IluminacionMaterial(const float diffuseColorRed, const float diffuseColorGreen, const float diffuseColorBlue)
{
	this->ambientColor = new float[3];
	this->diffuseColor = new float[3];
	this->specularColor = new float[3];
	this->shininess = 128;

	this->setLuzDifusaColor(diffuseColorRed, diffuseColorGreen, diffuseColorBlue);
	this->setLuzEspecualarColor(1.0, 1.0, 1.0);
	this->setLuzAmbienteColor(0.3, 0.3, 0.3);
}

void IluminacionMaterial::setPropiedadesMaterial()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularColor);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void IluminacionMaterial::setLuzAmbienteColor(const float ambientColorRed, const float ambientColorGreen, const float ambientColorBlue)
{
	this->initColor(this->ambientColor, ambientColorRed, ambientColorGreen, ambientColorBlue);
}

void IluminacionMaterial::setLuzEspecualarColor(const float specularColorRed, const float specularColorGreen, const float specularColorBlue)
{
	this->initColor(this->specularColor, specularColorRed, specularColorGreen, specularColorBlue);
}

void IluminacionMaterial::setLuzDifusaColor(const float diffuseColorRed, const float diffuseColorGreen, const float diffuseColorBlue)
{
	this->initColor(this->diffuseColor, diffuseColorRed, diffuseColorGreen, diffuseColorBlue);
}

void IluminacionMaterial::setBrillo(const float shininess)
{
	this->shininess = shininess;
}

IluminacionMaterial::~IluminacionMaterial()
{
	delete []this->ambientColor;
	delete []this->diffuseColor;
	delete []this->specularColor;
}

void IluminacionMaterial::initColor (float color[3], const float red, const float green, const float blue)
{
	color[LUZ_ROJA] = red;
	color[LUZ_VERDE] = green;
	color[LUZ_AZUL] = blue;
}
