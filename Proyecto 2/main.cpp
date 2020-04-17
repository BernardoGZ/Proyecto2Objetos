#include <iostream>
#include <string>
#include <fstream>

#include "Actor.h"		//Se le tiene que agregar la clase actor? No arriesgarse
#include "Funcion.h"
#include "Pelicula.h"

int main() 
{

	Actor arrAct[20];
	Funcion arrFun[20];
	Pelicula arrPeli[20];

	Actor actor;	
	Funcion fun;

	int i = 0, j = 0, k = 0, x = 0, y, z, w;
	bool test;
	string r, n;

	
	
				//PARTE 1 Arreglo de Actores

	ifstream actores;
	actores.open("actores.txt");

	while (getline(actores,r)) //Se obtiene toda la linea, hasta que el archivo se acabe
	{
		x = r.find_first_of(' '); //Un int cualquiera toma el lugar del espacio entre Id y Nombre
		
		n = r.substr(x + 1, r.length()); //Se le asigna el nombre a un string, a partir del espacio. 
		x = stoi(r.substr(0, x)); //Se le asigna el id a un int, desde el principio hasta el espacio. 

		actor.setId(x);	
		actor.setNombre(n); 

		arrAct[i] = actor;		
		
		i++;	

	}
	actores.close();

	int numArrAct = i; //Guardar cuantos actores hay en total, servira para buscar en la lista, mas adelante
			
				   
				   //PARTE 2 Arreglo de Peliculas

	ifstream pelicula;
	pelicula.open("peliculas.txt");

	i = 0;

	while (getline(pelicula,r))
	{	
		Pelicula peli;		//La variable 'peli' se puso dentro del while para que cada que vaya leyendo una pelicula, el atributo
							//     contAct y  la lista, se reinicien por el constrDefault. Con esto, resolver el problema con la lista. 
		j = 0;
		k = 0;
		x = 0;

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
		n = r.substr(y, x-y);  //x-y se uso para solucionar problema, 'g' tenia valor de casi todo el renglon. Ahora el genero se obtiene de manera correcta.
		peli.setGenero(n);
		r.erase(x, 1);
	

		
		//Set Cantidad de actores que se agregaran a la lista
		y = x;
		x = r.find(' ');
		z = stoi(r.substr(y, x));  //'z' es la cantidad de actores.
		r.erase(x, 1);
		
		
		//Set Id de actores en la lista
		while (j < z)		//mientras que nuestro contador 'j' sea menor que la cantidad de actores
		{
			y = x;
			x = r.find(' ');
			w = stoi(r.substr(y, x));		//'w' se usara para no reemplazar 'z' del valor de cantidad de actores
			r.erase(x, 1);

			while (k < numArrAct)		//Mientras que mi contador 'k' llega al numero total de actores en la lista
			{
				if (arrAct[k].getId() == w)		//Se busca el Id segun es recibido en 'w'
				{
					 peli.agregarActor(arrAct[k]) ;		//Se agrega el actor a la lista segun el metodo agregarActor. Debe regresar un bool. 					
				}				
				k++;
			}
			
			k = 0;
			j++;

		}

		
		
		//Set Titulo
		y = x;
		n = r.substr(y, r.length());  //Este ultimo es diferente porque es desde nos quedamos, hasta el final del renglon
		peli.setTitulo(n);

		
		arrPeli[i] = peli;
		
		i++;
		
	}
	int numArrPeli = i;
	pelicula.close();

				
				//PARTE 3 Arreglo de funciones

	i = 0;
	
	bool salidafun = true;
	string cve;
	
	cout << "Funciones: " <<endl;

	while (salidafun == true)
	{
		test = false;
		j = 0;
		
		cout << "Por favor ingresa las siglas clave de la funcion: " << endl;
		cin >> cve;
		fun.setCve(cve);		

	
		
		while (test == false)		//validar que el numero de pelicula sea correcto
		{
			cout << "Por favor ingresa el numero de pelicula :" << endl;
			cin >> x;

			while (j < numArrPeli)
			{
				if (x == arrPeli[j].getNumP()) 
				{ 
					fun.setNumP(x); 
					test = true; 
				}
				
				j++;
			}

			if (test == false)
			{
				cout << "\nPor favor ingrese un numero valido.  " << endl;
			}
			j = 0;
		}
		
		j = 0;
		test = false;

		while (test == false)
		{
			cout << "Por favor ingresa el horario (hh:mm) (24 hrs):" << endl;
			cin >> r;
			x = r.find(":");
			y = stoi(r.substr(0, x));
			z = stoi(r.substr(x + 1, x + 2));

			if ((-1 < y && y < 24) && (-1 < z && z < 60))
			{
				Hora h(y, z);
				fun.setHora(h);
				test = true;
			}
			else
			{
				cout << "\nPor favor ingrese un horario valido.  " << endl;				
			}

		}
		

		cout << "Por favor ingresa el numero de sala :" << endl;
		cin >> x;
		fun.setSala(x);

		arrFun[i] = fun;
	
		i++;

		cout << "Quieres agregar otra funcion? 1. Si  2.No" << endl;
		cin >> x;

		if (x == 2)
		{
			salidafun = false;
		}

	}
	

	int numArrFun = i;

				
				//PARTE 4 Menu del usuario

	bool salidamenu = true;
	int opcion;
	Hora h;


	while (salidamenu == true)
	{
		i = 0;
		j = 0;
		test = false;
	

		cout << "\n Bienvenido! \n Por favor ingrese el numero de la opción que deseé elegir: " << endl;
		cout << "\t 1. Consulta de lista de actores. \n\t 2. Consulta de lista de peliculas. \n\t 3. Consulta de lista de funciones. \n\t 4. Consulta de funciones por hora. \n\t 5. Consulta de funcion por clave. \n\t 6. Consulta de peliculas por actor. \n\t 7. Salir." << endl;
		cin >> opcion;		//Si el usuario ingresa un numero con una puntuacion, o un caracter, se loopea. A que se debe y como se resuelve?

		if (cin.fail() == 1) { cin.clear(); cin.ignore(); }


		switch (opcion)
		{
		case 1:
			while (i < numArrAct)
			{
				arrAct[i].muestra();
				i++;
			}
			break;

		case 2:
			while (i < numArrPeli)
			{
				arrPeli[i].muestra();
				i++;
			}		// Pruebas exitosas. El actor num 39 en Forrest Gump no existe en la lista de actores. Otra prueba de exito.   
			break;

		case 3:
			while (i < numArrFun)
			{
				arrFun[i].muestra();
				i++;
			}
			break;

		case 4:
			
			cout << "\n Por favor ingrese el horario a buscar (hh:mm) (en formato 24hrs) : " << endl;
			cin >> r;
			x = r.find(":");
			y = stoi(r.substr(0, x));
			z = stoi(r.substr(x + 1, x + 2));			

			if ((-1 < y && y < 24) && (-1 < z && z < 60 ))		//validar la hora y poder continuar
			{
				h.setHora(y);
				h.setMinuto(z);
	
				while (i < numArrFun)		// A continuacion validar que el horario (hh:mm) si exista en alguna funcion
				{					// Para esto se busca dentro del arrFun, el metodo getHora de clase Funcion, getHora y getMin de clase Hora
					if (arrFun[i].getHora().getHora() == h.getHora() && arrFun[i].getHora().getMinuto() == h.getMinuto())
					{										
						while (j < numArrPeli)
						{							
							if(arrFun[i].getNump() == arrPeli[j].getNumP())		//Obtener el titulo de la pelicula segun el numP
							{
								cout << "\n" << arrPeli[j].getTitulo() ;								
							}
							j++;
						}
						
						arrFun[i].muestra();
						test = true;
						j = 0;
					}
					
					i++;
				}
				if (test == false)
				{
					cout << "\n No hay funciones disponibles a esa hora. " << endl;
				}

			}
			else if (0 > y || y > 24 || -1 > z || z > 59)
			{
				cout << "\n Por favor introduzca un horario valido. " << endl;
			}		

			break;
		case 5:
			cout << "\n Por favor ingresa las siglas clave de la funcion : " << endl;
			cin >> r;

			while (i < numArrFun)
			{
				if (r == arrFun[i].getCve())	//validar que exista la clave dentro de alguna funcion
				{
					while (j < numArrPeli)
					{
						if (arrFun[i].getNump() == arrPeli[j].getNumP())   //Encontrar los datos de la pelicula
						{
							arrPeli[j].muestra();
						}
						j++;

					}
					
					arrFun[i].muestra();
					test = true;
					j = 0;
				}
				i++;
			}
			if (test == false)
			{
				cout << "Por favor ingrese una Clave valida." << endl;
			}
			
			break;
		case 6:
			cout << "Por favor ingrese el ID del actor: ";
			cin >> x;

			while (i < numArrAct)
			{
				if (arrAct[i].getId() == x)		//Validar que el ID exista
				{
					arrAct[i].muestra();

					while (j < numArrPeli)		//Buscar sin pasarnos del numero de peliculas
					{
										
						while (k < arrPeli[j].getCantAct())		//Buscar sin pasarnos la cantidad de actores por lista de cada pelicula
						{						
							
							if (arrPeli[j].getListAct(k).getId() == x)		//Verificar el ID del actor por pelicula
							{
								cout << arrPeli[j].getTitulo() << "\t" << arrPeli[j].getAnio() << endl;
							}
							
							k++;
						}
						
						k = 0;
						j++;
					}
				
					test = true;
				}
				j = 0;
				i++;
			}
			if (test == false)
			{
				cout << "Por favor ingrese un ID valido." << endl;
			}
			
			break;

		
		case 7:			
			cout << "Gracias!" << endl;
			salidamenu = false;

			break;
		
		default:
			cout << "\nPor favor ingrese una opcion valida. " << endl;
			break;
		}

	}
}