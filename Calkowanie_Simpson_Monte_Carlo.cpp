#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
double funkcja(double x) //definicja funkcji
{
	return(x * x*x + 2);
 }
int main()
{
	srand(time(NULL));
	const int LP = 4; //liczba punktów podziałowych
	double xp, xk, s, st, dx, x;

	cout << "Obliczanie calki oznaczonej\n"
		" za pomoca metody Simpsona\n"
		"f(x) = x * x *x +2\n"
		"Podaj poczatek przedzialu calkowania: ";
	cin >> xp;
	cout << "\nPodaj koniec przedzialu calkowania: ";
	cin >> xk;
	cout << endl;
	s = 0; st = 0;
	dx = (xk - xp) / LP;
	for (int i = 1; i <= LP; i++)
	{
		x = xp + i * dx;
		st += funkcja(x - dx / 2);

		if (i < LP) 
		s += funkcja(x);
	}
	s = dx / 6 * (funkcja(xp) + funkcja(xk) + 2 * s + 4 * st);
	cout << "Wartosc calki wynosi : " << setw(8) << s
		<< endl << endl;
	cout << "Obliczanie calki oznaczonej\n"
		" za pomoca metody Monte Carlo\n"
		"f(x) = x * x + 2 * x\n\n"
		"Podaj poczatek przedzialu calkowania: ";
	cin >> xp;
	cout << "\nPodaj koniec przedzialu calkowania: ";
	cin >> xk;
	cout <<endl<< "Podaj ile punktow chcesz wylosowac: ";
	int p;
	cin >> p;
	double suma=0, srednia;
	for (int i = 0; i < p;i++)
	{
		x = (rand() / (static_cast <double>(RAND_MAX) + 1)) *(xk - xp) + xp;
		suma += funkcja(x);
	}
	srednia = suma / ((double)p);
	double calka = srednia * (xk - xp);
	cout << "Calka wynosi: " << calka<<endl;
	system("pause");

	return 0;
}
