// Cqueue 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace  std;
#define size 12
#define size1 6
#define size2 6
struct stack {
	int data[size2];
	int top;
};
struct queue {
	int data[size2];
	int front,rear;
};
struct Cqueue {
	int data[size];
	int front, rear;
};
void push(stack *p1) {
	int item;
	if (p1->top == size1 - 1) {
		cout << "\nstack is full\n\n ";
		return;
	}
	p1->top++;
	cout << "\nEnter new item : ";
	cin >> item;
	p1->data[p1->top] = item;
	cout << " Successed push opreation \n\n";
}
int pop(stack *p2) {
	int item;
	if (p2->top == -1) {
		cout << "\nstack is empty\n\n ";
		return 0;
	}
	item = p2->data[p2->top];
	p2->data[p2->top] = 0;
	p2->top--;
	return item;

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
	if (p1->rear ==size2 - 1) {
		cout << "\nQueue is full \n\n";
		return;
	}
	p1->rear++;
	cout << "\nEnter the item : ";
	cin >> item;
	p1->data[p1->rear] = item;
	cout << "Successed Enqueue Operation\n\n";
}
int dequeue(queue *p2) {
	int item;
		if (p2->rear == p2->front) {
			cout << "\nQueue is Empty\n";
			return 0;
		}
		p2->front++;
		item = p2->data[p2->front];
		p2->data[p2->front] = NULL;
		return item;
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
void cEnqueue(Cqueue *p1,queue *p2,stack *p3) {
	int item;
	for (int i = p3->top; i >= 0; i--) {
		if ((p1->rear == size - 1 && p1->front == 0) || (p1->front == p1->rear + 1)) {
			cout << "\nCircular Queue is full \n\n";
			return;
		}
		if (p1->rear == size - 1 && p1->front != 0)
			p1->rear = -1;
		p1->rear++;
		p1->data[p1->rear] = pop(p3);
		if (p1->front == -1)
			p1->front = 0;
	}
	for (int i = p2->front + 1; i <= p2->rear; i++) {
		if ((p1->rear == size - 1 && p1->front == 0) || (p1->front == p1->rear + 1)) {
			cout << "\nCircular Queue is full \n\n";
			return;
		}
		if (p1->rear == size - 1 && p1->front != 0)
			p1->rear = -1;
		p1->rear++;
		p1->data[p1->rear] = dequeue(p2);
		if (p1->front == -1)
			p1->front = 0;
	}
	cout << "Successed Enqueue Operation\n\n";
}
void cDequeue(Cqueue *p2) {
	int item;
	if (p2->rear == -1 && p2->front == -1) {
		cout << "\nCircular Queue is empty \n\n";
		return;
	}
	
		item = p2->data[p2->front];
		p2->front++;
		cout << "\n" << item << "\n";
	cout << "Successed Dequeue Operation\n\n";

	if (p2->front - 1 == p2->rear)
		p2->front = p2->rear = -1;
	else if (p2->front == size)
		p2->front = 0;
}
void display_Cqueue(Cqueue *p3) {
	if (p3->rear == -1 && p3->front == -1) {
		cout << "\nCircular Queue is empty \n\n";
		return;
	}
	int i = p3->front;
	if (p3->front <= p3->rear)
	{
		while (i <= p3->rear)
		{
			cout << "\t |------|" << endl;
			cout << "\t |  " << p3->data[i] << "\t|" << endl;
			i++;
		}
	}
	else
	{
		while (i <= size-1)
		{
			cout << "\t |------|" << endl;
			cout << "\t |  " << p3->data[i] << "\t|" << endl;
			i++;
		}
		i = 0;
		while (i <= p3->rear)
		{
			cout << "\t |------|" << endl;
			cout << "\t |  " << p3->data[i] << "\t|" << endl;
			i++;
		}
	}
	cout << endl;
}
int main()
{
	Cqueue cq;
	queue q;
	stack s;
	s.top = -1;
	q.rear = q.front = -1;
	cq.front = -1;
	cq.rear = -1;
	int c;
	do {
		cout << "1:push_stack 2:dis_stack 3:enq_queue 4:dis_queue 5:cEnqueue  6:cDequeue  7:display_Cqueue  8:Exit\n ";
		cout << "choice : ";
		cin >> c;
		switch (c)
		{
		case 1: push(&s);
			break;
		case 2: display_stack(&s);
			break;
		case 3: enqueue(&q);
			break;
		case 4: display_queue(&q);
			break;
		case 5: cEnqueue(&cq,&q,&s);
			break;
		case 6: cDequeue(&cq);
			break;
		case 7: display_Cqueue(&cq);
			break;
		case 8: cout << "\n End of program\n\n";
			break;
		default: cout << "\n Wrong choice \n\n";
			break;
		}
	} while (c != 8);
	return 0;
}
