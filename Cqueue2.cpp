// Cqueue2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace  std;
#define size 8

struct stack {
	int data[size];
	int top;
};
struct queue {
	int data[size];
	int front, rear;
};
struct Cqueue {
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
void enqueue(queue *p1,int item) {
	if (p1->rear == size - 1) {
		cout << "\nQueue is full \n\n";
		return;
	}
	p1->rear++;
	p1->data[p1->rear] = item;
}
void dequeue(queue *p2) {
	int item;
	if (p2->rear == p2->front) {
		cout << "\nQueue is Empty\n";
		return;
	}
	p2->front++;
	item = p2->data[p2->front];
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
void cEnqueue(Cqueue *p1) {
	int item;
		if ((p1->rear == size - 1 && p1->front == 0) || (p1->front == p1->rear + 1)) {
			cout << "\nCircular Queue is full \n\n";
			return;
		}
		if (p1->rear == size - 1 && p1->front != 0)
			p1->rear = -1;
		p1->rear++;
		cout << " Enter the item : ";
		cin >> item;
		p1->data[p1->rear] = item;
	cout << "Successed Enqueue Operation\n\n";
	if (p1->front == -1)
		p1->front = 0;
}
int cDequeue(Cqueue *p2) {
	int item;
	if (p2->rear == -1 && p2->front == -1) {
		cout << "\nCircular Queue is empty \n\n";
		return 0;
	}
	item = p2->data[p2->front];
	return item;
	p2->front++;
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
		while (i <= size - 1)
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
void develop(Cqueue *p1, queue *p2, stack *p3) {
	if (p1->rear == -1 && p1->front == -1) {
		cout << "\nCircular Queue is empty \n\n";
		return;
	}
	int i = p1->front;
	if (p1->front <= p1->rear)
	{
		while (i <= p1->rear)
		{
			if (p1->data[i] % 2 == 0)
				push(p3, p1->data[i]);
			if (p1->data[i] % 2 != 0)
				enqueue(p2, p1->data[i]);
			i++;
		}
	}
	else
	{
		while (i <= size - 1)
		{
			if (p1->data[i] % 2 == 0)
				push(p3, p1->data[i]);
			if (p1->data[i] % 2 != 0)
				enqueue(p2, p1->data[i]);
			i++;
		}
		i = 0;
		while (i <= p1->rear)
		{
			if (p1->data[i]%2 == 0)
				push(p3, p1->data[i]);
			if (p1->data[i]%2 != 0)
				enqueue(p2, p1->data[i]);
			i++;
		}
	}
	cout << "\nSuccessed develop operation\n\n";
}
void main()
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
		cout << "1:cEnqueue  2:cDequeue  3:display_Cqueue 4:develop 5:pop_stack 6:dis_stack 7:dequeue 8:dis_qaueue  9:Exit\n ";
		cout << "choice : ";
		cin >> c;
		switch (c)
		{
		case 1: cEnqueue(&cq);
			break;
		case 2: cDequeue(&cq);
			break;
		case 3: display_Cqueue(&cq);
			break;
		case 4: develop(&cq, &q, &s);
			break;
		case 5:pop(&s);
			break;
		case 6:display_stack(&s);
			break;
		case 7:dequeue(&q);
			break;
		case 8:display_queue(&q);
			break;
		case 9: cout << "\n End of program\n\n";
			break;
		default: cout << "\n Wrong choice \n\n";
			break;
		}
	} while (c != 9);
}

