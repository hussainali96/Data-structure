#include<iostream>
using namespace std;
#define stack_size 4
struct stack
{
	int data[stack_size];
	int top;
};
void push(stack *p1) {
	int item;
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
void pop(stack *p2) {
	int item;
	if (p2->top == -1) {
		cout << "\nstack is empty\n\n ";
		return;
	}
	item = p2->data[p2->top];
	p2->data[p2->top] = 0;
	cout << "\n " << item << "\n";
	cout << " Successed pop opreation \n\n";
	p2->top--;

}
void display(stack *p3) {
	int i;
	if (p3->top == -1) {
		cout << "\nStack is empty\n\n";
		return;
	}
	cout << endl;
	for (i = p3->top; i >= 0; i--) {
		cout << p3->data[i] << endl;
	}
	cout << endl;
}
void display_avg(stack *p4) {
	float avg, sum = 0,count=0;
	if (p4->top == -1) {
		cout << "\nStack is empty\n\n";
		return;
	}
	cout << endl;
	for (int i = p4->top; i >= 0; i--) {
		sum += p4->data[i];
		count++;
	}
	avg = sum / count;
	cout <<" average = "<<avg << endl;
	cout << endl;
}
void display_evenNum(stack *p5) {
	if (p5->top == -1) {
		cout << "\nStack is empty\n\n";
		return;
	}
	cout << endl;
	for (int i = p5->top; i >= 0; i--) {
		if (p5->data[i] % 2 == 0)
			cout << p5->data[i] << endl;

	}
	cout << endl;
}
void display_factOdd(stack *p6) {
	if (p6->top == -1) {
		cout << "\nStack is empty\n\n";
		return;
	}
	cout << endl;
	for (int i = p6->top; i >= 0; i--) {
		float fact = 1, Num;
		if (p6->data[i] % 2 != 0) {
			Num = p6->data[i];
			cout << "" << Num << "! : ";
			for (int j = 1; j <= Num; j++) {
				fact *= j;
			}
			cout << fact << endl;
		}
	}
	cout << endl;
}
void display_dupNum(stack *p7) {
	if (p7->top == -1) {
		cout << "\nStack is empty\n\n";
		return;
	}
	cout << endl;
	for (int i = p7->top; i >= 0; i--) {
		int	w = 0;
		for (int j = p7->top; j >= 0; j--) {
			if (j != i)
				if (p7->data[i] == p7->data[j]) {
					p7->data[j] = NULL;
					w++;
				}
		}
		if (w >0) {
			p7->data[i] = NULL;
		}
	}
		cout << " Successed delete duplicated Numbers \n\n";
}
void main() {
	stack s;
	s.top = -1;
	int c;
	do {
		cout << "1:push 2:pop  3:display 4:display_avg  5:display_evenNum  6:display_factOdd 7:display_dupNum  8:exit\n\n";
		cout << " choice: ";
		cin >> c;
		switch (c) {
		case 1: push(&s);
			break;
		case 2: pop(&s);
			break;
		case 3: display(&s);
			break;
		case 4: display_avg(&s);
			break;
		case 5:display_evenNum(&s);
			break;
		case 6:display_factOdd(&s);
			break;
		case 7:display_dupNum(&s);
			break;
		case 8:cout << "\nEnd of program" << endl << endl;
			break;
		default:cout << "\nWrong choice" << endl << endl;
			break;
		}
	} while (c != 8);
	cout << endl;
}
