/*
 * IluminacionMaterial.cpp
 *
 *  Created on: 15/02/2012
 *      Author: amalia
 */

#include "IluminacionMaterial.h"

IluminacionMaterial::IluminacionMaterial(float diffuseColor[3])
{
	this->ambientColor = new float[3];
	this->initColor(this->ambientColor, 0.8);
	this->diffuseColor = diffuseColor;
	this->specularColor = new float[3];
	this->initColor(this->specularColor, 1.0);
	this->shininess = 10;
}

void IluminacionMaterial::setPropiedadesMaterial()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularColor);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void IluminacionMaterial::setLuzAmbienteColor(float ambientColor[3])
{
	delete []this->ambientColor;
	this->ambientColor = ambientColor;
}

void IluminacionMaterial::setLuzEspecualarColor(float specularColor[3])
{
	delete []this->specularColor;
	this->specularColor = specularColor;
}

void IluminacionMaterial::setLuzDifusaColor(float diffuseColor[3])
{
	delete []this->diffuseColor;
	this->diffuseColor = diffuseColor;
}

void IluminacionMaterial::setBrillo(float shininess)
{
	this->shininess = shininess;
}

IluminacionMaterial::~IluminacionMaterial()
{
	delete []this->ambientColor;
	delete []this->diffuseColor;
	delete []this->specularColor;
}

void IluminacionMaterial::initColor (float color[3], const float valorCte )
{
	for ( unsigned int i = 0; i < 3; i++ )
		color[i] = valorCte;
}
