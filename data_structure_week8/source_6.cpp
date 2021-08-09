#include <iostream>
using namespace std;

// ���� ���� ����Ʈ (��������Ʈ + �����)

class DNode {	// D-Node : ���� ���
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

void insert_node(DNode* new_node)	// ����Ʈ �������� ���ο� ��� �߰�
{
	new_node->rlink = Head;
	new_node->llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;
}

void delete_node(int key)	// Ű ���� ������ ���� ���� ��� ����
{
	for (DNode* list = Head->rlink; list != Head; list = list->rlink) 
	{
		if (list->data == key)
		{	// ���� ��ũ�� �ǳʶٰ� ��
			list->llink->rlink = list->rlink;
			list->rlink->llink = list->llink;
			return;
		}
	}
}

void print_list()
{
	cout << "\n����Ʈ ���� ���" << endl;

	// Head�� rlink�� ù��° ���
	// list = list->rlink : ����Ʈ ���������� �� ����
	for (DNode* list = Head->rlink; list != Head; list = list->rlink)
	{	
		cout << list->data << endl;
	}

	// ���� ���
	// for (DNode* list = Head->llink; list != Head; list = list->llink)
}

void main()
{
	// ����� ����
	Head = new DNode;		// ������ �Լ� DNode() ȣ��
	Head->llink = Head;
	Head->rlink = Head;		// Head->llink = Head->rlink = Head;���� ���� �� ����

	int num, data;

	cout << "�Է��� ����� ������ ? : ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		// ��� �� �Է�
		cin >> data;

		DNode* new_node = new DNode(data);	// ������ �Լ� DNode(int) ȣ��
		// new_node->data = data;
		// new_node->llink = NULL;
		// new_node->rlink = NULL;

		// ��带 ����Ʈ�� �߰�
		insert_node(new_node);
	}

	print_list();

	cout << "\n������ ���� ? : ";
	cin >> data;

	delete_node(data);

	print_list();
}