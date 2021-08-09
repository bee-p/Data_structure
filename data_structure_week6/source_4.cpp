#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
};

// 헤드포인터를 전역변수로 설정
// 함수에 인자를 넘기지 않아도 되도록 함
Node* Head;

void insert_node_A(Node* pre, Node* new_node) {	// 삽입 함수(A방식-선행노드 이용)
	if (Head == NULL) {		// 공백 리스트인 경우
		Head = new_node;
	}
	else if (pre == NULL) {		// pre가 NULL이면 첫번째 노드로 삽입
		new_node->link = Head;
		Head = new_node;
	}
	else {		// pre 다음에 삽입
		new_node->link = pre->link;
		pre->link = new_node;
	}

}

void insert_node_at_rear(Node* new_node) {	// 삽입함수(B방식 - 선행노드를 모르는 경우)
	// 리스트 마지막에 노드 삽입함
	if (Head == NULL)	// 공백 리스트인 경우
		Head = new_node;
	else {
		Node* list = Head;

		// 리스트가 마지막 노드를 가리킬 때까지 이동
		while (list->link != NULL)
			list = list->link;

		list->link = new_node;

	}
}

void insert_node_at_front(Node* new_node) {	// 삽입함수(C방식 - 리스트 처음에 노드 삽입)
	new_node->link = Head;
	Head = new_node;
}

void delete_node(int x) {	// 삭제 함수(B방식 - key(x)값을 갖는 노드를 찾아 삭제함)
	Node* pre = Head;

	if (Head == NULL) return;	// 삭제할 것이 없음
	else if (Head->data == x)	// 찾는 노드(삭제 노드)가 첫 노드일 경우
	{
		Head = Head->link;
		return;
	}
	else	// 나머지 경우
	{
		while (pre->link != NULL)	// 찾는 노드의 앞 노드를 찾는 것, pre가 마지막 노드면 탈출
		{
			if (pre->link->data == x)
			{
				pre->link = pre->link->link;
				return;
			}
			pre = pre->link;
		}
	}
}

void reverse_list() {	// 리스트 역순 연산
	Node *p, *q, *r;	

	p = Head;
	q = r = NULL;
	while (p != NULL) {
		r = q;		// r -> q -> p 순으로 따라감
		q = p;
		p = p->link;	// p가 먼저 앞서감
		q->link = r;	// q의 링크 방향을 역순으로 바꿈
	}
	Head = q;
}

void print_list() {		// 연결리스트 출력 함수
	for (Node* ptr = Head; ptr != NULL; ptr = ptr->link)	// for문안에 선언까지 하는게 c++스타일..?
		if (ptr->link == NULL) cout << ptr->data << endl;
		else cout << ptr->data << "-->";
}

void main() 
{
	Head = NULL;

	// 데이터 입력 개수 입력 받기
	int data_number;
	cout << "전체 입력 데이터의 개수는? : ";
	cin >> data_number;
	
	for (int i = 0; i < data_number; i++)	// XX개의 데이터 입력
	{	
		// 새로운 데이터를 차례로 입력을 받음
		int i_data;
		cout << "새로운 값을 입력하시오(#" << i+1 << ") : ";
		cin >> i_data;

		// 새로운 노드를 생성하여 내용을 수정
		Node* new_node = new Node;
		new_node->data = i_data;
		new_node->link = NULL;

		// 전체 연결리스트에 추가/삽입
		// insert_node_A(NULL, new_node);
		// insert_node_at_rear(new_node);
		insert_node_at_front(new_node);
	}

	// 확인용으로 출력
	cout << "\n구성된 연결 리스트는 : ";
	print_list();

	/*
	// 연결리스트에서 노드 삭제 반복
	for (int i = 0; i < 3; i++)
	{
		// 삭제할 노드의 값 입력 받기
		int del_data;
		cout << "\n삭제할 노드의 값 : ";
		cin >> del_data;

		// 해당 값을 가진 노드 삭제
		delete_node(del_data);

		// 노드 삭제 후 연결 리스트 출력
		cout << "\n삭제 후 연결 리스트는 : ";
		print_list();
	}
	*/


	// 리스트 역순 연산 테스트
	reverse_list();
	print_list();
}