#include<iostream>
#include<string>
using namespace std;
int Compare1(string str1, string str2) {
	if (str1 == str2) return 0;
	if (str1 > str2) return 1;
	if (str1 < str2) return -1;
}
int Compare2(string *str1, string *str2) {
	if (*str1 == *str2) return 0;
	if (*str1 > *str2) return 1;
	if (*str1 < *str2) return -1;
}
int main()
{
	string str1, str2;
	cout << " Enter the text 1 : ";
	getline(cin, str1);
	cout << " Enter the text 2 : ";
	getline(cin, str2);
	cout << " Compare without pointer tex1 with text2 is : " << Compare1(str1, str2) << endl;
	cout << " Compare with pointer tex1 with text2 is    : " << Compare2(&str1, &str2) << endl;
	cout << endl;
    return 0;
}
