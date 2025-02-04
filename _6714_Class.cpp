
#include<iostream>
#include<cmath>
#include <vector>
using namespace std;

int* selectionSort(int* arr) {
    int n = 4;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return arr;
}

int* extractDigits(int num){
	int* digits = new int[4];
//	int j = 0;
	
	for(int i = 0; i < 4; i++){
		digits[i] = num % 10;
		num /= 10;
	}
	
	return selectionSort(digits);
}

int biggerValue(int* arr){
	int value = 0;
	
	for(int i = 0; i < 4; i++){
		value += arr[3-i] * pow(10,3-i);
	}
	
	return value;
}


int smallerValue(int* arr){
	int value = 0;
	
	for(int i = 0; i < 4; i++){
		value += arr[i] * pow(10,3-i);
	}
	
	return value;
}

class Namba{
	private:
		int value, cycles, result;
		vector<int> vals;
		int difference;
	
	public:
		setNamba(int value){
			this->value = value;
			this->difference = this->value;
			this->cycles = 0;
			
			this->result = this->subtract();
		}
		
		int subtract(){
			this->cycles++;
			
			int* num = extractDigits(difference);
			
			vals.push_back(0);
			
			difference = biggerValue(num) - smallerValue(num);
		
			for(int i = vals.size(); i > 0; i--) {
				if(vals[i-1] == difference){
					
					delete [] num;
					
					return difference;
				}
			}
			
			vals.push_back(difference);
		
			delete [] num;
		
			return this->subtract();
		}
		
		printOut(){
			cout<<"[\'"<<value<<"\',";
			cout<<"\'"<<cycles<<"\',";
			cout<<"\'"<<result<<"\']"<<endl;
//			cout<<"[\'"<<value<<"\',";
		}
};

int main() {
	
	for(int j = 0;j < 10000;j++) {
		Namba test;
		
		test.setNamba(j);
		test.printOut();
		
//		cout<<9998<<" -> "<<val<<endl;
	}
	
	return 0;
}
