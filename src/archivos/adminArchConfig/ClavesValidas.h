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
static const string CANON_TEXTURA = "CANON_TEXTURA";
static const string CANON_PTOS = "CANON_PTOS";
static const string CAJA_CANON = "CAJA_CANON";
static const string BAUPRES_TEXTURA = "BAUPRES_TEXTURA";
static const string BAUPRES_PTOS = "BAUPRES_PTOS";
static const string PISO_BARCO = "PISO_BARCO";
static const string CASCO_BARCO = "CASCO_BARCO";
static const string BARANDA_BARCO = "BARANDA_BARCO";
static const string PALO_BARCO = "PALO_BARCO";
static const string TELA_VELA = "TELA_VELA";
static const string PALO_VELA = "PALO_VELA";

static const string CLAVE_VALIDAS[] =
{
		AGUA,
		CIELO,
		MAPA,
		PASTO,
		SUELO,
		ARENA,
		PALMERA,
		CANON_TEXTURA,
		CANON_PTOS,
		CAJA_CANON,
		BAUPRES_TEXTURA,
		BAUPRES_PTOS,
		PISO_BARCO,
		CASCO_BARCO,
		BARANDA_BARCO,
		PALO_BARCO,
		TELA_VELA,
		PALO_VELA
};

static const unsigned int CANT_CLAVES = sizeof(CLAVE_VALIDAS)/sizeof(string) ;

#endif /* CLAVESVALIDAS_H_ */
