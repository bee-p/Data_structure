#include <iostream>
using namespace std;

#define element Pos
#define MAZE_SIZE 6
#define STACK_SIZE 10

struct Pos {	// 좌표 구조체
	int r, c;
};

// 0 : 갈 수 있는 길
// 1 : 갈 수 없는 길(벽)
// s : 출발점, m : 현재 위치, x : 출구
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

	void push_pos(int r, int c) {	// 해당 위치를 스택에 push
		if (r < 0 || c < 0) return;
		if (maze[r][c] != '1' && maze[r][c] != '.') {	// 해당 좌표가 벽도, 이미 지나온 길도 아니면
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

	void print_stack() {	// 구조체 사용으로 인해 출력 형식 변경함
		cout << "STACK STATUS" << endl;

		if (is_stack_empty()) return;
		else {
			for (int i = top; i >= 0; i--)
				cout << myStack[i].r << ', ' << myStack[i].c << endl;
		}
	}
};

void maze_print()	// 현재 미로 출력
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
	// 위치 좌표를 넣기 위한 스택
	Stack posStack;

	// 좌표 변수 (r: 행, c: 열)
	element pos;


	// 1. 시작 좌표 찾기
	for (pos.r = 0; pos.r < MAZE_SIZE; pos.r++) {	// 행 둘러보기
		for (pos.c = 0; pos.c < MAZE_SIZE; pos.c++) {	// 열 둘러보기
			// 해당 좌표가 출발점이면 모든 루프 나오기
			if (maze[pos.r][pos.c] == 's')	goto EXIT;
		}
	}
	EXIT:	// 출발점을 찾았을 경우의 이동 지점

	// 2. 경로 탐색, 출구가 나오면 마침
	while (maze[pos.r][pos.c] != 'x')
	{
		maze[pos.r][pos.c] = '.';			// 현재 위치를 .으로 변경

		maze_print();

		posStack.push_pos(pos.r - 1, pos.c);	// 상
		posStack.push_pos(pos.r + 1, pos.c);	// 하
		posStack.push_pos(pos.r, pos.c - 1);	// 좌
		posStack.push_pos(pos.r, pos.c + 1);	// 우

		// 스택이 비어있다면 더이상 나아갈 길이 없으므로 미로 찾기 실패
		if (posStack.is_stack_empty()) {
			cout << "\n미로 탈출에 실패 했습니다." << endl;
			return;
		}
		// 그게 아니라면 스택 상단의 위치를 불러와 현재 위치로 변경
		else
			pos = posStack.pop();
	}
	cout << "\n미로 탈출에 성공 했습니다!" << endl;
}