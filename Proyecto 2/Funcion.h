#include <iostream>
#include <string>
#include "Hora.h"

using namespace std;

class Funcion
{
public:
	Funcion();
	Funcion(string cveF, int np, Hora h, int s);

	void setCve(string cveF) { cveFuncion = cveF;}
	void setNumP(int np) { numPeli = np; }
	void setHora(Hora h) { hora = h; }
	void setSala(int s) { sala = s; }

	string getCve() { return cveFuncion; }
	int getNump() { return numPeli; }
	Hora getHora() { return hora; }
	int getSala() { return sala; }

	void muestra();

private:
	string cveFuncion;
	int numPeli, sala;
	Hora hora;
};


Funcion::Funcion()
{
	cveFuncion = " ";
	numPeli =  0 ;
	sala = 0;

	Hora h(22, 30); //Creamos una variable tipo Hora, para despues poder igualar
	hora = h;
}

Funcion::Funcion(string cveF, int np, Hora h, int s)
{
	cveFuncion = cveF;
	numPeli = np;
	hora = h;
	sala = s;

}

void Funcion::muestra()
{
	cout << cveFuncion << "\t" << numPeli << "\t" << sala << endl;
	hora.muestra();
}
