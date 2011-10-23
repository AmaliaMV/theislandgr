/*
 * Palmera.cpp
 *
 *  Created on: 10/X09/2011
 *      Author: amalia
 */

#include "Palmera.h"

Palmera::Palmera( string nombreTextura ):ObjetoDibujable ( new Textura32(nombreTextura) )
{
	this->displayList(  );
}

void Palmera::displayList( )
{
	const float tamY = 10.0;
	const float tamX = tamY * 480.0 /1024.0;


	float ptos[4][3] = { { 0.0,  tamX, 0.0 },
						{ 0.0, -tamX, 0.0 },
						{ 0.0, -tamX, tamY },
						{ 0.0,  tamX, tamY }
	};

//	float coordText[4][2] = { { 0.0, 340.0 /1024.0 },
//							  { 1.0, 340.0 /1024.0 },
//							  { 1.0, 674.0 /1024.0 },
//							  { 0.0, 674.0 /1024.0 }// hardcode
	float coordText[4][2] = { { 340.0 /1024.0, 0.0 },
							  { 674.0 /1024.0, 0.0 },
							  { 674.0 /1024.0, 1.0 },
							  { 340.0 /1024.0, 1.0 }
	};

	GLuint vertIndice[4] = { 0, 1, 2, 3 };

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(CteObjeto::CANT_COORD_PTO, GL_FLOAT, 0, ptos);
		glTexCoordPointer(CteObjeto::CANT_COORD_TEXTURA, GL_FLOAT, 0, coordText);

		glNewList(this->getIdDisplayList(), GL_COMPILE);

			glEnable( GL_BLEND );
				glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glColor4f ( 1.0, 1.0, 1.0, 1.0 );
				Textura::habilitar();
					this->getTextura()->usar();
					glDrawElements (GL_QUADS, 4 , GL_UNSIGNED_INT, vertIndice);
				Textura::deshabilitar();
			glDisable( GL_BLEND );

		glEndList();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

Palmera::~Palmera()
{

}

void Palmera::dibujar()
{
	glPushMatrix();
//		glRotatef(10, 0.0, 0.0, 1.0);
//		ObjetoDibujable::dibujar();
		glRotatef(45, 0.0, 0.0, 1.0);
		ObjetoDibujable::dibujar();
//		glRotatef(45, 0.0, 0.0, 1.0);
		ObjetoDibujable::dibujar();
//		glRotatef(45, 0.0, 0.0, 1.0);
//		ObjetoDibujable::dibujar();
	glPopMatrix();
}
