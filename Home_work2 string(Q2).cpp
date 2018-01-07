#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << " Enter the text : ";
	string str;
	getline ( cin, str);
	int len = str.size();
	int count = 0;
	for (int i = 0; i < len; i++) {
		if ( str[i] == ' '||i==len-1) {
			count++;
		}
	}
	cout << " The number words of text is : " << count << endl;
    return 0;
}
