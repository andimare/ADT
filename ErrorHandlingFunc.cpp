#include <iostream>
#include <exception>
#include <cmath>
using namespace std;

double f(double x) {
	
	return sqrt((x*x*x) - 1);
}

int main(){
	int x;
	
	cout<<"Enter the value of x : ";
	cin>>x;
	
	try{
		if(y < 1) throw y;
		cout<<f(x)<<endl;
	}
	catch(int x){
		cerr << "getting a square root for a value less than 0! " << endl;
	}
	
	return 0;
}
