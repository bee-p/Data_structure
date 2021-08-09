#include <iostream>
using namespace std;

// 단순 배열 스택으로 괄호 검사 응용
#define element int		// element는 int형
const int MAX_SIZE = 1000;	// #define MAX_SIZE 1000

element Stack[MAX_SIZE];
int top = -1;	// 스텟 포인터 초기화 sp = -1;

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
		else	// 나머지 문자는 건너뜀
		{}
	}
	if (is_stack_empty()) return true;
	return true;
}

void main()
{
	char string[100];
	cout << "수식을 입력하세요 : ";
	cin.getline(string, 100);

	if (check_matching(string) == true) 
		cout << string << " ==> 괄호 OK" << endl;
	else 
		cout << string << " ==> 괄호 ERROR" << endl;
}