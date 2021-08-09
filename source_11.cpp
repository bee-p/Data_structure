#include <iostream>
using namespace std;

// (����Ȱ��)���� ǥ�⸦ ���� ǥ��� ��ȯ �� ���
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

char post_fix_expr[1000];
int p_index = 0;

char *postfix(char expr[])
{
	Stack MyStack;

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
			// cout << MyStack.pop();
			post_fix_expr[p_index++] = MyStack.pop();
		}
		else if (expr[i] == ' ')	// �����̸�
		{
			continue;
		}
		else	// �ǿ����ڸ�
		{
			// cout << expr[i];
			post_fix_expr[p_index++] = expr[i];
		}
	}
	// cout << endl << endl;
	post_fix_expr[p_index] = '\0';	// �������� null �ֱ�
	return post_fix_expr;
}

int calculate(char postfix[])
{
	Stack MyStack;

	for (int i = 0; i < strlen(postfix); i++)
	{
		// �����ڸ� pop() �� ���, ��� ����� �ٽ� ���ÿ� push
		if (postfix[i] == '+')
		{
			int oper2 = MyStack.pop();
			int oper1 = MyStack.pop();
			MyStack.push(oper1 + oper2);
		}
		else if (postfix[i] == '*')
		{
			int oper2 = MyStack.pop();
			int oper1 = MyStack.pop();
			MyStack.push(oper1 * oper2);
		}
		else if (postfix[i] == '-')
		{
			int oper2 = MyStack.pop();
			int oper1 = MyStack.pop();
			MyStack.push(oper1 - oper2);
		}
		else if (postfix[i] == '/')
		{
			int oper2 = MyStack.pop();
			int oper1 = MyStack.pop();
			MyStack.push(oper1 / oper2);
		}
		else if (postfix[i] >= '0' && postfix[i] <= '9')  // �ǿ����ڸ� ���ÿ� push
		{	// 0~9������ �ǿ����ڷ� �޾Ƶ���
			MyStack.push(postfix[i] - '0');	// ���ڸ� ���ڷ� ��ȯ�ϴ� �������� ���
		}
	}

	// ���� ����� ���ÿ� ���� �ִ� ���� pop�Ͽ� ��ȯ
	return MyStack.pop();
}

void main()
{
	char string[100];
	cout << "������ �Է��ϼ��� : ";
	cin.getline(string, 100);

	char *post_expr = postfix(string);

	cout << string << " = " << post_expr << " = " << calculate(post_expr) << endl;
}