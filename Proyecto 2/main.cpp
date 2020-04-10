#include <iostream>
#include <string>
#include <fstream>

#include "Actor.h"
#include "Funcion.h"
#include "Pelicula.h"

int main() 
{

	Actor arrAct[20];
	Funcion arrFun[20];
	Pelicula arrPeli[20];

	Actor actor;
	Pelicula peli;

	int i = 0, id, x = 0, y, z, w;
	string r, n, g;

	
	
			//PARTE 1 Arreglo de Actores

	ifstream actores;
	actores.open("actores.txt");

	while (getline(actores,r)) //Se obtiene toda la linea, hasta que el archivo se acabe
	{
		id = r.find_first_of(' '); //Un int cualquiera toma el lugar del espacio entre Id y Nombre
		
		n = r.substr(id + 1, r.length()); //Se le asigna el nombre a un string, a partir del espacio. 
		id = stoi(r.substr(0, id)); //Se le asigna el id a un int, desde el principio hasta el espacio. 

		actor.setId(id);	
		actor.setNombre(n); 

		arrAct[i] = actor;		
		arrAct[i].muestra();

		i++;	

	}
	actores.close();



			//PARTE 1 Arreglo de Peliculas

	ifstream pelicula;
	pelicula.open("pelicula.txt");

	i = 0;

	while (getline(pelicula,r))
	{
		//Set Numero de peli
		y = x;
		x = r.find(' ');
		z = stoi(r.substr(y, x));
		peli.setNumP(z);
		r.erase(x, 1);
		

		//Set Anio
		y = x;
		x = r.find(' ');
		z = stoi(r.substr(y, x));
		peli.setAnio(z);
		r.erase(x, 1);

		//Set Duracion
		y = x;
		x = r.find(' ');
		z = stoi(r.substr(y, x));
		peli.setDuracion(z);
		r.erase(x, 1);

		//Set Genero
		y = x;
		x = r.find(' ');
		n = r.substr(y, x);
		peli.setGenero(g);
		r.erase(x, 1);


		//Set Cantidad de actores que se agregaran a la lista
		y = x;
		x = r.find(' ');
		z = stoi(r.substr(y, x));
		r.erase(x, 1);
		
		//Set Id de actores de la lista
		while (i < z)
		{
			y = x;
			x = r.find(' ');
			z = stoi(r.substr(y, x));


		}
		
		//Set Titulo



	}

	pelicula.close();




}