#include <iostream>
using namespace std;

double x[] = { 0.9, 0.96, 1, 1.12, 1.25, 1.29, 1.35, 1.4 };
double y[] = { 20, 47, 37, 16, -29, -37, -4, 15 };
int m = 4;//степень полинома(n)
double a[5][5];
double b[5];
double ans[5];
//N+1=8

double gauss_method() {
	/*double a[4][4] = { 7.6, 0, 12.3, 9.9,     8.7, 12.1, 3.9, 8,     0, 6, 7.4, 9.3,     5.6, 8.4, 10.2, 6.7 };
	double b[4] = { 18 ,12.5, -14.7 ,11.9 };*/

	
	//double sum;
	double times;

	/////////////////////////////////////////////////
	for (int c = 1; c < 5; c++) {
		int z = 0;
		if (a[c][z] > 0) {
			times = (-a[c][z] / a[z][z]);
			a[c][z] = a[c][z] + a[z][z] * (-a[c][z] / a[z][z]);
			for (int i = 1; i < 5; i++) {
				a[c][i] = a[c][i] + a[z][i] * times;
			}
			b[c] = b[c] + b[z] * times;
		}
		else {
			times = (a[c][z] / a[z][z]);
			a[c][z] = a[c][z] + a[z][z] * (a[c][z] / a[z][z]);
			for (int i = 1; i < 5; i++) {
				a[c][i] = a[c][i] + a[z][i] * times;
			}
			b[c] = b[c] + b[z] * times;
		}
	}
	//for (int c = 0; c < 5; c++) {
	//	for (int i = 0; i < 5; i++) {
	//		cout << a[c][i] << "  ";
	//	}
	//	cout << "\t" << b[c] << endl << endl;
	//}cout << "                             " << endl;
	for (int c = 2; c < 5; c++) {
		int z = 1;
		if (a[c][z] > 0) {
			times = (-a[c][z] / a[z][z]);
			a[c][z] = a[c][z] + a[z][z] * (-a[c][z] / a[z][z]);
			for (int i = 2; i < 5; i++) {
				a[c][i] = a[c][i] + a[z][i] * times;
			}
			b[c] = b[c] + b[z] * times;
		}
		else {
			times = (a[c][z] / a[z][z]);
			a[c][z] = a[c][z] + a[z][z] * (a[c][z] / a[z][z]);
			for (int i = 2; i < 5; i++) {
				a[c][i] = a[c][i] + a[z][i] * times;
			}
			b[c] = b[c] + b[z] * times;
		}
	}
	/*for (int c = 0; c < 5; c++) {
		for (int i = 0; i < 5; i++) {
			cout << a[c][i] << "  ";
		}
		cout << "\t" << b[c] << endl << endl;
	}cout << "                             " << endl;*/
	
	for (int c = 3; c < 5; c++) {
		int z = 2;
		if (a[c][z] > 0) {
			times = (-a[c][z] / a[z][z]);
			a[c][z] = a[c][z] + a[z][z] * (-a[c][z] / a[z][z]);
			for (int i = 3; i < 5; i++) {
				a[c][i] = a[c][i] + a[z][i] * times;
			}
			b[c] = b[c] + b[z] * times;
		}
		else {
			times = (a[c][z] / a[z][z]);
			a[c][z] = a[c][z] + a[z][z] * (a[c][z] / a[z][z]);
			for (int i = 3; i < 5; i++) {
				a[c][i] = a[c][i] + a[z][i] * times;
			}
			b[c] = b[c] + b[z] * times;
		}
	}
	a[4][2] = 0;
	/*for (int c = 0; c < 5; c++) {
		for (int i = 0; i < 5; i++) {
			cout << a[c][i] << "  ";
		}
		cout << "\t" << b[c] << endl << endl;
	}cout << "                             " << endl;*/
	
	for (int c = 4; c < 5; c++) {
		int z = 3;
		if (a[c][z] > 0) {
			times = (-a[c][z] / a[z][z]);
			a[c][z] = a[c][z] + a[z][z] * (-a[c][z] / a[z][z]);
			for (int i = 4; i < 5; i++) {
				a[c][i] = a[c][i] + a[z][i] * times;
			}
			b[c] = b[c] + b[z] * times;
		}
		else {
			times = (a[c][z] / a[z][z]);
			a[c][z] = a[c][z] + a[z][z] * (a[c][z] / a[z][z]);
			for (int i = 4; i < 5; i++) {
				a[c][i] = a[c][i] + a[z][i] * times;
			}
			b[c] = b[c] + b[z] * times;
		}
	}
	

	for (int c = 0; c < 5; c++) {
		for (int i = 0; i < 5; i++) {
			cout << a[c][i] << "  ";
		}
		cout << "\t" << b[c] << endl << endl;
	}cout << "                             " << endl;


	ans[4] = b[4] / a[4][4];
	cout << "a5= " << ans[4] << endl;
	ans[3] = (b[3] - ans[4] * a[3][4]) / a[3][3];
	cout << "a4= " << ans[3] << endl;
	ans[2] = (b[2] - ans[4] * a[2][4] - ans[3] * a[2][3] ) / a[2][2];
	cout << "a3= " << ans[2] << endl;
	ans[1] = (b[1] - ans[4] * a[1][4] - ans[3] * a[1][3] - ans[2] * a[1][2]) / a[1][1];
	cout << "a2= " << ans[1] << endl ;
	ans[0] = (b[0] - ans[4] * a[0][4] - ans[3] * a[0][3] - ans[2] * a[0][2] - ans[1] * a[0][1]) / a[0][0];
	cout << "a1= " << ans[0] << endl << endl;
	return 0;
}

int main(){
	for (int i = 0; i < 5; i++) {				//
		for (int j = 0; j < 5; j++) {            //
			int n = i + j;                        //
			for (int z = 0; z < 8; z++) {         //
				a[i][j] += pow(x[z], n);           //
			}                                       //
		}                                           //
	}                                                //

	/*for (int i = 0; i < 5; i++) {                      создание матрицы
		for (int j = 0; j < 5; j++) {
			cout << a[i][j] << endl;
		}
	}*/

	for (int i = 0; i < 5; i++) {                    //
		for (int z = 0; z < 8; z++) {               //
			b[i] += y[z] * pow(x[z], i);           //
		}                                        //
		//cout << b[i] << endl;
	}                                        //


	for (int c = 0; c < 5; c++) {
		for (int i = 0; i < 5; i++) {
			cout << a[c][i] << "  ";
		}
		cout << "\t" << b[c] << endl << endl;
	}cout << "                             " << endl;

	gauss_method();//решение матрицы

	double p[8];
	for (int i = 0; i < 8; i++) {
		p[i] = 0;
		for (int j = 0; j < 5; j++) {
			p[i] += ans[j] * pow(x[i], j - 1);
		}
		cout << p[i] << endl;
	}
	cout << endl;

	double diff[8];
	for (int i = 0; i < 8; i++) {
		diff[i] = 0;
		diff[i] = p[i] - y[i];
		cout << diff[i] << endl;
	}
}