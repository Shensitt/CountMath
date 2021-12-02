#include <iostream>
using namespace std;
double a[4][4] = { 7.6, 0, 12.3, 9.9,     8.7, 12.1, 3.9, 8,     0, 6, 7.4, 9.3,     5.6, 8.4, 10.2, 6.7 };
//double b[4] = { 18 ,12.5, -14.7 ,11.9 };

int main() {
	double u0[4] = { 1,0,0,0 };//1
	double u1[4];
	double u2[4];
	//u1=a*u0


	u1[0]= a[0][0] * u0[0] + a[0][1] * u0[1] + a[0][2] * u0[2] + a[0][3] * u0[3];//
	u1[1]= a[1][0] * u0[0] + a[1][1] * u0[1] + a[1][2] * u0[2] + a[1][3] * u0[3]; //2
	u1[2]= a[2][0] * u0[0] + a[2][1] * u0[1] + a[2][2] * u0[2] + a[2][3] * u0[3];//
	u1[3]= a[3][0] * u0[0] + a[3][1] * u0[1] + a[3][2] * u0[2] + a[3][3] * u0[3];//
	//cout << u1[0];
	double sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += pow(u0[i], 2);
	}
	double mod_u0 = sqrt(sum);
	//cout << mod_u0;

	sum = 0;
	for (int i = 0; i < 4; i++) {                            //2
		sum += pow(u1[i], 2);
	}
	double mod_u1 = sqrt(sum);
	//cout << mod_u1;

	double lambda = mod_u1 / mod_u0;
	//cout << lambda<<endl;



	for(;;){
	

		u2[0] = a[0][0] * u1[0] + a[0][1] * u1[1] + a[0][2] * u1[2] + a[0][3] * u1[3];//
		u2[1] = a[1][0] * u1[0] + a[1][1] * u1[1] + a[1][2] * u1[2] + a[1][3] * u1[3]; //3
		u2[2] = a[2][0] * u1[0] + a[2][1] * u1[1] + a[2][2] * u1[2] + a[2][3] * u1[3];//
		u2[3] = a[3][0] * u1[0] + a[3][1] * u1[1] + a[3][2] * u1[2] + a[3][3] * u1[3];//
		//cout << u1[0];
		sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += pow(u1[i], 2);
		}
		mod_u1 = sqrt(sum);
		//cout << mod_u0;

		sum = 0;
		for (int i = 0; i < 4; i++) {                            //3
			sum += pow(u2[i], 2);
		}
		double mod_u2 = sqrt(sum);
		//cout << mod_u1;

		double lambda1 = mod_u2 / mod_u1;
		//cout << lambda1;

	
//cout << abs(lambda - lambda1)<<endl;
		if (abs(lambda - lambda1) < 0.001) {
			cout << "~first self amount: " << lambda1 << endl;
			cout << "~self vector: " << endl;
			for (int i = 0; i < 4; i++) {
				cout  << u2[i] << endl;
			}
		
			break;
		}
		//else {
		
		for (int i = 0; i < 4; i++) {
			u1[i] = u2[i];
		 }
		 lambda = lambda1;
	//}
	}
}