#include<iostream>
using namespace  std;
#define queue_size 10	
struct queue {
	int data[queue_size];
	int front, rear;
};
void enqueue(queue *p1) {
	int item;
	if (p1->rear == queue_size - 1) {
		cout << "\nQueue is full \n\n";
		return;
	}
	p1->rear++;
	cout << "\nEnter the item : ";
	cin >> item;
	p1->data[p1->rear] = item;
	cout << "Successed Enqueue Operation\n\n";
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
void dis_primary(queue *p3) {
	if (p3->rear == p3->front) {
		cout << "\nQueue is Empty\n\n";
		return;
	}
	cout << endl;
	for (int i = p3->front+1;i <= p3->rear;i++)
	{
		int item = p3->data[i],count=0;
		for (int j = 1; j <=item ; j++) 
		{
			if(item % j == 0)
				count++;
		}
		if (count <= 2)
		{
			cout << "\t |------|" << endl;
			cout << "\t |  " << item << "\t|" << endl;
		}
	}
	cout << endl;
}
void dis_SecOddN(queue *p3) {
	int count = 0;
	if (p3->rear == p3->front) {
		cout << "\nQueue is Empty\n\n";
		return;
	}
	cout << endl;
	for (int i = p3->front + 1; i <= p3->rear; i++)
	{
		if (p3->data[i] % 2 != 0)
			count++;
		if (count == 2) {
			cout << " Second odd number is : " << p3->data[i];
			break;
		}
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
		cout << "1:Enqueue  2:Dequeue  3:Display  4:dis_primary  5:dis_SecOddN  6:Exit\n ";
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
		case 4: dis_primary(&q);
			break;
		case 5: dis_SecOddN(&q);
			break;
		case 6: cout << "\n End of program\n\n";
			break;
		default: cout << "\n Wrong choice \n\n";
			break;
		}
	} while (c != 6);
	return 0;
}
