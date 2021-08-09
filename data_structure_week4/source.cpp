#include <iostream>
using namespace std;

void main()
{
	// 1���� �迭�� ������
	int* ptr;
	int score1[10] = { 10, 20 , 30, 40, 50, 60 };

	ptr = score1;
	
	// ��� ���� �ּҰ��� �ߴ� ���� Ȯ���� �� �ִ�.
	// �迭��, &�迭��, &�迭ù���Ұ� ��� ���� �ּҰ��� ���
	cout << score1 << endl;
	cout << &score1 << endl;
	cout << &score1[0] << endl;

	// score1�� �����ϰ� �迭�� ���� �ּҰ� ��
	cout << ptr << endl;
	

	for (int i = 0; i < 10; i++)
	{
		// �迭���ҵ��� ���ӵ� ��� ��Ҹ� ���� ������ Ȯ��
		// �� ������ ũ�� Ȯ��
		// int �迭 - �� ���Ҹ��� 4byte�� ����
		cout << "index = " << i << ">>> �ּ� : " << &score1[i] << endl;

		// &score1[i]�� score1 + i�� �������� Ȯ��
		// score1 + i  >>> �ε����� i�� ������ �ּ�
		// �����Ϸ������� &score1[i]�� score1 + i�� ǥ������ �ٲ�
		cout << (score1 + i) << endl;
		
		// index�� i�� ������ �� score1[i]�� ������ ǥ��
		cout << *(score1 + i) << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		// �� ������ �� ���
		cout << "score1[" << i << "] = " << score1[i] << endl;
		cout << "score1[" << i << "] = " << *(score1 + i) << endl;
		cout << "score1[" << i << "] = " << *(ptr + i) << endl;
		cout << "score1[" << i << "] = " << *(ptr++) << endl;
		cout << "score1[" << i << "] = " << ptr[i] << endl;
	}


	// --------------------------------------------- //
	// 2���� �迭�� ������
	int score[3][4] = { {10, 20, 30, 40},
						{100, 110, 120, 130},
						{200, 210, 220, 230} };

	// ù��° ������ �ּҰ�(2���� �迭�� �����ּ�)
	cout << score << " : " << &score << " : " << &score[0][0] << endl;

	// ���� 1�࿡ 16����Ʈ�� �ʿ����� �� �� ����(������ �ι�° ���ڰ� 1�� Ŀ��)
	// int�� ���� * 4�� == 4byte * 4 == 16byte
	cout << score[0] << " : " << score[1] << " : " << score[2] << endl;

	// �״�� �ּҰ��� ������ ���� Ȯ��
	cout << &score[0] << " : " << &score[1] << " : " << &score[2] << endl;

	// ���Ұ��� ������ ���� Ȯ��
	cout << score[0][0] << " : " << score[1][0] << " : " << score[2][0] << endl;

	// ������ ���Ұ� Ȯ��
	// 10, 120, 230
	cout << *score[0] << " : " << *(score[1] + 2) << " : " << *(score[2] + 3) << endl;
}