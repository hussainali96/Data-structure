#include<iostream>
using namespace std;
#include<string>
#include<cstring>
struct  car      //hussain ali
{
	string name;
	string color;
	int model;
	int price;
}mycar[5];
void ColorRed(car mycar[]){
	for (int i = 0; i < 5; i++) {
		if (mycar[i].color == "RED" || mycar[i].color == "Red" || mycar[i].color == "red") {
			cout << mycar[i].name << "  " << mycar[i].model << "  " << mycar[i].price <<"$"<< endl;

		}
	}	  
}
void lenght(car mycar[]) {
	for (int i = 0; i < 5; i++) {
		int len = mycar[i].name.size();
		if (len > 5) 
			cout << mycar[i].name << "  ";
	}
}
void main() {
	/*car mycar[5] = {
		{ "MBMW","Black",2012,7000 },
		{ "ACCENT","White",2015,10000 },
		{ "KIA","Red",2016,15000 },
		{ "MAZDA","Blue",1990,5000 },
		{ "LAMBORGHINI","White",2016,50000 }
	};*/
	for (int i = 0; i < 5; i++) {
	cout << " Enter the information car " << i+1 << " : " << endl;
	cout << " Name  : ";
	cin.ignore();
	fflush(stdin);
	getline(cin, mycar[i].name);
	cout << " Color : ";
	cin.ignore();
	fflush(stdin);
	getline(cin, mycar[i].color);
	cout << " Model : ";
	cin >> mycar[i].model;
	cout << " Price : ";
	cin>> mycar[i].price;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	}
	cout << "Sum of cars that model's more than 2000  = ";
	int sum_cars = 0;
	for (int i = 0; i < 5; i++) {
		if (mycar[i].model > 2000) {
			sum_cars++;
		}
	}
	cout  << sum_cars << endl;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl << endl;
	cout << "Names of cars that prices less than 15000$ : ";
	for (int i = 0; i < 5; i++) {
		if (mycar[i].price < 15000) {
			cout << mycar[i].name << "  ";
		}
		
	}cout << endl<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl << endl;
	cout << "Information of cars that color is RED : " << endl;
	 ColorRed( mycar);
	cout << endl<< "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl << endl;
	cout << "Names of cars that named contain character 'M' : ";
	int Sum_cars = 0;
	for (int i = 0; i <5; i++) {
		string str = mycar[i].name;
		int len = str.size();
		for (int j = 0; j < len; j++) {
			if (str[j] =='M'|| str[j] =='m') {
				Sum_cars++;
				cout << mycar[i].name << "\t";
				break;
			}
		}
	}
	cout << endl;
	cout << "Sum of cars that named contain character 'M' : " << Sum_cars;
	cout << endl << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl << endl;
	cout << "Names of cars that name's lenght more than 5 characters : ";
	lenght(mycar);
	cout << endl << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl << endl;
}
