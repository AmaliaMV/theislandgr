/*
 * BuildBomba.cpp
 *
 *  Created on: 10/02/2012
 *      Author: amalia
 */

#include "BuildBomba.h"

BuildBomba::BuildBomba( const string nombreTextBomba, Fisica* fisica )
{
	this->textura = new Textura24 ( nombreTextBomba );
	this->shapeBomba = new btSphereShape(0.25);
	this->fisica = fisica;

	this->fisica->addCollisionShape( this->shapeBomba );
}

BuildBomba::~BuildBomba()
{
	delete textura;
}

Bomba* BuildBomba::construirBomba( const float angVCanon, const float angHCanon, const float angBarco, const float radio ) const
{
	Bomba* bomba;
	float x, y, z, fx, fy, longCanon = 5, alturaCanon = 3.09;

	x = - longCanon * Matematica::cosHex ( angHCanon ) * Matematica::cosHex ( angVCanon );
	y = - longCanon * Matematica::sinHex ( angHCanon ) * Matematica::cosHex ( angVCanon );

	fx = radio * Matematica::cosHex( angBarco ) + x * Matematica::cosHex( angBarco ) - y * Matematica::sinHex( angBarco );
	fy = radio * Matematica::sinHex( angBarco ) + y * Matematica::cosHex( angBarco ) + x * Matematica::sinHex( angBarco );

	z = alturaCanon + longCanon * Matematica::sinHex ( angVCanon );

	cout<<" x: "<<fx<<" y: "<<fy<<" z: "<<z<<endl;
	bomba = new Bomba( textura, shapeBomba, fx, fy, z, angHCanon, angVCanon, angBarco, radio );
	bomba->agregarseAlMundo( fisica->getMundoFisico() );

	return bomba;
}
