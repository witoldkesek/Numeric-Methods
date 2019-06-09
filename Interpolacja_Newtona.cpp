#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
class punkt
{
public:
	double x, y;
	punkt(double a, double b): x(a), y(b) {};
	punkt() { x = 0; y = 0; };
};
double funkcja_pomocnicza(vector <punkt> points, int initialIndex, int count)
{
	if (count == 1)
	{
		return points[initialIndex].y;
	}
	if (count == 2)
	{
		double top = points[initialIndex + 1].y - points[initialIndex].y;
		double down = points[initialIndex + 1].x - points[initialIndex].x;
		return top / down;
	}
	double top = funkcja_pomocnicza(points, initialIndex + 1, count - 1) - funkcja_pomocnicza(points, initialIndex, count - 1);
	double down = points[initialIndex + count - 1].x - points[initialIndex].x;
	return top / down;
}
double calculateStuff2(vector <punkt> points, double x)
{
	double returned = 0;
	double p = 1;
	for (int i = 0; i < points.size(); i++)
	{

		returned += p * funkcja_pomocnicza(points, 0, i + 1);
		cout << funkcja_pomocnicza(points, 0, i + 1) << " " << p << " " << "wynik: " << (x - points[i].x)*funkcja_pomocnicza(points, 0, i + 1) << endl;
		p *= (x - points[i].x);
	}
	return returned;
}
void wielomian(vector<punkt> punkty,int a)
{
	cout << "Wielomian ma postac: "<<endl;
	cout << "W(x)=";
	for (int i = 0; i < a; i++)
	{
		cout << funkcja_pomocnicza(punkty, 0, i + 1);
		for (int j = 0; j < i; j++)
			cout << "(x-" << punkty[j].x << ")";
		if(i!=a-1)
		cout << "+";
	}
	
}

int main()
{ 
	int n;
	cout << "Ile punktow chcesz podac: ";
	cin >> n;
	vector <punkt> punkty;
	for (int i = 0; i < n; i++)
	{
		punkt punkcik;
		cout << "Podaj punkt nr " << i + 1 << ": ";
		cin >> punkcik.x;
		cout << "Podaj wartosc funkcji dla tego punktu: ";
		cin >> punkcik.y;
		punkty.push_back(punkcik);
	}
	cout << "Dla jakiego punktu chcesz poznac wartosc funkcji: ";
	double x;
	cin >> x;
	cout << calculateStuff2(punkty, x);
	wielomian(punkty, n);





}
