#include <iostream>
using namespace std;

// (스택활용)중위 표기를 후위 표기로 변환 후 계산
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

char post_fix_expr[1000];
int p_index = 0;

char *postfix(char expr[])
{
	Stack MyStack;

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
			// cout << MyStack.pop();
			post_fix_expr[p_index++] = MyStack.pop();
		}
		else if (expr[i] == ' ')	// 공백이면
		{
			continue;
		}
		else	// 피연산자면
		{
			// cout << expr[i];
			post_fix_expr[p_index++] = expr[i];
		}
	}
	// cout << endl << endl;
	post_fix_expr[p_index] = '\0';	// 마지막에 null 넣기
	return post_fix_expr;
}

int calculate(char postfix[])
{
	Stack MyStack;

	for (int i = 0; i < strlen(postfix); i++)
	{
		// 연산자면 pop() 후 계산, 계산 결과는 다시 스택에 push
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
		else if (postfix[i] >= '0' && postfix[i] <= '9')  // 피연산자면 스택에 push
		{	// 0~9까지만 피연산자로 받아들임
			MyStack.push(postfix[i] - '0');	// 문자를 숫자로 변환하는 기초적인 방법
		}
	}

	// 최종 결과는 스택에 남아 있는 값을 pop하여 반환
	return MyStack.pop();
}

void main()
{
	char string[100];
	cout << "수식을 입력하세요 : ";
	cin.getline(string, 100);

	char *post_expr = postfix(string);

	cout << string << " = " << post_expr << " = " << calculate(post_expr) << endl;
}