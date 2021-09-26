//sqrt(1-0.4*x*x)-arcsin(x)=0
	//iterations
	//f(x)=0
	//[0;1]
//variant 10
#include <iostream>
using namespace std;
double mi = 0, ma = 1;
int eps;
double x0, x1,f;                                                                          //объявление переменных
int iteration=0;

int main() {
	
	cout << "Write eps (negative degree of ten)\n";                                       //задание точности вводом степени десяти
	cin >> eps;

	x1 = floor(((mi + ma) / 2)*pow(10,-eps))*pow(10,eps);                                 //задание начального значения х
	
   do{                                                                                    //начало цикла
		cout << iteration << "\t" << x1 << endl;                                          //вывод номера итерации и значения х
        x0 =floor( x1* pow(10, -eps))* pow(10, eps);                                      //задание значения х0                  
		f = floor((sqrt(1 - 0.4 * x0 * x0) - asin(x0))* pow(10, -eps))* pow(10, eps);     //расчет ф(х0)
		x1 = f;                                                                           //x1 = ф(х0)
		iteration++;                                                                      //счетчик итераций
		cout << "\t" << "f: " << f << endl;                                               //вывод ф(х)

		   if ((x1 < mi) || (x1 > ma)) { break; }                                         //условие прекращения работы цикла
      }	while (abs(x0 - x1) > eps);                                                       //условие работы цикла

	cout << "answer: " << x0 << endl <<"iteration: " << iteration-1 << endl<<"f: "<< f << endl;
}                                                                                         //вывод ответа: х, кол-во итераций, ф
