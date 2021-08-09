#include <iostream>
using namespace std;

// �ܼ� �迭 �������� ��ȣ �˻� ����
#define element int		// element�� int��
const int MAX_SIZE = 1000;	// #define MAX_SIZE 1000

element Stack[MAX_SIZE];
int top = -1;	// ���� ������ �ʱ�ȭ sp = -1;

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
		Stack[++top] = data;
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
		return Stack[top--];
	}
}

element peek() {
	if (is_stack_empty()) {
		cout << "ERROR: Stack Empty" << endl;
		return -1;
	}
	else {
		return Stack[top];
	}
}

void print_stack() {
	cout << "STACK STATUS (top = " << top << ")" << endl;

	if (is_stack_empty()) return;
	else {
		for (int i = top; i >= 0; i--)
			cout << Stack[i] << endl;
	}
}

bool check_matching(char sentence[]) {
	int len = strlen(sentence);
	
	for (int i = 0; i < len; i++)
	{
		if (sentence[i] == '(' || sentence[i] == '{' || sentence[i] == '[' || sentence[i] == '<')
		{
			push(sentence[i]);
		}
		else if (sentence[i] == ')')
		{
			if (is_stack_empty()) return false;

			char left = pop();
			if (left == '(') continue;
			else return false;
		}
		else if (sentence[i] == '}')
		{
			if (is_stack_empty()) return false;

			char left = pop();
			if (left == '{') continue;
			else return false;
		}
		else if (sentence[i] == ']')
		{
			if (is_stack_empty()) return false;

			char left = pop();
			if (left == '[') continue;
			else return false;
		}
		else if (sentence[i] == '>')
		{
			if (is_stack_empty()) return false;

			char left = pop();
			if (left == '<') continue;
			else return false;
		}
		else	// ������ ���ڴ� �ǳʶ�
		{}
	}
	if (is_stack_empty()) return true;
	return true;
}

void main()
{
	char string[100];
	cout << "������ �Է��ϼ��� : ";
	cin.getline(string, 100);

	if (check_matching(string) == true) 
		cout << string << " ==> ��ȣ OK" << endl;
	else 
		cout << string << " ==> ��ȣ ERROR" << endl;
}