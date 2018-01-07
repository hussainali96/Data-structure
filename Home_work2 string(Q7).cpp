#include<iostream>
#include<string>
using namespace std;
void main()
{
	string str;
	while (str !=" ") 
	{
		cout << "Enter the text : ";
		getline(cin, str);
		if (str.empty())
			return;
		else 
			cout <<"Print the text : "<< str<<endl;
		
		}
	cout<< endl;
}
