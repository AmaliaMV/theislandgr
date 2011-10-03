/*
 * FuncOpenGL.cpp
 *
 *  Created on: 12/08/2011
 *      Author: amalia
 */

#include "FuncOpenGL.h"

GLuint FuncOpenGL::pedirIdDisplayList()
{
	GLuint dl_base = glGenLists(1);

	if ( dl_base == 0 )
		throw new EOpenGL("Error al invocar glGenLists");

	return dl_base;
}

void FuncOpenGL::liberarIdDisplayList( GLuint id )
{
	glDeleteLists( id, 1 );
}

FuncOpenGL::FuncOpenGL() {
	// TODO Auto-generated constructor stub

}

FuncOpenGL::~FuncOpenGL() {
	// TODO Auto-generated destructor stub
}
