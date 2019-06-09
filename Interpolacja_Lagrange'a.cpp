#include "pch.h"
#include <iostream>
using namespace std;
class punkt
{
public:
	double x;
	double y;
	punkt(double a, double b):x(a),y(b){};
	punkt() {};
};
double interpolacja(punkt* p, int a, double x)
{
	double suma = 0;
	for (int j = 0; j < a; j++)
	{
		double tmp = 1;
		for (int g = 0; g < a; g++)
		{
			if (g != j)
			{
				tmp = tmp * (x - p[g].x);
				tmp = tmp / (p[j].x - p[g].x);
			}
		}
		tmp *= p[j].y;
		suma = suma + tmp;
	}
	return suma;
}
int main()
{
	int a;
	bool s=1;
	while (s==1)
	{
		cout << "Podaj ilosc punktow,ktore chcesz interpolowac: ";
		cin >> a;
		punkt * p = new punkt[a];
		for (int i = 0; i < a; i++)
		{
			cout << "Podaj x punktu numer " << i + 1 << ": ";
			cin >> p[i].x;
			cout << "Podaj y punktu numer " << i + 1 << ": ";
			cin >> p[i].y;
		}
		for (int i = 0; i < a; i++)
		{
			cout << p[i].x << "  " << p[i].y << endl;
		}
		cout << "Podaj wspolrzedna x punktu, ktorego wartosc chcesz poznac :";
		double x;
		cin >> x;

		cout << "Wynik to: " << interpolacja(p, a, x);
		bool y=1;
		while (y==1)
		{
			int b;
			cout << "Co chcesz robic dalej (podaj numer): "<<endl;
			cout << "1. Poznac wartosc dla inngo punktu. " << endl;
			cout << "2. Poznac wartosc innej interpolacji " << endl;
			cout << "3. Wyjsc " << endl;
			cout << "Podaj numer: ";
			
			cin >> b;
			switch (b)
			{
			case 1:
				cout << "Podaj wspolrzedna x punktu, ktorego wartosc chcesz poznac :";
				double x;
				cin >> x;
				cout << "Wynik to: " << interpolacja(p, a, x);
			
				break;
			case 2:
				y = 0;
				break;
			case 3:
				s =0;
				y = 0;
				break;
			}
		}

	}

}