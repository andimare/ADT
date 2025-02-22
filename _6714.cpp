// Theory of 6174
// Yet to run the test for the range btw 0 - 9999

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

int subtract(int test){
	
	int* num = extractDigits(test);
	
	static vector<int> vals;
	vals.push_back(0);
	
	int difference = biggerValue(num) - smallerValue(num);

	for(int i = vals.size(); i > 0; i--) {
		if(vals[i-1] == difference){
			
			delete [] num;
			
			return difference;
		}
	}
	
	vals.push_back(difference);

	delete [] num;

	return subtract(difference);
}

int main(){
	int sample;
	int i = 0;
	vector<int> outlayers;
	number:
		
	cout<<"Enter a random max of a four digit number"<<endl;
	cin>>sample;
	
	if(sample > 9999 || sample < 0) {
		cout<<"The number is out of the range expected."<<endl;
		goto number;
	}
	
//	for(int j = 0;j < 10000;j++) {
//		int val = subtract(9998);
//		
//		if(val != 6174){
//			outlayers.push_back(j);
//		}
//		cout<<9998<<" -> "<<val<<endl;
//	}
	
	cout<<"Here is the final number : "<<subtract(sample)<<endl;
	
//	cout<<"["<<endl;
//	for(auto num : outlayers) {
//		cout<<num<<" ,"<<endl;
//	}
//	cout<<"]"<<endl;
	
	return 0;
}
