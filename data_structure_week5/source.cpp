#include <iostream>
using namespace std;

void main()
{
	/*
	int score[10] = { 10, 20, 30 };
	// char str[10] = { 's', 't', 'r', 'i', 'n', 'g' };
	char str[] = "This is my world";
	char* ptr;

	ptr = str;
	// *(ptr + 4) = '\0';	// *(str+4) ==== str[4] ==== ptr[4] ==== *(ptr+4)

	// char str[7] = "String"; ó�� ""�ȿ� ���ڸ� �־��ָ�
	// '\0'�� �ڿ� �ڵ����� ����.
	// �迭 ���ó�� ������ ���� �ڵ����� ������ ������,
	// �� ���� �ڿ� ���� �پ� ���������� ��µǴ� ���� ��..?


	// char str[6] = { 's', 't', 'r', 'i', 'n', 'g' };�� �ϸ�
	// str��½� -> string �ڿ� �̻��� ���ڵ鵵 ���� ��µ�
	// ������ ĭ�� '\0'�� �� �� ���� �� ��µǴ� ���̱� ����
	// '\0'�� �����ϸ� �� ���ڿ��� ������ �ν���


	// cout << score << endl;
	cout << str << endl;
	cout << ptr + 5 << endl;
	*/

	/*
	// ���� �Ҵ�, �� �ֱ�
	int* score;
	int num;

	cout << "�л� ����? : ";
	cin >> num;

	score = new int[num];

	for (int i = 0; i < num; i++)
		cin >> *(score + i);	// score[i]

	int sum = 0;

	for (int i = 0; i < num; i++)
		sum += score[i];

	cout << sum;
	*/

	
	// ����ü �ǽ�
	struct employ
	{
		char name[20];
		int year;
		int salary;
	};
	struct employ kim, jung, park;
	struct employ* ptr;

	kim = { "kim", 2010, 3000 };
	jung = { "jung", 2011, 2500 };
	park = { "park", 2009, 3400 };

	ptr = &kim;

	cout << kim.name << " : " << kim.year << endl;
	cout << ptr->name << " : " << ptr->year << endl;
	cout << (*ptr).name << " : " << (*ptr).year << endl;
}