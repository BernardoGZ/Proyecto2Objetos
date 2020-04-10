#pragma once
#include <iostream>
#include <string>

using namespace std;

class Actor
{
public:
	Actor();
	Actor(int i, string n);

	void setId(int i) { id = i; }
	void setNombre(string n) { nombre = n; }

	int getId() { return id; }
	string getNombre() { return nombre; }
	
	void muestra();
private:
	int id;
	string nombre;

};

Actor::Actor()
{
	id = 0;
	nombre = "Juan";
}

Actor::Actor(int i, string n)
{
	id = i;
	nombre = n;
}

void Actor::muestra()
{
	cout << id << "\t" << nombre << endl;
}
