#include <iostream>
using namespace std;

//원형 큐
#define element int		// element는 int형
const int MAX_SIZE = 6;

element CQueue[MAX_SIZE];
int front = 0;
int rear = 0;

bool is_queue_empty() {
	return (front == rear);
}

bool is_queue_full() {
	return (front == (rear + 1) % MAX_SIZE);
}

void enQueue(element data) {	// 삽입
	if (is_queue_full()) {
		cout << "ERROR: CQueue Full" << endl;
		return;
	}
	else {
		// Queue[++rear] = data;
		rear = (rear + 1) % MAX_SIZE;	// *** 중요 ***
		CQueue[rear] = data;
	}
}

element deQueue() {				// 삭제
	if (is_queue_empty()) {
		cout << "ERROR: CQueue Empty" << endl;
		return -1;	// exit();
	}
	else {
		// return Queue[++front];
		front = (front + 1) % MAX_SIZE;
		return CQueue[front];
	}
}

void print_queue() {
	if (front < rear) {
		for (int i = front + 1; i <= rear; i++)
			cout << CQueue[i] << " ";
	}
	else {	// front > rear의 경우 두 차례에 나눠서 출력
		for (int i = front + 1; i < MAX_SIZE; i++)
			cout << CQueue[i] << " ";

		for (int i = 0; i <= rear; i++)
			cout << CQueue[i] << " ";
	}
	cout << endl;
}

void main()
{
	enQueue(10);
	enQueue(20);
	enQueue(30);
	enQueue(40);
	enQueue(50);
	deQueue();
	deQueue();
	enQueue(60);
	enQueue(70);

	print_queue();

	deQueue();
	deQueue();

	print_queue();
}