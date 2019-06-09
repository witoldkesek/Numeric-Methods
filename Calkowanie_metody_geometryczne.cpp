#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;
double funkcja(double x)
{
	return x*x*x + 2;
}
int main()
{
	int n;
	double xp, xk;
	cout << "Na ile przedzialow chcesz podzielic funkcje: ";
	cin >>n;
	cout << "Podaj poczatkowy punkt: ";
	cin >>xp;
	cout << "Podaj poczatkowy punkt: ";
	cin >> xk;
	double dx = (xk - xp) / n;
	cout << dx<<endl;
	double tmp = xp;
	//Metoda kwadratow
	double sumak = 0;
	for (int i = 0; i < n; i++)
	{
		tmp += dx;
		sumak += funkcja(tmp)*dx;
		
		//cout << "dodaje " << funkcja(tmp)*dx << endl;
	}
	cout << sumak<<endl;
	//Metoda trapezow
	tmp = xp;
	sumak = 0;
	for (int i = 0; i < n; i++)
	{
		
		sumak += (funkcja(tmp)+funkcja(tmp+dx))/2*dx;
		//cout << "dodaje " << (funkcja(tmp) + funkcja(tmp + dx)) / 2 * dx << endl;
		tmp += dx;
	}
	cout<<sumak<<endl;

}