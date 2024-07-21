//My selection sort
//Catching median
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	int blame[] = {34,6,4,23,5,4,23,3};
	int total_elem = sizeof(blame) / sizeof(blame[0]);
	
	//sorting the array first
	for(int i = 0; i < total_elem; ++i){
		int min = i,j = i + 1;
		
		while(j < total_elem){
			if(blame[min] > blame[j]) min = j;
			j++;
		}
		
		int dummy = blame[i];
		blame[i] = blame[min];
		blame[min] = dummy;
	}
	
	//Printing out the array
	int i = 0;
	
	cout<<"{";
	
	while(i < total_elem){
		if(i != 0) cout<<",";
		cout<<blame[i];
		i++;
	}
	
	cout<<"}";
	
	//Looking for the median
	int mid_point = total_elem / 2;
	
	if((total_elem % 2) == 1){
		mid_point += 1;
		cout<<"Median : "<<blame[mid_point]<<endl;
	}else{
		double mid = static_cast<double>(blame[mid_point] + blame[mid_point + 1]) / 2;
		cout<<"Median : "<<mid<<endl;
	}

	return 0;
}
