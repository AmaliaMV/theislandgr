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

static const string AGUA = "agua";
static const string CIELO = "cielo";
static const string MAPA = "mapa";
static const string PASTO = "pasto";
static const string SUELO = "suelo";
static const string ARENA = "arena";

static const string CLAVE_VALIDAS[] =
{
		AGUA,
		CIELO,
		MAPA,
		PASTO,
		SUELO,
		ARENA
};

static const unsigned int CANT_CLAVES = sizeof(CLAVE_VALIDAS)/sizeof(string) ;

#endif /* CLAVESVALIDAS_H_ */
