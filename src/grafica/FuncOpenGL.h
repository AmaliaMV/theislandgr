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
	static GLuint pedirIdDisplayList(); //solo permite pedir un id
	static void liberarIdDisplayList( GLuint id ); //solo libera un id

	virtual ~FuncOpenGL();

private:
	FuncOpenGL();

};

class  Coord_text {
public:
	Coord_text(): xmin(0), xmax(1.0), ymin(0.0), ymax(1.0) {}
	Coord_text(float _xmin, float _xmax, float _ymin, float _ymax): xmin(_xmin), xmax(_xmax), ymin(_ymin), ymax(_ymax){};
	Coord_text( Coord_text *coord_text)
	{
		xmin = coord_text->xmin;
		xmax = coord_text->xmax;
		ymin = coord_text->ymin;
		ymax = coord_text->ymax;
	}
	virtual ~Coord_text(){};
	float xmin;
	float xmax;
	float ymin;
	float ymax;
};


#endif /* FUNCOPENGL_H_ */
