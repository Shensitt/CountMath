#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;
double x = -2.1;
double y = 0.05;

double f(double x0, double y0) {
	return 0.82 * pow(M_E, sqrt(sin(pow((x0 + 0.2), 2) + pow((y0 - 1.5), 2)) + 1.2) + 0.23 * pow(x0, 2) + 0.21 * pow(y0, 2) + 0.75 * x0 * y0);
}

int step_num = 1;
double eps = 0.01;
double g = 0.01;
double grad = 1;
double dx, dy;
double h = 0.14;
double func;
double a = 0, xold=0, yold=0,x_1=0,y_1=0;

int main() {

	while (grad >= eps) {
		cout << step_num << endl;

		dx = (f(x + g, y) - f(x, y)) / (g);
		dy = (f(x, y + g) - f(x, y)) / (g);
		grad = sqrt(dx * dx + dy * dy);
		func = f(x, y);

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << "df/dx: " << dx << endl;
		cout << "df/dy: " << dy << endl;
		cout << "grad: " << grad << endl;
		cout << "func: " << func << endl << endl;

		
	/*	cout << x_1 << endl;
		cout << x << endl;*/

		xold = x;
		yold= y;
		x = x -a*(x-x_1)- h * dx;
		y = y - a * (y-y_1) - h * dy;
		x_1 = xold;
		y_1 = yold;
		
		a = 0.2;
		
		step_num++;
	}

}
