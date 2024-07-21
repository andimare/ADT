//My selection sort
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

vector<int> coll;

struct Frequency{
	int mode;
	int value;
};

//Set the frequency for the distinct numbers in the array
void intializeStruct(int num, Frequency freq[], vector<int>& arr){
	
	cout<<"Frequency distibution within the elements"<<endl;
	
	for(int i = 0; i < num; i++){
		freq[i].value = coll[i];
		int count = 0;
		
		while(freq[i].value == arr[0]){
			count++;
			arr.erase(arr.begin());
		}
		
		freq[i].mode = count;
		
		cout<<"["<<freq[i].value<<"] : "<<freq[i].mode<<endl;
	}
}

//Get the number of distinct element function declaration
int countDistinctValue(vector<int>& num){
	int count = 1;
	
	for(int i = 0;i < num.size(); i++){
		int j = i + 1;
		while(j < num.size()){
			if(num[i] == num[j]){
				num.erase(num.begin() + j);
			}else{
				count++;
				coll.push_back(num[i]);
				break;
			}
		}
	}
	
	return count - 1;
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
	vector<int> blame = {34,6,4,23,5,8,3,6,4,4,2,3,6,28,23,23,6};
	int total_elem = blame.size();
	
	//sorting the array first
	//To easy our work
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
	//After being sorted
	int i = 0;
	
	cout<<"Original Array sorted : {";
	
	while(i < total_elem){
		if(i != 0) cout<<",";
		cout<<blame[i];
		i++;
	}
	
	cout<<"}"<<endl;
	
	//Making a copy of the original array
	vector<int> blm = blame;
	
	//Getting the number of distincit element in the array
	int dist = countDistinctValue(blame);
	
	
	//Printing out the distinct values
	cout<<"Distinct array elements : {";
	
	i = 0;
	while(i < coll.size()){
		if(i != 0) cout<<",";
		cout<<coll[i];
		i++;
	}
	
	cout<<"}"<<endl;
	
	//Declaration of the frequency struct
	Frequency collection[dist];
	
	//Intializiting the struct
	intializeStruct(dist, collection, blm);
	
	//Now get the mode of the array
	checkMode(collection, dist);
	
	return 0;
}
