#include <iostream>
#include <vector>
using namespace std;

struct Velist{
	public:
		static void example(vector<int> list1) {
		/* This function prints out the contents of list[].*/
 	
 	
		    //Display
		    for(int elem : list1){
		    	std::cout<<elem<<" ";
			}
		 }
};

int main(){
	vector<int> list1;
	int i = 8;
	
	while(i > 0){
    	list1.push_back(i);
    	--i;
	}
    
    Velist lst;
    lst.example(list1);
    
	return 0;
}
