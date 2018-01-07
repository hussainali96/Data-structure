#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct fullname {
	string first_name;
	string last_name;
};

struct student {
	int id;
	fullname data_name;
	int mark[3];
}stud[3];

void avg_stud(student stud[3]) {
	for (int i = 0; i < 3; i++) {
		float sum = 0, avg;
		cout << "student (" << i+1<< ") : ";
		for (int j = 0; j < 3; j++) {
			sum += stud[i].mark[j];
		}
		avg = sum / 3;
		cout << avg << endl;
	}
}
void main() {
	cout << " Information of students... " << endl;
	for (int i = 0; i < 3; i++) {
		stud[i].id = i + 1;
		cout << "----------------------------" << "\n\n";
		cout << " Student (" << i + 1 << ") :" << endl;
		cout << " First name : ";
		getline(cin, stud[i].data_name.first_name);
		cout << " Last name  : ";
		getline(cin, stud[i].data_name.last_name);
		cout << "\n";
		cout << " Please insert marks student "<<i+1<<" "<<endl; 
		for (int j = 0; j < 3; j++) {
		cout << " Mark "<<j+1<<" : ";
		cin >> stud[i].mark[j];
		cin.ignore();
	}
		cout << "\n";
	}
	cout << " Display All Information:" << endl;
	cout << "----------------------------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << " Student(" << i + 1 << ") : ";
		cout << stud[i].id << " "<< stud[i].data_name.first_name << " " << stud[i].data_name.last_name;
		cout << "\t(";
		for (int j = 0; j < 3; j++) {
			cout  << stud[i].mark[j];
			if(j<2) cout<<", ";
		}
		cout << ")" << endl;
	}
	cout << "Average for each student :" << endl;
	cout << "--------------------------" <<"\n\n";
	avg_stud(stud);
	cout << endl;
	cout << "Names of student who have failed in more than one subject :" << endl;
	cout << "-----------------------------------------------------------" << endl;
	for (int i = 0; i < 3; i++) {
		int count = 0;
		for (int j = 0; j < 3; j++) {
			if (stud[i].mark[j] < 50) count++;
		}
		if (count > 1) {
			cout << stud[i].data_name.first_name << " " << stud[i].data_name.last_name << endl;
		}
	}
	cout << endl;
}
