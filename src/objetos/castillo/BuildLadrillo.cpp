/*
 * BuildLadrillo.cpp
 *
 *  Created on: 27/01/2012
 *      Author: amalia
 */

#include "BuildLadrillo.h"

BuildLadrillo::BuildLadrillo( float longParedX, float longParedY, float longParedZ )
{
	this->longParedX = longParedX;
	this->longParedY = longParedY;
	this->longParedZ = longParedZ;
}

BuildLadrillo::~BuildLadrillo(){}

Ladrillo* BuildLadrillo::construirLadrilloParedFrente( Textura* textura, btBoxShape* shape, float posX, float posY, float posZ, float desplaY )
{
	/* construir ladrillo frente pared => x = cte */
	float x0, xf, y0, yf, factorX, factorY;
	int factorT;
	Coord_text *textFrente, *textCostadoDer, *textCostadoIzq;
	Ladrillo *ladrillo;

	if ( posX > 0 )
	{
		factorT = 1;
		factorX = (float)1/2;
		factorY = 0;
	}
	else
	{
		factorT = -1;
		factorX = (float)3/2;
		factorY = 1;
	}

	/*primero calculo las coordenadas de la textura para el frente del ladrillo*/
	x0 = getCoordTextH( posY - factorT * shape->getHalfExtentsWithMargin().getY(), factorT, factorX, factorY ); //TODO cambiar los getY en la parte de abajo
	xf = getCoordTextH( posY + factorT * shape->getHalfExtentsWithMargin().getY(), factorT, factorX, factorY );
	y0 = getCoordTextV( posZ - shape->getHalfExtentsWithMargin().getZ() );
	yf = getCoordTextV( posZ + shape->getHalfExtentsWithMargin().getZ() );

	textFrente = new Coord_text( x0, xf, y0, yf );

	/*calculo las coordenadas para el costado del ladrillo, el lado izquierdo*/
	x0 = getCoordTextH( posY - factorT * (shape->getHalfExtentsWithMargin().getY() + shape->getHalfExtentsWithMargin().getX()*2), factorT, factorX, factorY );
	xf = getCoordTextH( posY - factorT * shape->getHalfExtentsWithMargin().getY(), factorT, factorX, factorY );

	textCostadoIzq = new Coord_text ( x0, xf, y0, yf );

	/*calculo las coordenadas para el costado del ladrillo, el lado derecho*/
	x0 = getCoordTextH( posY + factorT * shape->getHalfExtentsWithMargin().getY(), factorT, factorX, factorY );
	xf = getCoordTextH( posY + factorT * (shape->getHalfExtentsWithMargin().getY() + shape->getHalfExtentsWithMargin().getX()*2), factorT, factorX, factorY );

	textCostadoDer = new Coord_text ( x0, xf, y0, yf );

	if ( posX > 0 )
		ladrillo = new Ladrillo ( textura, shape, posX, posY + desplaY, posZ, textFrente, textFrente, textCostadoDer, textCostadoIzq );
	else
		ladrillo = new Ladrillo ( textura, shape, posX, posY + desplaY, posZ, textFrente, textFrente, textCostadoIzq, textCostadoDer );

	delete textFrente;
	delete textCostadoIzq;
	delete textCostadoDer;

	return ladrillo;
}
Ladrillo* BuildLadrillo::construirLadrilloParedCostado( Textura* textura, btBoxShape* shape, float posX, float posY, float posZ, float desplaY )
{
	/* construir ladrillo frente pared => y = cte */
	float x0, xf, y0, yf, factorX, factorY;
	int factorT;
	Coord_text *textFrente, *textCostadoDer, *textCostadoIzq;
	Ladrillo *ladrillo;

	if ( posY > 0 )
	{
		factorT = -1;
		factorX = 1;
		factorY = (float)1/2;
	}
	else
	{
		factorT = 1;
		factorX = 2;
		factorY = (float)3/2;
	}

	/*primero calculo las coordenadas de la textura para el frente del ladrillo*/
	x0 = getCoordTextH( posX - factorT * shape->getHalfExtentsWithMargin().getX(), factorT, factorX, factorY );
	xf = getCoordTextH( posX + factorT * shape->getHalfExtentsWithMargin().getX(), factorT, factorX, factorY );
	y0 = getCoordTextV( posZ - shape->getHalfExtentsWithMargin().getZ() );
	yf = getCoordTextV( posZ + shape->getHalfExtentsWithMargin().getZ() );

	textFrente = new Coord_text( x0, xf, y0, yf );

	/*calculo las coordenadas para el costado del ladrillo, el lado izquierdo*/
	x0 = getCoordTextH( posX - factorT * (shape->getHalfExtentsWithMargin().getX() + shape->getHalfExtentsWithMargin().getY()*2), factorT, factorX, factorY );
	xf = getCoordTextH( posX - factorT * shape->getHalfExtentsWithMargin().getX(), factorT, factorX, factorY );

	textCostadoIzq = new Coord_text ( x0, xf, y0, yf );


	/*calculo las coordenadas para el costado del ladrillo, el lado derecho*/
	x0 = getCoordTextH( posX + factorT * shape->getHalfExtentsWithMargin().getX(), factorT, factorX, factorY );
	xf = getCoordTextH( posX + factorT * (shape->getHalfExtentsWithMargin().getX() + shape->getHalfExtentsWithMargin().getY()*2), factorT, factorX, factorY );

	textCostadoDer = new Coord_text ( x0, xf, y0, yf );


	if ( posY > 0 )
		ladrillo = new Ladrillo ( textura, shape, posX, posY + desplaY, posZ, textCostadoIzq, textCostadoDer, textFrente, textFrente );
	else
		ladrillo = new Ladrillo ( textura, shape, posX, posY + desplaY, posZ, textCostadoDer, textCostadoIzq, textFrente, textFrente );

	delete textFrente;
	delete textCostadoIzq;
	delete textCostadoDer;

	return ladrillo;
}

float BuildLadrillo::getCoordTextH ( float t, int factorT, float factorLongX, float factorLongY )
{
	return ( t * factorT + longParedX * factorLongX + longParedY * factorLongY ) / ( 2 * (longParedX + longParedY) );
}

float BuildLadrillo::getCoordTextV ( float t )
{
	return ( t / longParedZ );
}
