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

	// char str[7] = "String"; 처럼 ""안에 문자를 넣어주면
	// '\0'이 뒤에 자동으로 들어가짐.
	// 배열 방식처럼 넣으면 널이 자동으로 들어가지진 않지만,
	// 운 좋게 뒤에 널이 붙어 정상적으로 출력되는 것일 것..?


	// char str[6] = { 's', 't', 'r', 'i', 'n', 'g' };로 하면
	// str출력시 -> string 뒤에 이상한 문자들도 같이 출력됨
	// 마지막 칸에 '\0'이 들어갈 수 없어 더 출력되는 것이기 때문
	// '\0'이 등장하면 그 문자열이 끝임을 인식함


	// cout << score << endl;
	cout << str << endl;
	cout << ptr + 5 << endl;
	*/

	/*
	// 동적 할당, 값 넣기
	int* score;
	int num;

	cout << "학생 수는? : ";
	cin >> num;

	score = new int[num];

	for (int i = 0; i < num; i++)
		cin >> *(score + i);	// score[i]

	int sum = 0;

	for (int i = 0; i < num; i++)
		sum += score[i];

	cout << sum;
	*/

	
	// 구조체 실습
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