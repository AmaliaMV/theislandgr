#ifndef BMPCABECERA_H_
#define BMPCABECERA_H_

typedef unsigned char 		BYTE1;
typedef unsigned short int 	BYTE2;
typedef unsigned int 		BYTE4;

struct Encabezado1{
	BYTE1 B;
	BYTE1 M;
};

struct Encabezado2{
	BYTE4 tamanoArchivo;
	BYTE4 reservado;
	BYTE4 inicioImagen;
};

struct Encabezado3{
	BYTE4 tamanoEncabezado;
	BYTE4 ancho;
	BYTE4 alto;
	BYTE2 comprimida;
	BYTE2 tamanoPixel;
	BYTE4 tamanoImagen;
	BYTE4 resolucionAncho;
	BYTE4 resolucionAlto;
	BYTE4 dealgo;
	BYTE4 paleta;
	BYTE4 colorImportantes;
};

struct Pixel3{

	BYTE1 azul;
	BYTE1 verde;
	BYTE1 rojo;
};

struct Pixel4{

	BYTE1 alfha;
	BYTE1 azul;
	BYTE1 verde;
	BYTE1 rojo;
};
#endif
