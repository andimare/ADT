
template <class Type, class  Type1>
class accumulator{ 
	private: 
		Type total; 
	public: 
		accumulator(Type value = 0):total(value) {
		
		} 
		
		Type getTotal(){
			return total;
		}
		
		void addValue(Type value){
			total += value;
		}
		
		accumulator operator +=(const accumulator &obj);
		accumulator operator -=(const accumulator &obj);
		friend accumulator operator +(const accumulator &x, const accumulator &y);
		friend ostream & operator <<(ostream & ostr, const accumulator &obj);
};

template <class Type1>
Type1 accumulator <Type1>::operator +=(const accumulator &obj){
	this->total += obj.total;
	
	return *this;
}

template <class Type1>
Type1 accumulator <Type1>::operator -=(const accumulator &obj){
	this->total *= -1;
	
	return *this;
}

template <class Type1>
Type1 operator +(const Type1 &x, const Type1 &y){
	accumulator dummy;
	
	dummy.total = x.total + y.total;
	
	return dummy;
}

template <class Type1>
ostream & operator <<(ostream & ostr, const accumulator &obj){
	ostr<<"The value is : "<<obj.total<<endl;
	
	return ostr;
}
