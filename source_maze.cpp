#include <iostream>
using namespace std;

#define element Pos
#define MAZE_SIZE 6
#define STACK_SIZE 10

struct Pos {	// ��ǥ ����ü
	int r, c;
};

// 0 : �� �� �ִ� ��
// 1 : �� �� ���� ��(��)
// s : �����, m : ���� ��ġ, x : �ⱸ
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'s', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'}
};

class Stack {
public:
	element myStack[STACK_SIZE];
	int top;

	Stack() {
		top = -1;
	}

	bool is_stack_empty() {
		return (top == -1);
	}

	bool is_stack_full() {
		return (top == STACK_SIZE - 1);
	}

	void push(element data) {
		if (is_stack_full()) {
			cout << "ERROR: Stack Full" << endl;
		}
		else {
			myStack[++top] = data;
		}
	}

	void push_pos(int r, int c) {	// �ش� ��ġ�� ���ÿ� push
		if (r < 0 || c < 0) return;
		if (maze[r][c] != '1' && maze[r][c] != '.') {	// �ش� ��ǥ�� ����, �̹� ������ �浵 �ƴϸ�
			element tmp;
			tmp.r = r;
			tmp.c = c;
			push(tmp);
		}
	}

	element pop() {
		if (is_stack_empty()) {
			cout << "ERROR: Stack Empty" << endl;
			exit(-1);
		}
		else {
			return myStack[top--];
		}
	}

	element peek() {
		if (is_stack_empty()) {
			cout << "ERROR: Stack Empty" << endl;
			exit(-1);
		}
		else {
			return myStack[top];
		}
	}

	void print_stack() {	// ����ü ������� ���� ��� ���� ������
		cout << "STACK STATUS" << endl;

		if (is_stack_empty()) return;
		else {
			for (int i = top; i >= 0; i--)
				cout << myStack[i].r << ', ' << myStack[i].c << endl;
		}
	}
};

void maze_print()	// ���� �̷� ���
{
	cout << endl;
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			cout << maze[r][c] << ' ';
		}
		cout << endl;
	}
}

void main() 
{
	// ��ġ ��ǥ�� �ֱ� ���� ����
	Stack posStack;

	// ��ǥ ���� (r: ��, c: ��)
	element pos;


	// 1. ���� ��ǥ ã��
	for (pos.r = 0; pos.r < MAZE_SIZE; pos.r++) {	// �� �ѷ�����
		for (pos.c = 0; pos.c < MAZE_SIZE; pos.c++) {	// �� �ѷ�����
			// �ش� ��ǥ�� ������̸� ��� ���� ������
			if (maze[pos.r][pos.c] == 's')	goto EXIT;
		}
	}
	EXIT:	// ������� ã���� ����� �̵� ����

	// 2. ��� Ž��, �ⱸ�� ������ ��ħ
	while (maze[pos.r][pos.c] != 'x')
	{
		maze[pos.r][pos.c] = '.';			// ���� ��ġ�� .���� ����

		maze_print();

		posStack.push_pos(pos.r - 1, pos.c);	// ��
		posStack.push_pos(pos.r + 1, pos.c);	// ��
		posStack.push_pos(pos.r, pos.c - 1);	// ��
		posStack.push_pos(pos.r, pos.c + 1);	// ��

		// ������ ����ִٸ� ���̻� ���ư� ���� �����Ƿ� �̷� ã�� ����
		if (posStack.is_stack_empty()) {
			cout << "\n�̷� Ż�⿡ ���� �߽��ϴ�." << endl;
			return;
		}
		// �װ� �ƴ϶�� ���� ����� ��ġ�� �ҷ��� ���� ��ġ�� ����
		else
			pos = posStack.pop();
	}
	cout << "\n�̷� Ż�⿡ ���� �߽��ϴ�!" << endl;
}