#include "pch.h"
#include <iostream>
using namespace std;
double funkcja(double x)
{
	return (1 / x);
}
int main()
{
	double xp, xk;
	cout << "Metoda kwadratur Gaussa-Legendre'a dla funkcji f(x)=1/x." << endl;
	cout <<endl<< "Metoda dwuwezlowa."<<endl;
	cout << "Podaj poczatek przedzialu: ";
	cin >> xp;
	cout << "Podaj koniec przedzialu: ";
	cin >> xk;
	double x0 = sqrt(3)/3, x1 = -x0;
	double t0, t1;
	t0 = (xk + xp) / 2 + (xk - xp) / 2 * x0;
	t1 = (xk + xp) / 2 + (xk - xp) / 2 * x1;
	double A0 = 1, A1 = 1;
	double integral = (xk - xp) / 2 * (funkcja(t1)+funkcja(t0));
	cout << "Calka wynosi: " << integral<<endl;
	cout <<endl<< "Metoda czterowezlowa." << endl;
	cout << "Podaj poczatek przedzialu: ";
	cin >> xp;
	cout << "Podaj koniec przedzialu: ";
	cin >> xk;
	double x[4];
	x[1] = -sqrt(525 - 70 * sqrt(30))/35;
	x[0]= -sqrt(525 + 70 * sqrt(30)) / 35;
	x[2] = -x[1];
	x[3] = -x[0];
	double t[4];
	for (int i = 0; i < 4; i++)
	{
		t[i] = (xk + xp) / 2 + (xk - xp) / 2 * x[i];
	}
	double A[4];
	A[1] = (18 + sqrt(30)) / 36;
	A[0] = (18 - sqrt(30)) / 36;
	A[2] = A[1];
	A[3] = A[0];
	double suma = 0;
	for (int i = 0; i < 4; i++)
	{
		suma += A[i] * funkcja(t[i]);
	}

	integral = (xk - xp) / 2 *suma;
	cout << "Calka wynosi: " << integral << endl;
	system("PAUSE");


}