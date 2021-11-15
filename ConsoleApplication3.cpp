#include <iostream>
using namespace std;
int cut_number = 48;
double a = 0, b = sqrt(3);
double h = (b - a) / cut_number;

int square_method() {
cout << "square method: \n";

double sum_left = 0, sum_center = 0, sum_right = 0;

for (int i = 0; i <= cut_number - 1; i++) {
	double xi = a + i * h;
	double delta = 0;
	double x = xi + delta;
	/*sum_left += x * atan(x); */
	delta = h / 2;
	sum_center += x * atan(x);
	//delta = h;
	//sum_right += x * atan(x);
}
//double answer_left = h * sum_left;
double answer_center = h * sum_center;
//double answer_right = h * sum_right;
cout << "answer: "  << answer_center << endl ;
return 0;
}

int trapet_method() {
	cout << "trapet method: \n";

	double x0 = a ;
	double xEnd = a + cut_number * h;
	//double xEnd = b;
	double ans0 = x0 * atan(x0);
	double ansEnd = xEnd * atan(xEnd);
	double answer = ans0 + ansEnd;

	double sum = 0;
	for (int i = 1; i <= cut_number - 1; i++) {
		double xi = a + i * h;
		sum += xi * atan(xi);
	}

	double result = (sum * 2 + answer)*(h/2);
	cout << "answer: " << result << endl;
	return 0;
}

int simp_method() {
	cout << "simp method: \n";

	double x0 = a;
	double xEnd = a + cut_number * h;
	//double xEnd = b;
	double ans0 = x0 * atan(x0);
	double ansEnd = xEnd * atan(xEnd);
	double answer = ans0 + ansEnd;

	double sum = 0;
	for (int i = 1; i <= cut_number - 1; i++) {
		double xi = a + i * h;
		sum += (3 - pow(-1,i) )*xi * atan(xi);
	}

	double result = (sum  + answer) * (h / 3);
	cout << "answer: " << result << endl;
	return 0;
}

int main() {
	square_method();
	trapet_method();
	simp_method();
}