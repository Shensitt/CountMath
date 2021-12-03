#include <iostream>
using namespace std;

double x[] = { 0.77, 0.9, 0.94, 0.96, 0.99, 1, 1.17, 1.3 };
double y[] = { 11.6, 7.3, 3.1, 1.7, 0.3, -0.1, -2.6, 0.5 };
double x_beg = 0.9;
double x_end = 1.2;
double x_step = 0.02;

double ln_poly = 0;

double times = 1;
double sum = 0;

int main() {
	for (double xx = x_beg; xx <= x_end; xx+= x_step) {
		ln_poly = 0;
		sum = 0;
		//cout << "x= " << xx << endl;
		for (int i = 0; i < 8; i++) {
			times = 1;
			
			for (int j = 0; j < 8; j++) {
				if (i != j) {
					times *= (xx - x[j]) / (x[i] - x[j]);
					//cout << "times= " << times << endl;
				}
			}

			sum += y[i] * times;
		}
		ln_poly = sum;
		cout << "x: " << xx << "\t\tf(x): " << ln_poly << endl;
	}

}
