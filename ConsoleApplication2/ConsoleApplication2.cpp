#include <iostream>
using namespace std;
double x0,x1,mi=1,ma=1.5,f;
int eps,iteration;

int main() {
	
	cout << "write eps(negative degree of ten)\n";
	cin >> eps;//задание точности вводом степени десяти

	for(double i =0;i<10;i=i+0.5){//цикл для определения частка поиска корня
		mi = i;
		ma = i + 0.5;
		cout << "searching for the answer in the area of: " << mi << ".." << ma<<endl ;//задание минимального и максимального значения на участке
		iteration = 0;
		x1 = (mi + ma) / 2;//задание первого х
		do {
			cout << "iteration #: " << iteration << "\tx = " << x1 << endl;//вывод номера итерации и x0
			x0 = x1;
			f = cos(x0) - (0.1 * sqrt(x0));//f=F(x)
			x1 = acos(0.1*sqrt(x0));//x1=f(x0)
			cout << "\t\tfunction = " << f << endl;//вывод значения функции
			iteration++;//счетчик итераций

			if ((abs(x0 - x1) <= pow(10, eps)) || (x1 > ma) || (x0 > ma) || (x1 < mi) || (x0 < mi)) { break; }
		} while ((abs(mi - x0) >= pow(10, eps)) && (abs(ma - x0) >= pow(10, eps)));//условия выполнения цикла и его прекращения
		if (iteration > 1) {
			cout << "\nanswer: " << x0 << endl << "iteration: " << iteration - 1 << endl << "f: " << f << endl<<endl;//вывод найденного корня на отрезке
		}

	}
}
