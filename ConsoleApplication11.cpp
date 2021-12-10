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
	double h = 0.1;
	double y0 = 1, 
		y1=1.07565, 
		y2=1.19224, 
		y3 =1.3597 ;
	double x0=0,x1=0.1,x2=0.2,x3 = 0.3;
	double fa=f(x0, y0), fb=(x1, y1), fc=(x2, y2), fd=(x3, y3);

	for(;;){
		double y = y3 + h / 24 * (55 * fd - 59 * fc + 37 * fb - 9 *fa );
		if (x3 + h >= 1) { break; }
		x3 += h;
		fa = fb; fb = fc; fc = fd;
		fd = f(x3, y);
		y3 = y;
		cout << "x= " << x3 << endl << "y= " << y << endl;
	}
}
