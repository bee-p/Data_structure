#include <iostream>
using namespace std;

void main()
{
	// 1차원 배열과 포인터
	int* ptr;
	int score1[10] = { 10, 20 , 30, 40, 50, 60 };

	ptr = score1;
	
	// 모두 같은 주소값이 뜨는 것을 확인할 수 있다.
	// 배열명, &배열명, &배열첫원소가 모두 동일 주소값을 출력
	cout << score1 << endl;
	cout << &score1 << endl;
	cout << &score1[0] << endl;

	// score1과 동일하게 배열의 시작 주소가 뜸
	cout << ptr << endl;
	

	for (int i = 0; i < 10; i++)
	{
		// 배열원소들이 연속된 기억 장소를 갖고 있음을 확인
		// 각 원소의 크기 확인
		// int 배열 - 각 원소마다 4byte씩 차지
		cout << "index = " << i << ">>> 주소 : " << &score1[i] << endl;

		// &score1[i]와 score1 + i가 동일함을 확인
		// score1 + i  >>> 인덱스가 i인 원소의 주소
		// 컴파일러에서는 &score1[i]도 score1 + i의 표현으로 바뀜
		cout << (score1 + i) << endl;
		
		// index가 i인 원소의 값 score1[i]와 동일한 표현
		cout << *(score1 + i) << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		// 각 원소의 값 출력
		cout << "score1[" << i << "] = " << score1[i] << endl;
		cout << "score1[" << i << "] = " << *(score1 + i) << endl;
		cout << "score1[" << i << "] = " << *(ptr + i) << endl;
		cout << "score1[" << i << "] = " << *(ptr++) << endl;
		cout << "score1[" << i << "] = " << ptr[i] << endl;
	}


	// --------------------------------------------- //
	// 2차원 배열과 포인터
	int score[3][4] = { {10, 20, 30, 40},
						{100, 110, 120, 130},
						{200, 210, 220, 230} };

	// 첫번째 원소의 주소값(2차원 배열의 시작주소)
	cout << score << " : " << &score << " : " << &score[0][0] << endl;

	// 각각 1행에 16바이트가 필요함을 알 수 있음(끝에서 두번째 숫자가 1씩 커짐)
	// int형 원소 * 4개 == 4byte * 4 == 16byte
	cout << score[0] << " : " << score[1] << " : " << score[2] << endl;

	// 그대로 주소값이 나오는 것을 확인
	cout << &score[0] << " : " << &score[1] << " : " << &score[2] << endl;

	// 원소값이 나오는 것을 확인
	cout << score[0][0] << " : " << score[1][0] << " : " << score[2][0] << endl;

	// 나오는 원소값 확인
	// 10, 120, 230
	cout << *score[0] << " : " << *(score[1] + 2) << " : " << *(score[2] + 3) << endl;
}