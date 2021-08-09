#include <iostream>
using namespace std;

class CNode {
public:
	int data;
	CNode* link;
};

// 헤드포인터를 전역변수로 설정
// 함수에 인자를 넘기지 않아도 되도록 함
CNode* Head = NULL;

void insert_node_at_rear(CNode* new_node) {	// 리스트 마지막에 노드 삽입함
	if (Head == NULL) {		// 공백 리스트인 경우
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;	// 새로운 노드가 현재 마지막 노드 뒤에 붙음(이제 new_node가 마지막 노드)
		Head = new_node;	// Head는 항상 마지막 노드를 가리킴(new_node로 바꿔줌)
	}
}

void insert_node_at_front(CNode* new_node) {	// 리스트 처음에 노드 삽입
	if (Head == NULL) {		// 공백 리스트인 경우
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;	// 새로운 노드가 첫 번째(마지막 노드 다음)에 붙음
	}
}

void delete_node(int key) {	// key값을 갖는 노드를 찾아 삭제함
	if (Head == NULL) return;	// 빈 리스트
	// 노드가 1개이면서 그 값이 key와 일치할 경우
	else if (Head->link == Head && Head->data == key)	Head = NULL;
	else	// 일반적인 경우
	{
		CNode* pre = Head;
		do
		{
			if (pre->link->data == key) {
				CNode* removed = pre->link;
				pre->link = removed->link;	// pre->link = pre->link->link;
				if (Head == removed) Head = pre;	// 헤드포인터 pre로 재설정
				return;
			}
			pre = pre->link;
		} while (pre != Head);
	}
}

void print_list() {		// 전체 목록 출력
	cout << "\n원형연결리스트 결과" << endl;

	if (Head == NULL) return;
	else
	{
		CNode* ptr = Head;

		do
		{
			cout << ptr->link->data << endl;	// 첫번째 노드부터 출력
			ptr = ptr->link;
		} while (ptr != Head);
	}
}

void main()
{
	// 데이터 입력 개수 입력 받기
	int num;
	cout << "전체 입력 데이터의 개수는? : ";
	cin >> num;

	for (int i = 0; i < num; i++)	// XX개의 데이터 입력
	{	// 입력값을 받아 연결리스트에 추가
		
		CNode* new_node = new CNode;
		int i_data;
		
		cout << "새로운 값을 입력하시오(#" << i + 1 << ") : ";
		cin >> i_data;
		new_node->data = i_data;
		new_node->link = NULL;
		
		// 전체 연결리스트에 추가/삽입
		insert_node_at_rear(new_node);
	}

	// 확인용으로 출력
	print_list();

	// 노드 삭제
	int del_data;

	cout << "\n삭제할 값은: ";
	cin >> del_data;

	delete_node(del_data);

	print_list();
}