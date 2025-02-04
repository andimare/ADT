#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class Type>
void removeDuplicate(Type a[], int& n) {
	vector<Type> vec;
	
	for(int i = 0; i < n; i++){
		vec.push_back(a[i]);
	}
	
	for(int i = 0; i < vec.size(); i++){
		int j = i + 1;
		
		while(j < vec.size()){
			if(vec[i] == vec[j]){
				vec.erase(vec.begin() + j);
				continue;
			}
			++j;
		}
		
	}
	
	n = vec.size();
	
}

template <class Type2>
void removeDuplicate(vector<Type2> vec, int& n) {
	for(int i = 0; i < vec.size(); i++){
		int j = i + 1;
		
		while(j < vec.size()){
			if(vec[i] == vec[j]){
				vec.erase(vec.begin() + j);
				continue;
			}
			++j;
		}
		
	}
	
	n = vec.size();
}

int main(){
	vector<int> arr = {34,6,4,23,5,8,3,6,4,4,2,34,6,28,23,23,6};
	string str[] = {"a","ew","wed","a","we"};
	char chr[] = {'r','e','b','s','e','h','h','e'};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	removeDuplicate(arr, n);
	
	cout<<"N value : "<<n<<endl;
	
	int t = sizeof(str)/sizeof(str[0]);
	
	removeDuplicate(str, t);
	
	cout<<"N value : "<<t<<endl;
	
	int y = sizeof(chr)/sizeof(chr[0]);
	
	removeDuplicate(chr, y);
	
	cout<<"N value : "<<y<<endl;
	
	return 0;
}
