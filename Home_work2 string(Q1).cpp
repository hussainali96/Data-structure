#include <iostream>
#include<string>
using namespace std;
int occurrence(string str, char chr) {
	int len = str.size();
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == chr)
			count++;
	}
	return count;
}
int main()
{
	string str1, str2, str3;
	char chr;
	cout << " Enter the string 1 : ";
	getline(cin,str1);
	cout << " Enter the string 2 : ";
	getline(cin, str2);
	cout << " The string 1 : "<<str1<<endl;
	cout << " The string 2 : " <<str2 << endl;
	int len1 = str1.size();
	int len2= str2.size();
	cout << " The string 1 : ";
	for (int i = 0; i < len1; i++) {
			cout << str1[i];
	}
	cout << endl;
	cout << " The string 2 : ";
	for (int i = 0; i < len2; i++) {
		cout << str2[i];
	}
	cout << endl;
	cout << " The reverse string 1 : ";
	for (int i = len1; i>=0; i--) {
		cout << str1[i];
	}
	cout << endl;
	str3 = str1 + str2;
	cout << " The string 3 : " << str3 << endl;
	cout << " chr : ";
	cin >> chr;
	cout << endl;
	cout << " Char repeat : " << occurrence(str3, chr);
	cout << endl;
	return 0;
}
