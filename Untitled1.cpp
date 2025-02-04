#include <iostream>
#include <string>
using namespace std;

int main() {
	string state = "Fert";
	
	try{
		cout<<state++<<endl;
		
//		throw Exception;
	} catch (...) {
		cout<<"Error thrown"<<endl;
	}
	
	return 0;
}
