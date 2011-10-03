/*
 * FuncOpenGL.h
 *
 *  Created on: 12/08/2011
 *      Author: amalia
 */

#ifndef FUNCOPENGL_H_
#define FUNCOPENGL_H_

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "EOpenGL.h"

class FuncOpenGL {
public:
	FuncOpenGL();

	static GLuint pedirIdDisplayList(); //solo permite pedir un id
	static void liberarIdDisplayList( GLuint id ); //solo libera un id

	virtual ~FuncOpenGL();
};

#endif /* FUNCOPENGL_H_ */
