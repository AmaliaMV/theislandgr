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
	cout<<"longParedX: "<<longParedX<<endl;
	cout<<"longParedY: "<<longParedY<<endl;
}

BuildLadrillo::~BuildLadrillo(){}

Ladrillo* BuildLadrillo::construirLadrilloParedFrente( Textura* textura, btBoxShape* shape, float posX, float posY, float posZ )
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

	cout<<" lo q entro: "<<posY - factorT * shape->getHalfExtentsWithMargin().getY()<<" "<<factorT<<" "<<factorX<<" "<<factorY<<endl;
	cout<<"t: "<<posY<<" largo: "<<shape->getHalfExtentsWithMargin().getY()<<" x0 "<< x0<<" xf "<<xf<<endl;

	textFrente = new Coord_text( x0, xf, y0, yf );
//	textFrente = new Coord_text ( xf, x0, yf, y0 );
//	textFrente = new Coord_text ( yf, y0, xf, x0 );

	/*calculo las coordenadas para el costado del ladrillo, el lado izquierdo*/
	x0 = getCoordTextH( posY - factorT * (shape->getHalfExtentsWithMargin().getY() + shape->getHalfExtentsWithMargin().getX()), factorT, factorX, factorY );
	xf = getCoordTextH( posY - factorT * shape->getHalfExtentsWithMargin().getY(), factorT, factorX, factorY );

	cout<<"t: "<<posY<<" largo: "<<shape->getHalfExtentsWithMargin().getY()<<" x0 "<< x0<<" xf "<<xf<<endl;

	textCostadoIzq = new Coord_text ( x0, xf, y0, yf );
//	textCostadoNeg = new Coord_text ( xf, x0, yf, y0 );
//	textCostadoNeg = new Coord_text ( yf, y0, xf, x0 );

	/*calculo las coordenadas para el costado del ladrillo, el lado derecho*/
	x0 = getCoordTextH( posY + factorT * shape->getHalfExtentsWithMargin().getY(), factorT, factorX, factorY );
	xf = getCoordTextH( posY + factorT * (shape->getHalfExtentsWithMargin().getY() + shape->getHalfExtentsWithMargin().getX()), factorT, factorX, factorY );

	cout<<"t: "<<posY<<" largo: "<<shape->getHalfExtentsWithMargin().getY()<<" x0 "<< x0<<" xf "<<xf<<endl<<endl;

	textCostadoDer = new Coord_text ( x0, xf, y0, yf );
//	textCostadoPos = new Coord_text ( xf, x0, yf, y0 );
//	textCostadoPos = new Coord_text ( yf, y0, xf, x0 );

	if ( posX > 0 )
		ladrillo = new Ladrillo ( textura, shape, posX, posY, posZ, textFrente, textFrente, textCostadoDer, textCostadoIzq );
	else
		ladrillo = new Ladrillo ( textura, shape, posX, posY, posZ, textFrente, textFrente, textCostadoIzq, textCostadoDer );

	delete textFrente;
	delete textCostadoIzq;
	delete textCostadoDer;

	return ladrillo;
}
Ladrillo* BuildLadrillo::construirLadrilloParedCostado( Textura* textura, btBoxShape* shape, float posX, float posY, float posZ )
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
	cout<<" lo q entro: "<<posX - factorT * shape->getHalfExtentsWithMargin().getX()<<" "<<factorT<<" "<<factorX<<" "<<factorY<<endl;
	cout<<"t_: "<<posX<<" largo: "<<shape->getHalfExtentsWithMargin().getX()<<" x0 "<< x0<<" xf "<<xf<<endl;

	textFrente = new Coord_text( x0, xf, y0, yf );
//	textFrente = new Coord_text( xf, x0, yf, y0 );

	/*calculo las coordenadas para el costado del ladrillo, el lado izquierdo*/
	x0 = getCoordTextH( posX - factorT * (shape->getHalfExtentsWithMargin().getX() + shape->getHalfExtentsWithMargin().getY()), factorT, factorX, factorY );
	xf = getCoordTextH( posX - factorT * shape->getHalfExtentsWithMargin().getX(), factorT, factorX, factorY );
	cout<<"t_: "<<posX<<" largo: "<<shape->getHalfExtentsWithMargin().getX()<<" x0 "<< x0<<" xf "<<xf<<endl;
	textCostadoIzq = new Coord_text ( x0, xf, y0, yf );
//	textCostadoNeg = new Coord_text ( xf, x0, yf, x0 );

	/*calculo las coordenadas para el costado del ladrillo, el lado derecho*/
	x0 = getCoordTextH( posX + factorT * shape->getHalfExtentsWithMargin().getX(), factorT, factorX, factorY );
	xf = getCoordTextH( posX + factorT * (shape->getHalfExtentsWithMargin().getX() + shape->getHalfExtentsWithMargin().getY()), factorT, factorX, factorY );
	cout<<"t_: "<<posX<<" largo: "<<shape->getHalfExtentsWithMargin().getX()<<" x0 "<< x0<<" xf "<<xf<<endl<<endl;
	textCostadoDer = new Coord_text ( x0, xf, y0, yf );
//	textCostadoPos = new Coord_text ( xf, x0, yf, y0 );

	if ( posY > 0 )
		ladrillo = new Ladrillo ( textura, shape, posX, posY, posZ, textCostadoIzq, textCostadoDer, textFrente, textFrente );
	else
		ladrillo = new Ladrillo ( textura, shape, posX, posY, posZ, textCostadoDer, textCostadoIzq, textFrente, textFrente );

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
