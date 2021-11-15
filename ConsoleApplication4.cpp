#include <iostream>
#include<math.h>
using namespace std;

double func(double x) {
	return x * atan(x);
}

double a = 0, b = sqrt(3);
int cut_count = 1;
double h;
double  res1 = 0;
double  result=0;
double  answer;

double  simp_method(int cut_count) {
	h = (b - a) / cut_count;
	answer = func(a)+func(b);
	double  sum = 0;
	for (int i = 1; i <= cut_count - 1; i++) {
		double  xi = a + i * h;
		sum += (3 - pow(-1, i)) * xi * atan(xi);
	}
	double  result = (sum + answer) * (h / 3);
	return result;
}

int main() {
	result = simp_method(cut_count);
	do {
		res1 = result;
		cut_count *= 2;
		cout << "cut count: " << cut_count << endl;
		result = simp_method(cut_count);
		cout << "result old= "; printf("%.5f", res1); cout << endl;
		cout << "result new= "; printf("%.5f", result); cout << endl;
	} while (abs(res1 - result) >= pow(10, -3));
}
