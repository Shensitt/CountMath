#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

double func(double x) {
	return (log(0.35 * x) + pow(M_E, 0.2 * x)) / (sin(x) + 1.5);
}

double a = 0.1, b ;
int cut_count = 1;
double h;
double  res1 = 0;
double  result = 0;
double  answer;

double  simp_method(int cut_count,double b) {
	h = (b - a) / cut_count;
	answer = func(a) + func(b);
	double  sum = 0;
	for (int i = 1; i <= cut_count - 1; i++) {
		double  xi = a + i * h;
		sum += (3 - pow(-1, i)) * xi * atan(xi);
	}
	double  result = (sum + answer) * (h / 3);
	return result;
}

double simp_result(double x0) {
	result = simp_method(cut_count,x0);
	double int_eps = 0.2;
	cut_count = 1;
	do {
		int_eps *= 2;
		res1 = result;
		cut_count *= 2;
		//cout << "cut count: " << cut_count << endl;
		result = simp_method(cut_count,x0);
		//cout << "result old= "; printf("%.5f", res1); cout << endl;
		//cout << "result new= "; printf("%.5f", result); cout << endl;
	} while (abs(res1 - result) >= int_eps);
	return result;
}


double mi = 0.2, ma =8;
double eps=-3;             
double x0, x1, f;                                                                                           //объявление переменных
int iteration = 0;

int main() {
	//for (double i = 0.2; i < ma;i+=0.78) {
		//mi = i;
		//ma = mi + 0.78;
		x1 = (mi + ma) / 2.;                                                                                     //задание начального значения х

		do {                                                                                                     //начало цикла
			cout <<"iter #"<< iteration <<endl <<"a=" << x1 << endl;                                                         //вывод номера итерации и значения х
			x0 = x1;                                                                                              //задание значения х0                  
			f = simp_result(x0); 
			//cout << f;//расчет ф(х0)
			//x1 = f;   
			x1=pow(M_E ,-pow(M_E,0.2*x0)-log(0.35));                                                                         //x1 = ф(х0))
			iteration++;                                                                                                 //счетчик итераций
			cout << "\t" << "f: " << f << endl;                                                                    //вывод ф(х)

			if ((abs(x0 - x1) < pow(10, eps)) || (x1 > ma) || (x0 > ma) || (x1 < mi) || (x0 < mi)) { break; }                                         //условие прекращения работы цикла
		} while ((abs(mi - x0) >= pow(10, eps)) && (abs(ma - x0) >= pow(10, eps)));                                                       //условие работы цикла

		cout << "answer: " << x0 << endl << "iteration: " << iteration - 1 << endl << "f: " ; printf("%.5f",f);
	//}
}




