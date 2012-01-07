/*
 * Camara.h
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#ifndef CAMARA_H_
#define CAMARA_H_
#include <iostream>
using namespace std;
class Camara {
public:
	Camara ( float angHInit, float angVInit );
	virtual ~Camara ();

	virtual void setEye()= 0;
	virtual void setAt() = 0;

	float* getEye () const;
	float* getAt () const;
	float* getUp () const;

	void incAngH( float num);
	void incAngV ( float num );

protected:

	float getAngH() const;
	float getTita() const;

	void setCoordEye ( float x, float y, float z );
	void setCoordAt ( float x, float y, float z);

	void setAngVMax( float angVMax );
	void setAngVMin( float angVMax );

private:
	float angH;
	float angV;
	float angVMax;
	float angVMin;
	float *eye;
	float *at;
	float *up;


	void setCoord ( float x, float y, float z, float *objeto );
	/*
	 * verifica que el angulo sea mayor o igual al minimo valor que puede
	 * tomar y menor o igual al maximo valor admisible. De estar en los
	 * extremos el valor del mismo, no podra seguir incrementando o
	 * disminuyendo su valor.
	 */
	void validarAngV ( float max, float min );
	/*
	 * verifica que el angulo sea mayor o igual al minimo valor que puede
	 * tomar y menor o igual al maximo valor admisible. De estar en su valor
	 * maximo, tomara su valor minimo, analogo con el valor minimo.
	 */
	void validarAngH ( float max, float min );
};

#endif /* CAMARA_H_ */
