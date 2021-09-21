//sqrt(1-0.4*x*x)-arcsin(x)=0
	//iterations
	//f(x)=0
	//[0;1]
//variant 10
#include <iostream>
using namespace std;
double mi = 0, ma = 1;
double eps = 0.00001;
double x0, x1,f;
int iteration=0;



int main(){
	x1 = (mi + ma) / 2;

   
	for (abs(x0 - x1) > eps;;) {
		cout << iteration << "\t" << x1 << endl;
        x0 = x1; 
		f = sqrt(1 - 0.4 * x0 * x0) - asin(x0);
		x1 = f;
		iteration++;
		if ((x1 < mi) || (x1 > ma)) { break; }
	
}

	cout << "answer: " << x0 << endl <<"iteration: " << iteration << endl;
}
