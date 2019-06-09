#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

double f(double, double);
double fi_rk2(double, double, double);
double fi_rk4(double, double, double);

int main()
{
	double a, b, h;
	int N = 300;
	cin >> a >> b;
	h = 0.01;
	ofstream euler;
	euler.open("Euler.csv");
	double y = 1, x = a;
	cout << "\nMetoda Eulera:\nx = " << x << " y = " << y << endl;
	for (int i = 0; i < N; i++) {
		y += h*f(x, y);
		x += h;
		euler << x << "," << y<<endl;
		cout << "x = " << x << " y = " << y << endl;
	}
	ofstream RK2;
	RK2.open("RK2.csv");
	double(*fi)(double, double, double) = fi_rk2;
	y = 1.0, x = a;
	cout << "\nMetoda Rungego-Kutty (RK2):\nx = " << x << " y = " << y << endl;
	for (int i = 0; i < N; ++i) {
		y += h * fi(x, y, h);
		x += h;
		RK2 << x << "," << y << endl;
		cout << "x = " << x << " y = " << y << endl;
	}

	y = 1.0, x = a;
	fi = fi_rk4;
	ofstream RK4;
	RK4.open("RK4.csv");
	cout << "\nMetoda Rungego-Kutty (RK4):\nx = " << x << " y = " << y << endl;
	for (int i = 0; i < N; ++i) {
		y += h * fi(x, y, h);
		x += h;
		RK4 << x << "," << y << endl;
		cout << "x = " << x << " y = " << y << endl;
	}
	system("pause");
	return 0;
}

inline double f(double x, double y) {
	return (y);
}

double fi_rk2(double x, double y, double h) {
	double k[2];
	k[0] = f(x, y),
		k[1] = f(x + h, y + h * k[0]);
	return 0.5*(k[0] + k[1]);
}

double fi_rk4(double x, double y, double h) {
	double k[4];
	k[0] = f(x, y),
		k[1] = f(x + 0.5*h, y + 0.5*h*k[0]),
		k[2] = f(x + 0.5*h, y + 0.5*h*k[1]),
		k[3] = f(x + h, y + h * k[2]);
	return (k[0] + 2.0*k[1] + 2.0*k[2] + k[3]) / 6.0;
}
