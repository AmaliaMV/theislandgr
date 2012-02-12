/*
 * BuildBomba.cpp
 *
 *  Created on: 10/02/2012
 *      Author: amalia
 */

#include "BuildBomba.h"

BuildBomba::BuildBomba( const string nombreTextBomba, Fisica* fisica, const float largoCanon, const float alturaCanon  )
{
	this->largoCanon = largoCanon;
	this->alturaCanon = alturaCanon;
	this->textura = new Textura24 ( nombreTextBomba );
	this->shapeBomba = new btSphereShape(0.15);
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
	float x, y, z, fx, fy;

	x = largoCanon * Matematica::cosHex ( angHCanon ) * Matematica::cosHex ( 180-angVCanon ) ;
	y = largoCanon * Matematica::sinHex ( angHCanon ) * Matematica::cosHex ( 180-angVCanon ) * 0.40 /*fact de correccion por el escalado del barco*/;;

	fx = radio * Matematica::cosHex( angBarco ) + x * Matematica::cosHex( angBarco ) - y * Matematica::sinHex( angBarco );
	fy = radio * Matematica::sinHex( angBarco ) + y * Matematica::cosHex( angBarco ) + x * Matematica::sinHex( angBarco );

	z = alturaCanon + largoCanon * Matematica::sinHex ( 180-angVCanon )*0.45/*fact de correccion por el escalado del barco*/;

	bomba = new Bomba( textura, shapeBomba, fx, fy, z, angHCanon, 180-angVCanon, angBarco, radio );
	bomba->agregarseAlMundo( fisica->getMundoFisico() );

	return bomba;
}
