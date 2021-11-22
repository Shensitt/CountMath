#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

double func(double x) {                //подинтегральная функция 
    return (log(0.35 * x) + pow(M_E, 0.2 * x)) / (sin(x) + 1.5);
}

double a = 0.1, b;
int cut_count = 1;
double h;
double  res1 = 0;                    //объявление переменных для метода Симпсона
double  result = 0;
double  answer;

double  simp_method(int cut_count, double b) {
    //подпрограмма вычисления интеграла
    h = (b - a) / cut_count;
    answer = func(a) + func(b);
    double  sum = 0;
    for (int i = 1; i <= cut_count - 1; i++) {
        double  xi = a + i * h;
        sum += (3 - pow(-1., i)) * func(xi);
    }
    double  result = (sum + answer) * (h / 3);
    return result;
}
double int_eps;
double simp_result(double a0) {
    //подпрограмма удвоения кол-ва разбиений и увеличения точности
    result = simp_method(cut_count, a0);
    cut_count = 1;
    for (int_eps = 0.2; int_eps > pow(10., -20); int_eps /= 2) {
        if ((abs(res1 - result) <= int_eps)) { break; }
        res1 = result;
        cut_count *= 2;
        result = simp_method(cut_count, a0);
    }
    return result;
}

double mi_a = 0.2, ma_a = 8;
double eps = -3;
double a0, a1, f;
int iteration = 0;
//объявлений переменных для основной подпрограммы     

int main() {                                //основная подпрограмма
    a1 = (mi_a + ma_a) / 2;
    for (;;) {
        cout << "iter #" << iteration << endl << "a=" << a1 << endl;
        a0 = a1;
        f = simp_result(a0);
        if (f > 0) {
            ma_a = a0;
            a1 = (mi_a + ma_a) / 2;
        }
        else {
            mi_a = a0;
            a1 = (mi_a + ma_a) / 2;
        }
        cout << "f= " << f << endl;
        iteration++;
        cout << "\t" << "f: " << f << endl;
        if ((abs(a0 - a1) < pow(10, eps)) || (a1 > ma_a) || (a0 > ma_a) || (a1 < mi_a) || (a0 < mi_a)) { break; }
    }
    cout << "answer: " << a0 << endl << "iteration: " << iteration - 1 << endl << "f: "; printf("%.5f", f);
    cout << endl;
}



