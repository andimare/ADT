#include <iostream>
#include <string>
using namespace std;
class Temperature {
	private:
		double high_temp, low_temp;
	public:
		Temperature();
		Temperature(double, double);
		double getLowTemp();
		double getHighTemp();
		void updateTemp(double);
};

Temperature average(Temperature[], int );

Temperature::Temperature(double high_temp, double low_temp ){
	this->low_temp = low_temp;
	this->high_temp = high_temp;
}

Temperature::Temperature(){
	this->low_temp = 0.0;
	this->high_temp = 0.0;
}
		
void Temperature :: updateTemp(double temp){
	
	if(temp > this->high_temp) {
		this->high_temp = temp;
	}
	else if(temp < this->low_temp || this->low_temp == 0.0){
		this->low_temp = temp;
	}
}
		
double Temperature :: getLowTemp() {
	return this->low_temp;
}

double Temperature :: getHighTemp() {
	return this->high_temp;
}


// This is a generica function but obly for float numbers (only for now)
void enterValue(string str, Temperature &tmp){
	double dd;
	
	cout<<str<<" : ";
	cin>>dd;
	
	tmp.updateTemp(dd);
	
}

void displayTempLimits(Temperature &tmp) {
	
	cout<<"The highest temperature is : "<<tmp.getHighTemp()<<endl;
	cout<<"The lowest temperature is : "<<tmp.getLowTemp()<<endl;
	
}

int main() {
	Temperature tmp1(0,0);
	
	enterValue("Enter recorded temperature", tmp1);
	enterValue("Enter recorded temperature", tmp1);
	enterValue("Enter recorded temperature", tmp1);
	enterValue("Enter recorded temperature", tmp1);
	
	displayTempLimits(tmp1);

	int n = 6;
	Temperature tmp2[n];
	
	for(int i = 0; i < n; i++){
		tmp2[i].updateTemp(87 / (i +1));
		tmp2[i].updateTemp(0.87 / (i +1));
	}
	R
	Temperature mean_temp = average(tmp2, n);
	
	cout<<endl;
	cout<<"This is the average temperatures in the recorde"<<endl;
	displayTempLimits(mean_temp);

	return 0;
}

Temperature average(Temperature a[], int n) {
	double mean_on_high_temps = 0.0, mean_on_low_temps = 0.0;
	
	// Get the average of the high temperature records
	for(int i = 1; i <= n; i++) {
		mean_on_high_temps = (mean_on_high_temps * (i - 1) + a[i-1].getHighTemp())/i;
	}
	
	// Get the average of the low temperature records
	for(int i = 1; i <= n; i++) {
		mean_on_low_temps = (mean_on_low_temps * (i - 1) + a[i].getLowTemp())/i;
	}
	
	Temperature ave_Temp(mean_on_high_temps, mean_on_low_temps);
	
	return ave_Temp;
}
