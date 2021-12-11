#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;

double f(double x, double y) {
	return 10 * x - 0.5 * y + pow(M_E, 0.94 * x * x + 0.2 * y * y);
}

double eps = 0.1, N = 20, a0 = 0.1;
double dx, dy;
double g = 0.001;
double x = 0, y = 0;
double grad=1;
double xo=x, yo=y;
double a = 0.01;
double n = 0;

int main() {
	for (int i = 0; i < N; i++) {
		dx = (f(x + g, y) - f(x, y)) / g;
		dy = (f(x, y + g) - f(x, y)) / g;
		grad = sqrt(dx * dx + dy * dy);

		if (grad < eps) { break; }

		

		xo -= a * dx;
		yo -= a * dy;
		double func = f(x, y);
		double func_new = f(xo, yo);

		 do{
			x = xo;
			y = yo;
			xo -= a * dx;
			yo -= a * dy;
			n++;
			//cout << "n=" << n << endl;
		 } while (f(x, y) < f(xo, yo));
		

		
		if (n > 20) {
			cout << "n>20" << endl;
			break;
		}
		
		double ak = a * (n - 1);
		if (ak > 0){
			a = a / 10;
		}
		else {
			xo = x;
			yo = y;
			cout << "ak =" << ak << endl;
			cout << "x = " << xo << endl;
			cout << "y = " << yo << endl;
		    cout << "func_old= " << func << endl;
			cout << "func = " << func_new << endl;
			cout<< "grad= " << grad << endl << endl;
		}
		n = 0;
	}
	
}


