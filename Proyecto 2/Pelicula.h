#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;

class Pelicula
{
public:
	Pelicula();

	void setNumP(int np) { numPeli = np; }
	void setAnio(int a) { anio = a; }
	void setDuracion(int d) { duracion = d; }
	void setTitulo(string t) { titulo = t; }
	void setGenero(string g) { genero = g; }

	int getNumP() { return numPeli; }
	int getAnio() { return anio; }
	int getDuracion() { return duracion; }
	string getTitulo() { return titulo; }
	string getGenero() { return genero; }
	int getCantAct() { return cantActores; }
	
	Actor getListAct(int i) { return listaActores[i]; }

	bool agregarActor(Actor a);

	void muestra();

private:
	int numPeli, anio, duracion;
	string titulo, genero;
	Actor listaActores[10];
	int cantActores;
};

Pelicula::Pelicula()
{
	numPeli = 0;
	anio = 0;
	duracion = 0;
	titulo = " ";
	genero = " ";
	cantActores = 0;

	Actor act(0, " Lol ");
	listaActores[0] = act;  
	//veamos si esto es util, o si solo hay que borrarlo
}

bool Pelicula::agregarActor(Actor a)		// Contrario a las instrucciones se le agrego un int para saber cuantos se agregaran.
{
	bool test;
	int i = 0;
	Actor b;
	
	if (cantActores < 10)
	{
		listaActores[cantActores] = a;
		cantActores++;
		test = true;
	}
	else
	{
		test = false;
	}
	
	return test;
	
}

void Pelicula::muestra()
{
	int i = 0;
	cout << numPeli << "\t" << titulo << "\t Anio: " << anio << "\t Duracion: " << duracion << "\t Genero: " << genero << endl;
	while (i  < cantActores)
	{
		listaActores[i].muestra();
		i++;
	}
}

