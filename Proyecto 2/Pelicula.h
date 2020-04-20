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
	
}

bool Pelicula::agregarActor(Actor a)		
{
	bool test = true;
	int i = 0;
	Actor b;
	
	if (cantActores < 10)		//Recordar que la cantActores se inicia cada constDefault como 0. Y se va sumando conforme se agreguen actores
	{			
		while (i < cantActores)  // validar que el actor que recibe no este ya en en la lista
		{
			if (a.getId() == listaActores[i].getId())
			{
				test = false;
			}			

			i++;
		}
		
	}
	else
	{
		test = false;
	}

	if (test == true)
	{
		listaActores[cantActores] = a;
		cantActores++;		
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

