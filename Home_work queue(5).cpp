#include<iostream>
using namespace  std;
#define size 10
struct stack {
	int data[size];
	int top;
};
struct queue {
	int data[size];
	int front, rear;
};
void push(stack *p1,int item) {
	if (p1->top == size - 1) {
		cout << "\nstack is full\n\n ";
		return;
	}
	p1->top++;
	p1->data[p1->top] = item;
}
void pop(stack *p2) {
	int item;
	if (p2->top == -1) {
		cout << " stack is empty\n ";
		return;
	}
	item = p2->data[p2->top];
	p2->data[p2->top] = NULL;
	cout << item << endl;
	cout << " Successed pop opreation \n\n";
	p2->top--;

}
void display_stack(stack *p3) {
	int i;
	if (p3->top == -1) {
		cout << "\nStack is empty\n\n";
		return;
	}
	cout << endl;
	for (i = p3->top; i >= 0; i--) {
		cout << "\t |------|" << endl;
		cout << "\t |  " << p3->data[i] << "\t|" << endl;
	}
	cout << endl;
}
void enqueue(queue *p1) {
	int item;
	if (p1->rear ==size - 1) {
		cout << "\nQueue is full \n\n";
		return;
	}
	p1->rear++;
	cout << "\nEnter the item : ";
	cin >> item;
	p1->data[p1->rear] = item;
	cout << "Successed Enqueue Operation\n\n";
}
void dequeue(queue *p2,stack *p3) {
	int item;
		if (p2->rear == p2->front) {
			cout << "\nQueue is Empty\n";
			return;
		}
		p2->front++;
		item = p2->data[p2->front];
		push(p3, item);
		p2->data[p2->front] = NULL;
		cout << "\n" << item << "\n";
	cout << "Successed Dequeue Operation\n\n";
}
void display_queue(queue *p3) {
	if (p3->rear == p3->front) {
		cout << "\nQueue is Empty\n\n";
		return;
	}
	cout << endl;
	for (int i = p3->front + 1; i <= p3->rear; i++) {
		cout << "\t |------|" << endl;
		cout << "\t |  " << p3->data[i] << "\t|" << endl;
	}
	cout << endl;
}
void main()
{
	queue q;
	stack s;
	s.top = -1;
	q.front = -1;
	q.rear = -1;
	int c;
	do {
		cout << "1:Enqueue  2:Dequeue  3:Display  4:pop stack 5:display_stack 6:Exit\n ";
		cout << "choice : ";
		cin >> c;
		switch (c)
		{
		case 1: enqueue(&q);
			break;
		case 2: dequeue(&q,&s);
			break;
		case 3: display_queue(&q);
			break;
		case 4: pop(&s);
			break;
		case 5: display_stack(&s);
			break;
		case 6: cout << "\n End of program\n\n";
			break;
		default: cout << "\n Wrong choice \n\n";
			break;
		}
	} while (c != 6);
}
