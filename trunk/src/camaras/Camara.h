/*
 * Camara.h
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#ifndef CAMARA_H_
#define CAMARA_H_

class Camara {
public:
	Camara ( float angHInit, float angVInit, float distancia );
	virtual ~Camara ();

	virtual void setEye()= 0;
	virtual void setAt() = 0;

	float* getEye () const;
	float* getAt () const;
	float* getUp () const;

	void incAngH( float num);
	void incAngV ( float num );

	virtual void alejarCamara();
	virtual void acercarCamara();
	virtual void subirCamara();
	virtual void bajarCamara();

protected:
	float getAngH() const;
	float getAngV() const;
	float getDist() const;

	void setCoordEye ( float x, float y, float z );
	void setCoordAt ( float x, float y, float z);

	void setAngVMax( float angVMax );
	void setAngVMin( float angVMin );

	void setDistMax ( float distMax );
	void setDistMin ( float distMin );

	void aumentarDist ( float aumento );
	void disminuirDist ( float disminucion );

private:
	float angH;
	float angV;
	float angVMax;
	float angVMin;
	float *eye;
	float *at;
	float *up;
	float distancia;
	float distMin;
	float distMax;


	void setCoord ( float x, float y, float z, float *objeto );
	/*
	 * verifica que el angulo sea mayor o igual al minimo valor que puede
	 * tomar y menor o igual al maximo valor admisible. De estar en los
	 * extremos el valor del mismo, no podra seguir incrementando o
	 * disminuyendo su valor.
	 */
	void validarAngV ();
	/*
	 * verifica que el angulo sea mayor o igual al minimo valor que puede
	 * tomar y menor o igual al maximo valor admisible. De estar en su valor
	 * maximo, tomara su valor minimo, analogo con el valor minimo.
	 */
	void validarAngH ( float max, float min );
};

#endif /* CAMARA_H_ */
