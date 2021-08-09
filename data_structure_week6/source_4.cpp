#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
};

// ��������͸� ���������� ����
// �Լ��� ���ڸ� �ѱ��� �ʾƵ� �ǵ��� ��
Node* Head;

void insert_node_A(Node* pre, Node* new_node) {	// ���� �Լ�(A���-������ �̿�)
	if (Head == NULL) {		// ���� ����Ʈ�� ���
		Head = new_node;
	}
	else if (pre == NULL) {		// pre�� NULL�̸� ù��° ���� ����
		new_node->link = Head;
		Head = new_node;
	}
	else {		// pre ������ ����
		new_node->link = pre->link;
		pre->link = new_node;
	}

}

void insert_node_at_rear(Node* new_node) {	// �����Լ�(B��� - �����带 �𸣴� ���)
	// ����Ʈ �������� ��� ������
	if (Head == NULL)	// ���� ����Ʈ�� ���
		Head = new_node;
	else {
		Node* list = Head;

		// ����Ʈ�� ������ ��带 ����ų ������ �̵�
		while (list->link != NULL)
			list = list->link;

		list->link = new_node;

	}
}

void insert_node_at_front(Node* new_node) {	// �����Լ�(C��� - ����Ʈ ó���� ��� ����)
	new_node->link = Head;
	Head = new_node;
}

void delete_node(int x) {	// ���� �Լ�(B��� - key(x)���� ���� ��带 ã�� ������)
	Node* pre = Head;

	if (Head == NULL) return;	// ������ ���� ����
	else if (Head->data == x)	// ã�� ���(���� ���)�� ù ����� ���
	{
		Head = Head->link;
		return;
	}
	else	// ������ ���
	{
		while (pre->link != NULL)	// ã�� ����� �� ��带 ã�� ��, pre�� ������ ���� Ż��
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

void reverse_list() {	// ����Ʈ ���� ����
	Node *p, *q, *r;	

	p = Head;
	q = r = NULL;
	while (p != NULL) {
		r = q;		// r -> q -> p ������ ����
		q = p;
		p = p->link;	// p�� ���� �ռ���
		q->link = r;	// q�� ��ũ ������ �������� �ٲ�
	}
	Head = q;
}

void print_list() {		// ���Ḯ��Ʈ ��� �Լ�
	for (Node* ptr = Head; ptr != NULL; ptr = ptr->link)	// for���ȿ� ������� �ϴ°� c++��Ÿ��..?
		if (ptr->link == NULL) cout << ptr->data << endl;
		else cout << ptr->data << "-->";
}

void main() 
{
	Head = NULL;

	// ������ �Է� ���� �Է� �ޱ�
	int data_number;
	cout << "��ü �Է� �������� ������? : ";
	cin >> data_number;
	
	for (int i = 0; i < data_number; i++)	// XX���� ������ �Է�
	{	
		// ���ο� �����͸� ���ʷ� �Է��� ����
		int i_data;
		cout << "���ο� ���� �Է��Ͻÿ�(#" << i+1 << ") : ";
		cin >> i_data;

		// ���ο� ��带 �����Ͽ� ������ ����
		Node* new_node = new Node;
		new_node->data = i_data;
		new_node->link = NULL;

		// ��ü ���Ḯ��Ʈ�� �߰�/����
		// insert_node_A(NULL, new_node);
		// insert_node_at_rear(new_node);
		insert_node_at_front(new_node);
	}

	// Ȯ�ο����� ���
	cout << "\n������ ���� ����Ʈ�� : ";
	print_list();

	/*
	// ���Ḯ��Ʈ���� ��� ���� �ݺ�
	for (int i = 0; i < 3; i++)
	{
		// ������ ����� �� �Է� �ޱ�
		int del_data;
		cout << "\n������ ����� �� : ";
		cin >> del_data;

		// �ش� ���� ���� ��� ����
		delete_node(del_data);

		// ��� ���� �� ���� ����Ʈ ���
		cout << "\n���� �� ���� ����Ʈ�� : ";
		print_list();
	}
	*/


	// ����Ʈ ���� ���� �׽�Ʈ
	reverse_list();
	print_list();
}