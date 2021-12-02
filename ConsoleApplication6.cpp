#include <iostream>
//#include <math.h>
using namespace std;
//var10

double gauss_method() {
	double a[4][4] = { 7.6, 0, 12.3, 9.9,     8.7, 12.1, 3.9, 8,     0, 6, 7.4, 9.3,     5.6, 8.4, 10.2, 6.7 };
	double b[4] = { 18 ,12.5, -14.7 ,11.9 };
	
	double x[4];
	//double sum;
	double times;
	
	/////////////////////////////////////////////////

	cout << "Gauss method" << endl;
	for (int c = 1; c < 4; c++) {
		if (a[c][0] > 0) {
			times = (-a[c][0] / a[0][0]);
			a[c][0] = a[c][0] + a[0][0] * (-a[c][0] / a[0][0]);
			for (int i = 1; i < 4; i++) {
				a[c][i] = a[c][i] + a[0][i] * times;
			}
			b[c] = b[c] + b[0] * times;
		}
		else {
			times = (a[c][0] / a[0][0]);
			a[c][0] = a[c][0] + a[0][0] * (a[c][0] / a[0][0]);
			for (int i = 1; i < 4; i++) {
				a[c][i] = a[c][i] + a[0][i] * times;
			}
			b[c] = b[c] + b[0] * times;
		}
	}
	/*for (int c = 0; c < 4; c++) {
		for (int i = 0; i < 4; i++) {
			cout << a[c][i] << "  ";
		}
		cout << "\t\t"<<b[c] << endl << endl;
	}
	cout << "                             "<<endl;*/


	
	/////////////////////////////////////////////////////////////
	
	for (int c = 2; c < 4; c++) {
		if (a[c][1] > 0) {
			times = (-a[c][1] / a[1][1]);
			a[c][1] = a[c][1] + a[1][1] * (-a[c][1] / a[1][1]);
			for (int i = 2; i < 4; i++) {
				a[c][i] = a[c][i] + a[1][i] * times;
			}
			b[c] = b[c] + b[1] * times;
		}
		else {
			times = (a[c][1] / a[1][1]);
			a[c][1] = a[c][1] + a[1][1] * (a[c][1] / a[1][1]);
			for (int i = 2; i < 4; i++) {
				a[c][i] = a[c][i] + a[1][i] * times;
			}
			b[c] = b[c] + b[1] * times;
		}
	}
	
	/*for (int c = 0; c < 4; c++) {
		for (int i = 0; i < 4; i++) {
			cout << a[c][i] << "  ";
		}
		cout << "\t\t" << b[c] << endl << endl;
	}cout << "                             " << endl;*/
	//////////////////////////////////////////////////////////////
	for (int c = 3; c < 4; c++) {
		if (a[c][2] > 0) {
			times = (-a[c][2] / a[2][2]);
			a[c][2] = a[c][2] + a[2][2] * (-a[c][2] / a[2][2]);
			for (int i = 3; i < 4; i++) {
				a[c][i] = a[c][i] + a[2][i] * times;
			}
			b[c] = b[c] + b[2] * times;
		}
		else {
			times = (a[c][2] / a[2][2]);
			a[c][2] = a[c][2] + a[2][2] * (a[c][2] / a[2][2]);
			for (int i = 3; i < 4; i++) {
				a[c][i] = a[c][i] + a[2][i] * times;
			}
			b[c] = b[c] + b[2] * times;
		}
	}

	for (int c = 0; c < 4; c++) {
		for (int i = 0; i < 4; i++) {
			cout << a[c][i] << "  ";
		}
		cout << "\t" << b[c] << endl << endl;
	}cout << "                             " << endl;


	////////////////////////////////////////////////
	

	x[3] = b[3] / a[3][3];
	cout << "x4= " << x[3]<<endl;
	x[2] = (b[2] - x[3] * a[2][3])/a[2][2];
	cout << "x3= " << x[2] << endl;
	x[1] = (b[1] - x[3] * a[1][3] - x[2] * a[1][2]) / a[1][1];
	cout << "x2= " << x[1] << endl;
	x[0] = (b[0] - x[3] * a[0][3] - x[2] * a[0][2] - x[1] * a[0][1]) / a[0][0];
	cout << "x1= "<<x[0] << endl<<endl;
	return 0;
}


	/*for (int c = 0; c < 4; c++) {
		for (int i = 0; i < 4; i++) {
			cout << a[c][i] << "  ";
		}
		cout << "\t\t"<<b[c] << endl << endl;
	}
	cout << "                             "<<endl;*/


	//if (norma >= 1) {
	//	for (int j = 0; j < 4; j++) {
	//		for (int i = 0; i < 4; i++) {
	//			a[j][i] /= norma + 1;
	//		}
	//		b[j] /= norma + 1;
	//	}

	//}
	//norma = 0;
	//for (int i = 0; i < 4; i++) {
	//	normass[i] = 0;
	//	for (int j = 0; j < 4; j++) {
	//		normass[i] += a[i][j];
	//	}
	//	if (abs(norma) < normass[i]) {
	//		norma = abs(normass[i]);
	//	}
	//}


