/*
#include <iostream>
using namespace std;

// (����Ȱ��)���� ǥ�⸦ ���� ǥ��� ��ȯ
// ��ȣ�� �� �Ǿ��ִٰ� ����

#define element char		// element�� char��
const int MAX_SIZE = 1000;	// #define MAX_SIZE 1000

class Stack {
public:
	char mystack[MAX_SIZE];
	int top;

	Stack() { top = -1; }

	bool is_stack_empty() {
		// if (top == -1) return true;
		// else return false;
		return (top == -1);		// * ��� *
	}

	bool is_stack_full() {
		// if (top == MAX_SIZE - 1) return true;
		// else return false;
		return (top == MAX_SIZE - 1);
	}

	void push(element data) {
		if (is_stack_full()) {
			cout << "ERROR: Stack Full" << endl;
			return;
		}
		else {
			// top++;
			// Stack[top] = data;
			mystack[++top] = data;
		}
	}

	element pop() {
		if (is_stack_empty()) {
			cout << "ERROR: Stack Empty" << endl;
			return -1;	// exit();
		}
		else {
			// element x = Stack[top];
			// top--;
			// return x;
			return mystack[top--];
		}
	}

	element peek() {
		if (is_stack_empty()) {
			cout << "ERROR: Stack Empty" << endl;
			return -1;
		}
		else {
			return mystack[top];
		}
	}

	void print_stack() {
		cout << "STACK STATUS (top = " << top << ")" << endl;

		if (is_stack_empty()) return;
		else {
			for (int i = top; i >= 0; i--)
				cout << mystack[i] << endl;
		}
	}
};

void postfix(char expr[]) 
{	
	Stack MyStack;

	cout << "�Է� ���� = " << expr << endl;
	cout << "���� ���� = ";

	// convert to postfix
	// ����: �Ұ�ȣ��, ��Ģ����, �ǿ����ڴ� ���ڸ�
	for (int i = 0; i < strlen(expr); i++)
	{
		if (expr[i] == '(')	// ���� ��ȣ��
		{
			continue;
		}
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')	// �����ڸ�
		{
			MyStack.push(expr[i]);
		}
		else if (expr[i] == ')')	// ������ ��ȣ��
		{
			cout << MyStack.pop();
		}
		else if (expr[i] == ' ')	// �����̸�
		{
			continue;
		}
		else	// �ǿ����ڸ�
		{
			cout << expr[i];
		}
	}
	cout << endl << endl;
}

void main()
{
	char string[100];
	cout << "������ �Է��ϼ��� : ";
	cin.getline(string, 100);

	postfix(string);
}
*/