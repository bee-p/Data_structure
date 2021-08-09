#include <iostream>
using namespace std;

class CNode {
public:
	int data;
	CNode* link;
};

// ��������͸� ���������� ����
// �Լ��� ���ڸ� �ѱ��� �ʾƵ� �ǵ��� ��
CNode* Head = NULL;

void insert_node_at_rear(CNode* new_node) {	// ����Ʈ �������� ��� ������
	if (Head == NULL) {		// ���� ����Ʈ�� ���
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;	// ���ο� ��尡 ���� ������ ��� �ڿ� ����(���� new_node�� ������ ���)
		Head = new_node;	// Head�� �׻� ������ ��带 ����Ŵ(new_node�� �ٲ���)
	}
}

void insert_node_at_front(CNode* new_node) {	// ����Ʈ ó���� ��� ����
	if (Head == NULL) {		// ���� ����Ʈ�� ���
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;	// ���ο� ��尡 ù ��°(������ ��� ����)�� ����
	}
}

void delete_node(int key) {	// key���� ���� ��带 ã�� ������
	if (Head == NULL) return;	// �� ����Ʈ
	// ��尡 1���̸鼭 �� ���� key�� ��ġ�� ���
	else if (Head->link == Head && Head->data == key)	Head = NULL;
	else	// �Ϲ����� ���
	{
		CNode* pre = Head;
		do
		{
			if (pre->link->data == key) {
				CNode* removed = pre->link;
				pre->link = removed->link;	// pre->link = pre->link->link;
				if (Head == removed) Head = pre;	// ��������� pre�� �缳��
				return;
			}
			pre = pre->link;
		} while (pre != Head);
	}
}

void print_list() {		// ��ü ��� ���
	cout << "\n�������Ḯ��Ʈ ���" << endl;

	if (Head == NULL) return;
	else
	{
		CNode* ptr = Head;

		do
		{
			cout << ptr->link->data << endl;	// ù��° ������ ���
			ptr = ptr->link;
		} while (ptr != Head);
	}
}

void main()
{
	// ������ �Է� ���� �Է� �ޱ�
	int num;
	cout << "��ü �Է� �������� ������? : ";
	cin >> num;

	for (int i = 0; i < num; i++)	// XX���� ������ �Է�
	{	// �Է°��� �޾� ���Ḯ��Ʈ�� �߰�
		
		CNode* new_node = new CNode;
		int i_data;
		
		cout << "���ο� ���� �Է��Ͻÿ�(#" << i + 1 << ") : ";
		cin >> i_data;
		new_node->data = i_data;
		new_node->link = NULL;
		
		// ��ü ���Ḯ��Ʈ�� �߰�/����
		insert_node_at_rear(new_node);
	}

	// Ȯ�ο����� ���
	print_list();

	// ��� ����
	int del_data;

	cout << "\n������ ����: ";
	cin >> del_data;

	delete_node(del_data);

	print_list();
}