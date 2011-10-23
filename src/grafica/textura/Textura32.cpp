/*
 * Textura32.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "Textura32.h"

Textura32::Textura32(string nombreArch ): Textura ( new BMP32(nombreArch), GL_RGBA, GL_RGBA )
{

}

Textura32::~Textura32()
{

}
