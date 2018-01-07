#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	cout << " Enter the text : ";
	getline(cin, str);
	int len = str.size();
	cout << " The text is : ";
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'a'&&str[i] <= 'z') {
			str[i] -= 32;
			cout << str[i];
		}
		else {
			cout << str[i];
		}
	}
	cout << endl;
    return 0;
}
