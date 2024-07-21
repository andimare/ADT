#include <iostream>
using namespace std;

void factorialArray(int arr[], int r){
	for(int x = 0; x < r; x++){
		int base = arr[x];
		int X = arr[x];
		 
		while(arr[x] > 1){
			arr[x]--;
			base *= arr[x];
		}
		
		cout<<"Factorial for ("<<X<<") is : "<<base<<endl<<endl;
	}
}

int main(){
	unsigned int r, elem;
	
	cout<<"Enter the number of elements you want : ";
	cin>>r;
	
	int b = r;	
	int arr[r];
	
	while(r > 0){
		--r;
		cout<<"Enter the element at index ["<<r<<"] : ";
		cin>>elem;
		arr[r] = elem;
	}
	
	factorialArray(arr, b);
	
	return 0;
}
