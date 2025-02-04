#include <iostream>
using namespace std;

class modClass{
	private:
		int val;
	public:
		modClass(int v = 0);
		
	friend modClass operator +(const modClass &x, const modClass &y);
	friend modClass operator *(const modClass &x, const modClass &y);
	friend  bool operator ==(const modClass &x, const modClass &y);
	friend bool operator <(const modClass &x, const modClass &y);
	friend ostream & operator <<(ostream & ostr, const modClass &obj);
};

modClass::modClass(int v){
	this->val = v % 7;
}

modClass operator +(const modClass &x, const modClass &y){
	modClass dummy;
	
	dummy.val = (x.val + y.val) % 7;
	
	return dummy;
}

modClass operator *(const modClass &x, const modClass &y){
	modClass dummy;
	
	dummy.val = (x.val * y.val) % 7;
	
	return dummy;
}

bool operator ==(const modClass &x, const modClass &y){
	if(x.val == y.val) return true;
	
	return false;
}

bool operator <(const modClass &x, const modClass &y){
	if(x.val < y.val) return true;
	
	return false;
}

ostream & operator <<(ostream & ostr, const modClass &obj){
	ostr<<"The value is : "<<obj.val<<endl;
	
	return ostr;
}

int main(){
	modClass a(6), b(5);
	
	modClass c = a + b;
	cout<<c<<endl;
	
	c = a * b;
	cout<<c<<endl;
	
	if(!(a == b)) cout<<"The objects are not the same."<<endl;
	if(!(a < b)) cout<<"A is not less than B"<<endl;
	
	return 0;
}
