#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

int main(){
	string str;
	
	cout<<"Enter the string (char array) : ";
	cin>>str;
	
	char ch[str.length()];
	
	strncpy(ch, str.c_str(),str.length());
	
	cout<<endl<<endl;
	
	for(char r : ch ){
		cout<<ch<<" "<<endl;
	}
	
	return 0;
}
