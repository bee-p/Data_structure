#include <iostream>
using namespace std;

// 이중 연결 리스트 (원형리스트 + 헤드노드)

class DNode {	// D-Node : 더블 노드
public:
	int data;
	DNode* llink;
	DNode* rlink;

	DNode() {
		llink = rlink = NULL;
	}
	DNode(int value) {
		data = value;
		llink = rlink = NULL;
	}
};

DNode* Head = NULL;

void insert_node(DNode* new_node)	// 리스트 마지막에 새로운 노드 추가
{
	new_node->rlink = Head;
	new_node->llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;
}

void delete_node(int key)	// 키 값과 동일한 값을 갖는 노드 삭제
{
	for (DNode* list = Head->rlink; list != Head; list = list->rlink) 
	{
		if (list->data == key)
		{	// 각자 링크를 건너뛰게 함
			list->llink->rlink = list->rlink;
			list->rlink->llink = list->llink;
			return;
		}
	}
}

void print_list()
{
	cout << "\n리스트 내용 출력" << endl;

	// Head의 rlink가 첫번째 노드
	// list = list->rlink : 리스트 오른쪽으로 쭉 따라감
	for (DNode* list = Head->rlink; list != Head; list = list->rlink)
	{	
		cout << list->data << endl;
	}

	// 역순 출력
	// for (DNode* list = Head->llink; list != Head; list = list->llink)
}

void main()
{
	// 헤드노드 생성
	Head = new DNode;		// 생성자 함수 DNode() 호출
	Head->llink = Head;
	Head->rlink = Head;		// Head->llink = Head->rlink = Head;으로 줄일 수 있음

	int num, data;

	cout << "입력할 노드의 개수는 ? : ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		// 노드 값 입력
		cin >> data;

		DNode* new_node = new DNode(data);	// 생성자 함수 DNode(int) 호출
		// new_node->data = data;
		// new_node->llink = NULL;
		// new_node->rlink = NULL;

		// 노드를 리스트에 추가
		insert_node(new_node);
	}

	print_list();

	cout << "\n삭제할 값은 ? : ";
	cin >> data;

	delete_node(data);

	print_list();
}