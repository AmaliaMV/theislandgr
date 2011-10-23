/*
 * ClavesValidas.h
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#ifndef CLAVESVALIDAS_H_
#define CLAVESVALIDAS_H_

#include <string>
using namespace std;

static const string AGUA = "AGUA";
static const string CIELO = "CIELO";
static const string MAPA = "MAPA";
static const string PASTO = "PASTO";
static const string SUELO = "SUELO";
static const string ARENA = "ARENA";
static const string PALMERA = "PALMERA";

static const string CLAVE_VALIDAS[] =
{
		AGUA,
		CIELO,
		MAPA,
		PASTO,
		SUELO,
		ARENA,
		PALMERA
};

static const unsigned int CANT_CLAVES = sizeof(CLAVE_VALIDAS)/sizeof(string) ;

#endif /* CLAVESVALIDAS_H_ */
