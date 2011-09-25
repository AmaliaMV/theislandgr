/*
 * Dimensiones.h
 *
 *  Created on: 07/08/2011
 *      Author: amalia
 */

#ifndef DIMENSIONES_H_
#define DIMENSIONES_H_

#include "TamanoPantalla.h"

#define MARGEN_X				0.01f
#define MARGEN_Y				0.15f
#define TAM_PRINCIPAL_W			0.70f

#define W_WIDTH 				TamanoPantalla::getAncho()
#define W_HEIGHT 				TamanoPantalla::getAlto()

// posiciones de la ventana donde se dibujan los ptos de control
#define TOP_VIEWA_POSX			((int)((float)W_WIDTH*MARGEN_X))
#define TOP_VIEWA_W				((int)((float)W_WIDTH*TAM_PRINCIPAL_W))
#define TOP_VIEWA_POSY			((int)((float)W_HEIGHT*MARGEN_Y))
#define TOP_VIEWA_H				((int)((float)W_HEIGHT*TAM_PRINCIPAL_W))

//posiciones de la ventana donde aparecen las coordenadas X,Y
#define TOP_VIEW_LETRA_POSX 	TOP_VIEWA_POSX + TOP_VIEWA_W
#define TOP_VIEW_LETRA_W		((int)((float)W_WIDTH*( 1.0 - TAM_PRINCIPAL_W - 2 * MARGEN_X )))
#define TOP_VIEW_LETRA_POSY		((int)((float)W_HEIGHT*MARGEN_Y))
#define TOP_VIEW_LETRA_H		((int)((float)W_HEIGHT*TAM_PRINCIPAL_W))

//posiciones de la ventana donde figuran las opciones
#define TOP_VIEW_OPCION_POSX 	TOP_VIEWA_POSX
#define TOP_VIEW_OPCION_W		((int)((float)W_WIDTH*( 1.0 - 2 * MARGEN_X )))
#define TOP_VIEW_OPCION_POSY	0
#define TOP_VIEW_OPCION_H		((int)((float)W_HEIGHT*MARGEN_Y))

//posiciones de la ventana titulo
#define TOP_VIEW_TITULO_POSX 	TOP_VIEWA_POSX
#define TOP_VIEW_TITULO_W		((int)((float)W_WIDTH*( 1.0 - 2 * MARGEN_X )))
#define TOP_VIEW_TITULO_POSY	TOP_VIEWA_POSY + TOP_VIEWA_H
#define TOP_VIEW_TITULO_H		((int)((float)W_HEIGHT*MARGEN_Y))

/*
 * limites izquierdo-derecho, superior-inferior para el dibujo de los ptos de ctrl
 * en el panel de dibujo. Lo usa el mouseEditor
 */
#define SX1 					(int) (TOP_VIEWA_POSX + (int)((float)W_WIDTH*0.037f))
#define SX2  					(int) (TOP_VIEWA_POSX + TOP_VIEWA_W - (int)((float)W_WIDTH*0.017f))
#define SY1  					(int) (W_HEIGHT-TOP_VIEWA_POSY - TOP_VIEWA_H + (int)((float)W_HEIGHT*0.012f))
#define SY2  					(int) (W_HEIGHT-TOP_VIEWA_POSY - (int)((float)W_HEIGHT*0.019f))



#endif /* DIMENSIONES_H_ */
