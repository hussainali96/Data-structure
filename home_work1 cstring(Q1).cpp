#include<iostream>
#include<cstring>
using namespace std;
int find(char *p, char chr) {
	int count = 0;
	while (*p != NULL) {
		if (*p == chr) {
			count++;
		}
		p++;
	}
	return count;
}
int main()
{
	char str[100];
	cout << " Enter the string : ";
	cin.getline(str, 100);
	char chr;
	cout << " chr : ";
	cin >> chr;
	cout << endl;
	cout << " char repet : " << find(str, chr);
	cout << endl;
    return 0;
}
