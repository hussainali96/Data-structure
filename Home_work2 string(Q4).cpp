#include<iostream>
#include<string>
using namespace std;
void freq_char(string str) {
	int len = str.size();
	int count1, count2 =0;
	char chr;
	for (int i = 0; i < len; i++) {
		 count1 = 0;
		 for (int j = 0; j < len; j++) {
			 if (i != j)
				 if (str[i] == str[j])
					 count1++;
		 }
		 if (count1 > count2) {
			 count2 = count1;
			 chr = str[i];
		 }
	}
	if (count2 == 0) {
		cout << " Doesn't  the most frequent character in the text"<<endl;
	}
	else {
		cout << " The most frequent charcter is : " << chr << endl;
	}
}
int main()
{
	string str;
	cout << " Enter the text : ";
	getline(cin, str);
	freq_char(str);
    return 0;
}
