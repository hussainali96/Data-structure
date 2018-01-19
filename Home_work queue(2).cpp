#include<iostream>
using namespace  std;
#define queue_size 7	
struct queue {
	int data[queue_size];
	int front, rear;
};
void enqueue(queue *p1) {
	int item;
	if (p1->rear == queue_size - 1) {
		cout << "\nQueue is full \n\n" ;
		return;
	}
	p1->rear++;
	cout << "\nEnter the item : ";
	cin >> item;
	p1->data[p1->rear] = item;
	cout << "Successed Enqueue Operation\n\n";
}
void dequeue(queue *p2) {
	int item, sum=0,N;
	cout << " Enter number if dequeue : ";
	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (p2->rear == p2->front) {
			cout << "\nQueue is Empty\n";
		}
		p2->front++;
		item = p2->data[p2->front];
		if (item % 2 == 0)
			sum += item;
		p2->data[p2->front] = NULL;
	}
	cout << " Sum of even number : " << sum << endl;
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
