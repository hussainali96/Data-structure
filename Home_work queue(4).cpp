#include<iostream>
using namespace  std;
#define queue_size 5	
struct queue {
	char data[queue_size];
	int front, rear;
};
void enqueue(queue *p1) {
	char item;
	if (p1->rear == queue_size - 1) {
		cout << "\nQueue is full \n\n";
		return;
	}
	cout << "\nEnter the item : ";
	cin >> item;
	if (item >= 'a'&&item <= 'z')
	{
		p1->rear++;
		p1->data[p1->rear] = item;
		cout << "Successed Enqueue Operation\n\n";
	}
	else {
		cout << "\n The item you enter is not lowerccase\n\n";
	}
}
void dequeue(queue *p2) {
	char item;
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
void display(queue *p3) {
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
int main()
{
	queue q;
	q.front = -1;
	q.rear = -1;
	int c;
	do {
		cout << "1:Enqueue  2:Dequeue  3:Display  4:Exit\n ";
		cout << "choice : ";
		cin >> c;
		switch (c)
		{
		case 1: enqueue(&q);
			break;
		case 2: dequeue(&q);
			break;
		case 3: display(&q);
			break;
		case 4: cout << "\n End of program\n\n";
			break;
		default: cout << "\n Wrong choice \n\n";
			break;
		}
	} while (c != 4);
	return 0;
}
