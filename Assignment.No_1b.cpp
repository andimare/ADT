//My selection sort
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Frequency{
	int mode;
	int value;
};

//Set the frequency for the distinct numbers in the array
void initializeStruct(Frequency freq[], vector<int>& arr, vector<int>& coll){
	
	cout<<"Frequency distibution within the elements"<<endl;
	
	for(int i = 0; i < coll.size(); i++){
		freq[i].value = coll[i];
		int count = 0;
		
		while(freq[i].value == arr[0] && !arr.empty() ){
			count++;
			arr.erase(arr.begin());
		}
		
		freq[i].mode = count;
		
		cout<<"["<<freq[i].value<<"] : "<<freq[i].mode<<endl;
	}
}

//Get the number of distinct element function declaration
void countDistinctValues(vector<int>& num){
	
	for(int i = 0;i < num.size(); i++){
		int j = i + 1;
		
		while(j < num.size()){
			if(num[i] != num[j]){
				break;
			}else{
				num.erase(num.begin() + j);
			}
		}
		
	}
	
}

//Looking for the mode
void checkMode(Frequency freq[], int total){
	int max = 0;
	int index;
	
	for(int i = 0; i < total; i++){
		if(freq[i].mode > max){
			max = freq[i].mode;
			index = i;	
		}
	}
	
	int num_max = 0;
	
	for(int i = 0; i < total; i++){
		if(max == freq[i].mode) num_max++;
	}
	
	if(num_max > 1 || num_max < 1) cout<<"We don't have a mode in the array"<<endl;
	else cout<<"The mode is ["<<freq[index].value<<"] with a frequency of : "<<max<<endl;
}


int main(){
	
	//You can change the contains in the culry braces to test the mode function
	vector<int> blame = {34,6,4,23,5,8,3,6,4,4,2,34,6,28,23,23,6};
	
	//sorting the array first
	//To easy our work
	for(int i = 0; i < blame.size(); ++i){
		int min = i,j = i + 1;
		
		while(j < blame.size()){
			if(blame[min] > blame[j]) min = j;
			j++;
		}
		
		int dummy = blame[i];
		blame[i] = blame[min];
		blame[min] = dummy;
	}
	
	//Printing out the array
	//After being sorted
	int i = 0;
	
	cout<<"Original Array sorted : {";
	
	while(i < blame.size()){
		if(i != 0) cout<<",";
		cout<<blame[i];
		i++;
	}
	
	cout<<"}"<<endl;
	
	//Making a copy of the original array
	vector<int> blm = blame;
	
	//Getting the number of distincit element in the array
	countDistinctValues(blame);
	
	
	//Printing out the distinct values
	cout<<"Distinct array elements : {";
	
	i = 0;
	while(i < blame.size()){
		if(i != 0) cout<<",";
		cout<<blame[i];
		i++;
	}
	
	cout<<"}"<<endl;
	
	//Declaration of the frequency struct
	Frequency collection[blame.size()];
	
	//Intializiting the struct
	initializeStruct(collection, blm, blame);
	
	//Now get the mode of the array
	checkMode(collection, blame.size());
	
	return 0;
}
