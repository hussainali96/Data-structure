#include<iostream>
#include<cstring>
using namespace std;

void find(char *p, char chr) {
	char chrb = 'B';
	while (*p != NULL) {
		if (*p == chr) {
			*p = chrb;
		}
			cout << *p;
			p++;
	}
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
	find(str, chr);
	cout << endl;
    return 0;
}
