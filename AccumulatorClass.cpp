#include <iostream>
using namespace std;

class accumulator{ 
	private: 
		int total; 
	public: 
		accumulator(int value=0):total(value) {
		
		} 
		
		int getTotal(){
			return total;
		}
		
		void addValue(int value){
			total += value;
		}
		
		accumulator operator +=(const accumulator &obj);
		accumulator operator -=(const accumulator &obj);
		friend accumulator operator +(const accumulator &x, const accumulator &y);
		friend ostream & operator <<(ostream & ostr, const accumulator &obj);
}; 

accumulator accumulator::operator +=(const accumulator &obj){
	this->total += obj.total;
	
	return *this;
}

accumulator accumulator::operator -=(const accumulator &obj){
	this->total *= -1;
	
	return *this;
}

accumulator operator +(const accumulator &x, const accumulator &y){
	accumulator dummy;
	
	dummy.total = x.total + y.total;
	
	return dummy;
}

ostream & operator <<(ostream & ostr, const accumulator &obj){
	ostr<<"The value is : "<<obj.total<<endl;
	
	return ostr;
}

int main(){
	accumulator a(5), b(4), c(9);
	
	a += b;
	cout<<a<<endl;
	
	a -= a;
	cout<<a<<endl;
	
	accumulator sum = b + c;
	cout<<sum<<endl;
	
	return 0;
}
