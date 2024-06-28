#include <iostream>
#include <list>

int main() {
    std::list<int> list1 = {1, 2, 3};

	//Insertion
	//At index 2
    list1.insert(std::next(list1.begin(), 2), 7);// list1 becomes [ 1, 2, 7, 3]
    
    //Insertion
    //At the back
    list1.push_back(8);// list1 becomes [ 1, 2, 7, 3, 8]
    
    //Deletion
    //At the front
    list1.pop_front();// list1 becomes [ 2, 7, 3, 8]
    
    //Deletion
    //At index 3
    list1.erase(std::next(list1.begin(), 2));// list1 becomes [ 2, 7, 8]
    
    //Display
    for(int elem : list1){
    	std::cout<<elem<<" ";
	}
     return 0;
}
