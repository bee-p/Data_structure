/*
#include <iostream>
using namespace std;

// (스택활용)중위 표기를 후위 표기로 변환
// 괄호가 잘 되어있다고 가정

#define element char		// element는 char형
const int MAX_SIZE = 1000;	// #define MAX_SIZE 1000

class Stack {
public:
	char mystack[MAX_SIZE];
	int top;

	Stack() { top = -1; }

	bool is_stack_empty() {
		// if (top == -1) return true;
		// else return false;
		return (top == -1);		// * 축약 *
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

	cout << "입력 수식 = " << expr << endl;
	cout << "후위 수식 = ";

	// convert to postfix
	// 가정: 소괄호만, 사칙연산, 피연산자는 한자리
	for (int i = 0; i < strlen(expr); i++)
	{
		if (expr[i] == '(')	// 왼쪽 괄호면
		{
			continue;
		}
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')	// 연산자면
		{
			MyStack.push(expr[i]);
		}
		else if (expr[i] == ')')	// 오른쪽 괄호면
		{
			cout << MyStack.pop();
		}
		else if (expr[i] == ' ')	// 공백이면
		{
			continue;
		}
		else	// 피연산자면
		{
			cout << expr[i];
		}
	}
	cout << endl << endl;
}

void main()
{
	char string[100];
	cout << "수식을 입력하세요 : ";
	cin.getline(string, 100);

	postfix(string);
}
*/