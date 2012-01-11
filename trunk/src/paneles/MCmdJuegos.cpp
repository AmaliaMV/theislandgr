/*
 * MCmdJuegos.cpp
 *
 *  Created on: 10/01/2012
 *      Author: amalia
 */

#include "MCmdJuegos.h"

MCmdJuegos::MCmdJuegos( string nomTextMenu  )
{
	TOP_VIEW_POSX = TOP_VIEW_W = TOP_VIEW_POSY = TOP_VIEW_H = 0.0;
	menu = new RectanguloConTextura ( nomTextMenu, 2.0, 2.0 );
}

MCmdJuegos::~MCmdJuegos()
{
	delete menu;
}
void MCmdJuegos::dibujarPanel( float anchoPantalla, float altoPantalla )
{
	TOP_VIEW_POSX = anchoPantalla * 0.10;
	TOP_VIEW_W = anchoPantalla * 0.80;
	TOP_VIEW_POSY = altoPantalla * 0.10;
	TOP_VIEW_H = altoPantalla * 0.80;

	glViewport ( (int) TOP_VIEW_POSX, (int) TOP_VIEW_POSY, (GLsizei) TOP_VIEW_W, (GLsizei) TOP_VIEW_H );
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
	gluOrtho2D( -TOP_VIEW_W / 2, TOP_VIEW_W / 2, -TOP_VIEW_H / 2, TOP_VIEW_H / 2);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glScalef(TOP_VIEW_W / 2, TOP_VIEW_H / 2, 1.0 );
	menu->dibujar();
	glPopMatrix();
	glEnable(GL_LIGHTING);

}
