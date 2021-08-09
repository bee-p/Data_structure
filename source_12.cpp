/*
#include <iostream>
using namespace std;

// 큐의 기본 함수 구현, 몇가지 간이 테스트
#define element int		// element는 int형
#define MAX_SIZE 100

element Queue[MAX_SIZE];
// int top = -1;	// 스텟 포인터 초기화 sp = -1;
int front = -1;
int rear = -1;

bool is_queue_empty() {
	return (front == rear);		// * 축약 *
}

bool is_queue_full() {
	return (rear == MAX_SIZE - 1);
}

void enQueue(element data) {	// 삽입
	if (is_queue_full()) {
		cout << "ERROR: Queue Full" << endl;
		return;
	}
	else {
		Queue[++rear] = data;	// rear++; Queue[rear] = data;
	}
}

element deQueue() {				// 삭제
	if (is_queue_empty()) {
		cout << "ERROR: Queue Empty" << endl;
		return -1;	// exit();
	}
	else {
		return Queue[++front];
	}
}

element peek() {
	if (is_queue_empty()) {
		cout << "ERROR: Queue Empty" << endl;
		return -1;
	}
	else {
		return Queue[front + 1];	// !! front를 바꾸면 안된다 !!
	}
}

void print_queue() {
	cout << "QUEUE STATUS (front = " << front << ", rear = " << rear << ")" << endl;

	if (is_queue_empty()) return;
	else {
		for (int i = front + 1; i <= rear; i++)
			cout << Queue[i] << " ";
	}
	cout << endl;
}

void main()
{
	enQueue(10);
	enQueue(20);
	enQueue(30);
	deQueue();

	print_queue();
	
	enQueue(40);
	enQueue(50);
	deQueue();
	enQueue(60);

	print_queue();
}
*/