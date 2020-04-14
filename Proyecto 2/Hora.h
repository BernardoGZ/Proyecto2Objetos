#include <iostream>

using namespace std;

class Hora
{
public:
	Hora();
	Hora(int h, int m);

	void setHora(int h) { hh = h; }
	void setMinuto(int m) { mm = m; }

	int getHora() { return hh; }
	int getMinuto() { return mm; }

	void muestra();


private:
	int hh, mm;
};

Hora::Hora()
{
	hh = 22;
	mm = 30;
}

Hora::Hora(int h, int m)
{
	hh = h;
	mm = m;
}

void Hora::muestra()
{
	cout << hh << ":" << mm << endl;
}
