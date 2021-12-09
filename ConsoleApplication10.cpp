#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;
//double rynge_kutta_method() {
//	//2y'-y=5xe^x
//y'=(5xe^x+y)/2
//}

double f(double x, double y) {
	return (5 * x * pow(M_E, x) + y) / 2;
}

int main() {
	double x = 0;
	double y = 1; 
	//double end = 1;
	double h = 0.1;
	double k[4];

	for (int i = 0; i <= 9;i++) {
		k[0] = h * f(x, y);
		k[1] = h * f(x + h / 2, y + k[0] / 2);
		k[2] = h * f(x + h / 2, y + k[1] / 2);
		k[3] = h * f(x + h, y + k[2]);
		x += h;
		if (x > 1) { break; }
		y += (k[0] + 2 * k[1] + 3 * k[2] + k[3]) / 6;
		cout << "x= " << x << endl << "y= " << y << endl;

		
	}
}