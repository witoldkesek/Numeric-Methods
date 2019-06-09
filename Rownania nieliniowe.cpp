#include "pch.h"
#include <iostream>
#include <cmath>
#include<math.h>
using namespace std;
double funkcja(double x)
{
	return 2 * x - sin(x) + 4 * cos(3 * x*x);
}
double pochodna(double x)
{
	return 2 - cos(x) - 24 * x*sin(3 * x*x);
}
/*double **Jacobian(double *x)
{
	double a, b, c, d;
	a = 2;
	b = 3 * x[1];
	c = cos(x[0]);
	d = 4 * exp(x[1]);
	double sf[2][2] = { a,b,c,d };
	return sf;
}*/
int main()
{
	double a, b,E;
	cout << "Podaj przedzial: "<<endl;
	cin >> a;
	cin >> b;
	cout << "Podaj dozwolone przyblizenie: ";
	cin >> E;
	cout << "Metoda Newtona (stycznych): "<<endl;
	double tmp = a;
	while (true)
	{
		cout << tmp << "    " << funkcja(tmp) << endl;
		if (abs(funkcja(tmp)) < E)
		{
			cout << "Rozwiazaniem rownania jest: " << tmp<<endl;
			break;
		}
		
		double a = tmp;
		tmp =a- funkcja(a) / pochodna(a);
		
	}
	cout << "Metoda siecznych: "<<endl;
	double tmp1=1;
	double tmp2 = 1.001;
	cout << "Punkty poczatkowe: " << tmp1 << ", " << tmp2<<endl;
	while (true)
	{
		cout << tmp2<< "    " << funkcja(tmp2) << endl;
		if (abs(funkcja(tmp2)) < E)
		{
			cout << "Rozwiazaniem rownania jest: " << tmp2;
			break;
		}

		double a = tmp2;
		tmp2 = a - (a - tmp1) / (funkcja(a) - funkcja(tmp1))*funkcja(a);
		tmp1 = a;

	}
	//double x0=0, x1=0;

}