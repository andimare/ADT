#include <iostream>
using namespace std;

double powerFloat(double& X, int n ){
	double value = X;
	
	while(n > 1){
		value *= X;
		
		--n;
	}
	
	return value;
}

int main(){
	int n;
	double x;
	
	cout<<"Enter the (float) base value : ";
	cin>>x;
	
	cout<<"Enter the (int) power value : ";
	cin>>n;
	cout<<endl;
	
	if(n > 0) cout<<"Final value : "<<powerFloat(x, n);
	else cout<<"You entered a negative power"<<endl;
	
	return 0;
}
