#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cmath>


using namespace std;

const double E = 2.7182818284;

double f(double x, double y)
{
	return	0.82 * pow(E, sqrt(sin(pow((x + 0.2), 2) + pow((y - 1.5), 2)) + 1.2) + 0.23 * pow(x, 2) + 0.21 * pow(y, 2) + 0.75 * x * y);
}







int main()
{
	setlocale(LC_ALL, "rus");
	double x = -2.1, y = 0.05, dx = 0, dy = 0, z = 0, g = pow(10.0, -3), h = 0.1, grad = 1, e = pow(10.0, -3);
	int i = 0;


	while (grad >= e) 
	{

		i++;

		dx = (f(x + g, y) - f(x, y)) / (g);

		dy = (f(x, y + g) - f(x, y)) / (g);

		grad = sqrt(dx * dx + dy * dy);

		z = f(x, y);

		x = x - h * dx;

		y = y - h * dy;

	};
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
	cout << "Z = " << z << endl;
	cout << "Колличество итераций = " << i << endl;







	return 0;
}