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
	Camara ( float fiInit, float titaInit );
	virtual ~Camara ();

	virtual void setEye()= 0;
	virtual void setAt() = 0;

	float* getEye () const;
	float* getAt () const;
	float* getUp () const;

	void incFi( float num);
	void incTita ( float num );

protected:

	float getFi() const;
	float getTita() const;

	void setCoordEye ( float x, float y, float z );
	void setCoordAt ( float x, float y, float z);

	void setTitaMax( float TitaMax );
	void setTitaMin( float TitaMax );

private:
	float fi;
	float tita;
	float titaMax;
	float titaMin;
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
	void validarAnguloTita ( float max, float min );
	/*
	 * verifica que el angulo sea mayor o igual al minimo valor que puede
	 * tomar y menor o igual al maximo valor admisible. De estar en su valor
	 * maximo, tomara su valor minimo, analogo con el valor minimo.
	 */
	void validarAnguloFi ( float max, float min );
};

#endif /* CAMARA_H_ */