double simp_iter_method() {
	double a[4][4] = { 7.6, 0., 12.3, 9.9,     8.7, 12.1, 3.9, 8.,     0., 6., 7.4, 9.3,     5.6, 8.4, 10.2, 6.7 };
	double b[4] = { 18 ,12.5, -14.7 ,11.9 };
	double x[4], norma, normass[4], y[4]; double delta = 0;
	double eps = 0.0001;

	cout << "simple iterations method: " << endl;
	norma = 0; int norma_num;
	for (int i = 0; i < 4; i++) {
		normass[i] = 0;
		for (int j = 0; j < 4; j++) {
			normass[i] += a[i][j];
		}
		if (abs(norma) < normass[i]) {
			norma = normass[i];
			norma_num = i;
		}
	}

	for (int i = 0; i < 4; i++) {//1
		x[i] = 0;
	}

	for (int c = 0; c < 4; c++) {
		for (int i = 0; i < 4; i++) {
			cout << a[c][i] << "  ";
		}
		cout << "\t\t" << b[c] << endl << endl;
	}
	cout << "                             " << endl;

	do {
		if (abs(norma) > 1) { cout << "norma- " << norma << endl; break; }
		for (int z = 0; z < 4; z++) {
			

			/*norma = 0;
			for (int i = 0; i < 4; i++) {
				normass[i] = 0;
				for (int j = 0; j < 4; j++) {
					normass[i] += a[i][j];
				}
				if (abs(norma) < normass[i]) {
					norma = abs(normass[i]);
				}
			}*/
			//int norma_num;
			norma = 0;
			for (int i = 0; i < 4; i++) {
				normass[i] = 0;
				for (int j = 0; j < 4; j++) {
					normass[i] += a[i][j];
				}
				if (abs(norma) < normass[i]) {
					norma = normass[i];
					norma_num = i;
				}
			}
			////////////////////////////////////////////////////problem here may be
			//while (abs(norma) >= 1) {
			//	//cout << norma<<endl;
			//	cout << norma_num<<endl;
			//	int deal_count = 0;
			//	if (normass[norma_num] > 0) {
			//		for (int j = 0; j < 4; j++) {
			//			if (deal_count != 0) { break; }
			//			if (normass[j] != normass[norma_num]) {
			//				if (normass[j] > 0) {
			//					for (int i = 0; i < 4; i++) {
			//						a[norma_num][i] -= a[j][0] / 10;
			//					}
			//					b[norma_num] -= a[j][0] / 10;
			//					deal_count++;
			//				}
			//				else {
			//					for (int i = 0; i < 4; i++) {
			//						a[norma_num][i] += a[j][0] / 10;
			//					}
			//					b[norma_num] += a[j][0] / 10;
			//					deal_count++;
			//				}
			//			}
			//			
			//		}
			//	}


			//	norma = 0;
			//	for (int i = 0; i < 4; i++) {
			//		normass[i] = 0;
			//		for (int j = 0; j < 4; j++) {
			//			normass[i] += a[i][j];
			//		}
			//		if (abs(norma) < normass[i]) {
			//			norma = abs(normass[i]);
			//			norma_num = i;
			//		}
			//	}

			//	for (int c = 0; c < 4; c++) {
			//		for (int i = 0; i < 4; i++) {
			//			cout << a[c][i] << "  ";
			//		}
			//		cout << "\t\t" << b[c] << endl << endl;
			//	}
			//	cout << "                             " << endl;
			//	//cout << norma << endl;
			//	//cout << norma_num;
			//}
			///////////////////////////////////////////////
			/*norma = 0;
			for (int i = 0; i < 4; i++) {
				normass[i] = 0;
				for (int j = 0; j < 4; j++) {
					normass[i] += a[i][j];
				}
				if (abs(norma) < normass[i]) {
					norma = normass[i];
				}
			}*/

			/*cout << "norma- " << norma << endl;
			for (int c = 0; c < 4; c++) {
				for (int i = 0; i < 4; i++) {
					cout << a[c][i] << "  ";
				}
				cout << "\t\t" << b[c] << endl << endl;
			}
			cout << "                             " << endl;*/

			double beta[4];
			/*if (a[z][z] == 0) {
				cout << "dividing on 0 error" << endl;
				break;
			}*/

			double sum = 0;
			double temp = a[z][z];
			for (int j = 0; j < 4; j++) {
				if (z != j) {
					a[z][j] = a[z][j] / temp;
				}
				else {
					a[z][j] = 0;
				}
				//b[z] /= temp;
					//может быть надо дописаь чему равно b
				//cout << a[z][j] << endl;
				sum += a[z][j] * x[j];
			}
			beta[z] = b[z] / temp;
			//cout << beta[z];
			//cout << sum;

			y[z] = beta[z] - sum;
			delta = 0;
			//cout << y[z];
			if (abs((x[z]) - (y[z])) >= delta) {
				delta = abs(x[z] - y[z]);
			}
			
			x[z] = y[z];
			//cout << delta;
			

			/*for (int c = 0; c < 4; c++) {
				for (int i = 0; i < 4; i++) {
					cout << a[c][i] << "  ";
				}
				cout << "\t\t" << b[c] << endl << endl;
			}
			cout << "                             " << endl;*/

			if (delta < eps) {
				for (int i = 0; i < 4; i++) {
					cout << "x" << i + 1 << "= " << x[i] << endl;
				}
				break;
			}

			/*for (int i = 0; i < 4; i++) {
					cout << "x" << i + 1 << "= " << x[i] << endl;
				}*/
		}
	}while (delta > eps);
	
	
	return 0;
}

	
	//cout << norma;

	



int main() {
	gauss_method();
	simp_iter_method();
}
