#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;
double x = -2.1;
double y = 0.05;

double f(double x0,double y0) {
	return 0.82 * pow(M_E, sqrt(sin(pow((x0 + 0.2), 2) + pow((y0 - 1.5), 2)) + 1.2) + 0.23 * pow(x0, 2) + 0.21 * pow(y0, 2) + 0.75 * x0 * y0);
} 

int step_num = 1;
double eps = 0.001;
double g = 0.001;
double grad = 1;
double dx, dy;
double h = 0.1;
double func;

int main() {
	
	while (grad >= eps) {
		cout << step_num<<endl;

		dx = (f(x + g, y) - f(x-g, y)) / (2*g);
		dy = (f(x, y + g) - f(x, y-g)) / (2*g);
		grad = sqrt(dx * dx + dy * dy);
		func = f(x, y);
		
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << "df/dx: " << dx << endl;
		cout << "df/dy: " << dy << endl;
		cout << "grad: " << grad << endl;
		cout << "func: " << func << endl<<endl;

	    x = x - h * dx;
		y = y - h * dy;

		step_num++;
	}
	
}