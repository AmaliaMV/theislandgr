/*
 * Textura.cpp
 *
 *  Created on: 30/05/2011
 *      Author: Amalia
 */

#include "Textura24.h"

Textura24::Textura24( string nombreArch ): Textura ( new BMP24(nombreArch), GL_RGB, GL_RGB )
{
}

Textura24::~Textura24()
{

}
