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
	Funcion fun;

	int i = 0, j = 0, k = 0, id, x = 0, y, z, w, numArrAct;
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
		//arrAct[i].muestra();

		i++;	

	}
	actores.close();

	numArrAct = i; //Guardar cuantos actores hay en total, servira para buscar en la lista, mas adelante

			
				   
				   //PARTE 2 Arreglo de Peliculas

	ifstream pelicula;
	pelicula.open("peliculas.txt");

	i = 0;

	while (getline(pelicula,r))
	{
		
		j = 0;
		k = 0;
		x = 0;

		//Set Numero de peli
		y = x;
		x = r.find(' ');
		z = stoi(r.substr(y, x));
		peli.setNumP(z);
		r.erase(x, 1);
		
		//cout << "\n" << peli.getNumP() << "\t"; 

		//Set Anio
		y = x;
		x = r.find(' ');
		z = stoi(r.substr(y, x));
		peli.setAnio(z);
		r.erase(x, 1);

		//cout << peli.getAnio() << "\t";

		//Set Duracion
		y = x;
		x = r.find(' ');
		z = stoi(r.substr(y, x));
		peli.setDuracion(z);
		r.erase(x, 1);

		//cout << peli.getDuracion() << "\t";

		//Set Genero
		y = x;
		x = r.find(' ');
		g = r.substr(y, x-y);  //x-y se uso para solucionar problema, 'g' tenia valor de casi todo el renglon. Ahora el genero se obtiene de manera correcta.
		peli.setGenero(g);
		r.erase(x, 1);

		//cout << peli.getGenero() << "\t";

		
		//Set Cantidad de actores que se agregaran a la lista
		y = x;
		x = r.find(' ');
		z = stoi(r.substr(y, x));  //'z' es la cantidad de actores
		r.erase(x, 1);

		//cout << z << "\t";
		//cout << peli.getCantAct() << "\t";    //Error, llama al valor default, porque contador cantAct se va sumando conforme vas agregando actores. Y todavia no agregamos
		
		/*
		//Set Id de actores en la lista
		while (i < z)		//mientras que nuestro contador 'i' sea menor que la cantidad de actores
		{
			y = x;
			x = r.find(' ');
			w = stoi(r.substr(y, x));		//'w' se usara para no reemplazar 'z' del valor de cantidad de actores
			r.erase(x, 1);

			while (j <= numArrAct)		//Mientras que mi contador 'j' llega al numero total de actores en la lista
			{
				if (arrAct[j].getId() == w)		//Se busca el Id segun es recibido en 'w'
				{
					 peli.agregarActor(arrAct[j], z) ;		//Se agrega el actor a la lista segun el metodo agregarActor. Debe regresar un bool. 
					
					 //cout << "\n Lool...  "<< peli.agregarActor(arrAct[j], z) << peli.getListAct(j).getId() << endl;
					 //Comprobando en el cout<< que el bool arroja true (1) pero el Id en la lista no se guarda, siempre sale el default(0).
				}
				
				j++;
			}

			
			//Actor lista;
			//peli.getListAct(i) = lista;
			//cout << lista.getNombre() << endl;
			
			i++;

		} */
		
		//Set Titulo
		y = x;
		g = r.substr(y, r.length());  //Este ultimo es diferente porque es desde nos quedamos, hasta el final del renglon
		peli.setTitulo(g);

		//cout << peli.getTitulo() << endl;

		arrPeli[i] = peli;

		//arrPeli[i].muestra();
		
		i++;
		
	}

	pelicula.close();

				//PARTE 3 Arreglo de funciones

	i = 0;
	
	bool salidafun = true;
	string cve;
	cout << "Funciones: " <<endl;

	while (salidafun == true)
	{
		cout << "Por favor ingresa las siglas clave de la funcion: " << endl;
		cin >> cve;
		fun.setCve(cve);

		cout << "Por favor ingresa el numero de pelicula :" << endl;
		cin >> x;
		fun.setNumP(x);

		cout << "Por favor ingresa el horario (hh:mm):" << endl;
		cin >> r;
		x = r.find(":");
		y = stoi(r.substr(0, x));
		z = stoi(r.substr(x + 1, x + 2));

		Hora h(y,z);
		fun.setHora(h);

		cout << "Por favor ingresa el numero de sala :" << endl;
		cin >> x;
		fun.setSala(x);

		arrFun[i] = fun;
		//arrFun[i].muestra();

		i++;

		cout << "Quieres agregar otra funcion? 1. Si  2.No" << endl;
		cin >> x;

		if (x == 2)
		{
			salidafun = false;
		}

	}


}