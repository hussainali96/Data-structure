#include<iostream>
using namespace std;
#define stack_size 10
struct stack
{
	char data[stack_size];
	int top;
};
void push(stack *p1) {
	char item;
	if (p1->top == stack_size - 1) {
		cout << "\nstack is full\n\n ";
		return;
	}
	p1->top++;
	cout << "\nEnter new item : ";
	cin >> item;
	p1->data[p1->top] = item;
	cout << " Successed push opreation \n\n";
}
void Push(stack *p1,char p) {
	if (p1->top == stack_size - 1) {
		cout << "\nstack is full\n\n ";
		return;
	}
	p1->top++;
	p1->data[p1->top] = p;
}
void pop(stack *p2) {
	char item;
	if (p2->top == -1) {
		cout << "\nstack is empty\n\n ";
		return;
	}
	item = p2->data[p2->top];
	p2->data[p2->top] = NULL;
	cout << "\n " << item << "\n";
	cout << " Successed push opreation \n\n";
	p2->top--;

}
void display(stack *p3,stack *p4) {
	int i;
	if (p3->top == -1) {
		cout << "\nStack is empty\n\n";
		return;
	}
	cout <<"\nStack s1 :"<< endl;
	for (i = p3->top; i >= 0; i--) {
		cout << p3->data[i] << endl;
	}
	cout << " Stack s2 :" << endl;
	for (i = p4->top; i >= 0; i--) {
		cout << p4->data[i] << endl;
	}
	cout << endl;
}
void transfer_cap(stack *p3 , stack *p4) {
	if (p3->top == -1) {
		cout << "\nStack is empty\n\n";
		return;
	}
	cout << endl;
	int i, j = 0;
	for (i = p3->top; i>= 0; i--) {
		if (int(p3->data[i]) >= 65 && int(p3->data[i] <= 90)) {
		char p = p3->data[i];
			Push(p4,p);
			p3->data[i] = NULL;
			j++;
		}
	}
	int swap,w=0;
	for (int i = 0; i <= p3->top; i++) {
		for (int j = i+1; j <= p3->top; j++) {
			if (p3->data[i] == NULL && p3->data[j] != NULL) {
				swap = p3->data[i];
				p3->data[i] = p3->data[j];
				p3->data[j] = swap;
			}
		}
		if (p3->data[i] == NULL) w++;
	}
	p3->top -= w;
	if (j > 0)cout << " Successed  transfer capital letters to another stack \n\n";
	else cout << " Not found capital letters \n\n";
	cout << endl;
}
void Ascending(stack *p3, stack *p4) {
	int i, j;
	char swap, Swap;
	if (p3->top == -1) {
		cout << "\nStack is empty\n\n";
		return;
	}
	for (i = p3->top; i >= 0; i--) {
		for (j = p3->top; j >= 0; j--) {
			if (int(p3->data[i]) >int(p3->data[j])) {
				swap = p3->data[i];
				p3->data[i] = p3->data[j];
				p3->data[j] = swap;
			}
		}
	}
	for (i = p4->top; i >= 0; i--) {
		for (j = p4->top; j >=0; j--) {
			if (int(p4->data[i]) > int(p4->data[j])) {
				Swap = p4->data[i];
				p4->data[i] = p4->data[j];
				p4->data[j] = Swap;
			}
		}
	}
	cout << " Successed Ascending order\n\n";
}
void main() {
	stack s1,s2;
	s1.top = -1;
	s2.top = -1;
	int c;
	do {
		cout << "1:push   2:pop    3:display   4: transfer_cap  5:Ascending   6:exit\n";
		cout << " choice: ";
		cin >> c;
		switch (c) {
		case 1:push(&s1);
			break;
		case 2:pop(&s1);
			break;
		case 3:display(&s1,&s2);
			break;
		case 4: transfer_cap(&s1, &s2);
			break;
		case 5:Ascending(&s1, &s2);
			break;
		case 6:cout << "\nEnd of program" << endl << endl;
			break;
		default:cout << "\nWrong choice" << endl << endl;
			break;
		}

	} while (c != 6);
}
