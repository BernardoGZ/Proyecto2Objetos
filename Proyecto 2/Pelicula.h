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

	Actor act(0, " ");
	listaActores[0] = act;  
	//veamos si esto es util, o si solo hay que borrarlo
}

bool Pelicula::agregarActor(Actor a)
{
	bool test;
	int i = 0;
	if (cantActores < 10)
	{
		while (i < cantActores)
		{
			if(listaActores[i] == a)  //Segun investigacion, estos no se pueden igualar por que no son binarios. son 2 atributos vs 2 atrib. 
			{
				test = false;
			}
			else if (listaActores[i] != a)
			{
				test = true;
			}
			
			i++;
		}

		if (test = true)
		{
			cantActores++;
			listaActores[cantActores] = a;
		}
	}

	return test;
	
}

