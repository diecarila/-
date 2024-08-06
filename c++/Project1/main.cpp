
// # <- 전처리기 컴파일러가 제일 처음에 인식함

#include <iostream>
#include "Function/function.h"
#define HUNGRY  0x1
#define THIRSTY 0x2
#define TIRED   0x4
#define FIRE    0x8

#define COLD    0x10  // f에서 다음자리로 넘어감
#define POISON  0x20
#define POISON1  0x40
#define POISON2  0x80

#define POISON3  0x100
#define POISON4  0x200
#define POISON5  0x400
#define POISON6  0x800

#include<stdio.h> // 표준 입출력
// define 을 사용함으로써 이점
// 1. 가독성
// 2. 코드 유지보수 용이

int dd = 0;

int Add(int left, int right) // <-- left, right 도 지역변수라는걸 알아야함
{
	return left + right;
}

int main()
{
	

	// �ڷ��� (ũ����� byte)
	// ������ : char(1), short(2), int(4), long(4), long long(8)
	// �Ǽ��� : float(4), double(8)
	// �������� �Ǽ����� �����ϴ� ������ ���� ó������� �ٸ��� ����.
	// int i = 0;

	// 1����Ʈ�� ����� ǥ��
	// 256���� -> 0 ~ 255
	unsigned char c = 0; // ����ε�� ����� �����Ѵٴ� �ǹ�

	c = 0;
	c = 255;

	// 1����Ʈ�� ���,���� �� �� ǥ��
	// -128 ~ 0 ~ 127

	char c1 = 0;
	c1 = 255;

	 /*���� ���� ã��(2�� ������)
	 �����Ǵ� ����� ��ȣ�� ���� �� , 1�� ���Ѵ�

	 ����ǥ�� ��İ� �Ǽ� ǥ�� ����� �ٸ���
	 �Ǽ�ǥ�� ����� ���е��� �����Ѵ�
	 ���� double(8) �ڷ����� flaot(4) �ڷ������� �� ū �޸𸮸� ����ϱ� ������
	 ���� ���� �ڸ��� �Ҽ������� ǥ�� ����. 

	 ������ ��������, �Ǽ��� �Ǽ����� �����ϵ�, �� ǥ������� �� �����ڰ� ����� ��� ��������� ��ȯ����*/
	float f = 10.2415f + (float)20; // �ڿ� f�� ���ΰ� float Ÿ��(4Byte) �� ���ڴٴ¶� �� ������ double Ÿ��(8Byte) �� ���ڴٴ°� ���� �ε��Ҽ��� �ڿ� ���̰ų� ��.

	

	 /*������
	 ���� ������, =
	
	 ��� ������
	 +, -, /, %(��ⷯ��, ������, �ǿ����ڰ� ��� ����)
	 ++,--* // 증감연산자 -> 한 단계 증가시킨다 라는 식으로 이해
	int data = 10 + 10;
	data = data + 20;
	data += 20; // ���� �Ȱ��� ��

	 data = 10 / 3; 
	 data = (int)(10. / 3. ); ��Ʈ�� �������̰� ������� �Ǽ����̶� ���� ��. �׷��� ������� ��Ʈ�� ������.
	             ���� �ڿ� ��� �� �ٴ´ٴ°��� double(8Bit) Ÿ������ ���ڴٴ� ��.*/

	// 논리 연산자
	// !(역), &&(곱), || (합)
	// 참(true), 거짓(false)
	// 참   : 0이 아닌 값 대부분 1
	// 거짓 : 0
	bool truefalse = true;			// bool 은 참 거짓 전용 자료형 True False만 받아들임
	bool IsTrue = 100;				// IsTrue 값은 100 이 아니라 1로 받음.


	// 비교 연산자
	// ==, != , < , >, <=, >=
	// 참, 거짓

	/*if ()      // if 안에서 동시에 적용이 안됨  ex) if가 만족하면 else if 는 안 넘어감
	{

	}

	else if ()
	{

	}

	else if ()
	{

	}

	else()
	{

	}*/

	/*if ()      // 별개의 조건을 거는것 ex) if가 만족해도 아래 if까지 볼 수 있음.
	{

	}

	if ()
	{

	}

	if ()
	{

	}

	if ()
	{

	}*/
	int iTest = 10;
	switch (iTest)   // break 를 걸어주지 않으면 걸리지 않고 아래것까지 진행함
	{
	case 10:

		break;

	case 20:
		break;

	default:
		break;
	}

	// 삼항 연산자           가독성 이슈로 굳이?의 느낌
	// :?
	iTest == 10 ? iTest = 100 : iTest = 200;  // 참이면 : 기준 왼쪽 거짓이면 오른쪽

	// 같은 의미
	if (iTest == 10)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}

	// 비트 연산자
	// 쉬프트 <<, >> 



	// 비트 곱(&), 합(|), xor(^) 반전(~)   
	// xor : 같으면 0, 다르면 1

	unsigned int iStatus = 0;

	// 상태 추가
	iStatus |= HUNGRY;
	iStatus |= THIRSTY;

	// 상태 확인
	if (iStatus & THIRSTY)
	{

	}


	// 특정 자리 비트 제거   이거 집가서 다시봐라
	iStatus &= ~THIRSTY; // 2
	//  1 1 1 0 0 1 1 0    -> 예시
	//  1 1 1 1 1 1 0 1    -> THIRSTY 의 반대(~)
	// ------------------     & 비트 연산
	//  1 1 1 0 0 1 0 0    -> THIRSTY 의 비트 자리만 바뀜.

	// 이걸 쓸 상황은 예를 들면, 게임 스테이터스(상태)창 갈증이 나는 상태이면
	// 그 디버프만 없애고 싶을 때. 그럴 때 쓰임 의외로 자주 쓰이니 기억해두자

	// 변수
	// 1. 지역변수
	// 2. 전역변수
	// 3. 정적변수
	// 4. 외부변수
	 
	// 지역변수
	int iName = 0;

	// 괄호 안에 선언된 변수(함수, 지역)
	{
		// 변수명 규칙
		int iName = 100; // <-- 하지만 괄호 안에서는 선언이 가능함 단 괄호 안에서만 활동
		iName;
		{
			{

			}
		}
	}

	// int iName = 100;    <-- 재선언 불가
	iName = 100;

	// 함수
	// printf();
	// scanf();
	

	// 반복문
	// for (/*반복자 초기화*/ ; /*반복자 조건 체크*/ ; /*반복자 변경*/)
	// {

	// }

	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 1)
		{
			continue; // -> 그냥 넘어감 아래 구문을 실행하지않고
		}

		std::cout << "Output Test\n";   // printf("Output Test\n")
	}
	
	/*int i = 0;
	while (i < 2)
	{
		printf("OutPut Test\n"); 

		++i;

		continue;

		break;
	}*/
	
	// 콘솔
	// printf
	printf("abcdef %d \n", 10);  // %d에 뒤에 10이 들어감
	printf("abcdef %f \n", 3.14f); // 실수 타입은 뒤에 f

	for (int i = 0; i < 10; ++i)
	{
		printf("Output i : %d \n", i);
	}
	
	// scanf
	int iInput = 0;
	scanf_s("%d", &iInput);  // --> & 이유는 나중에 설명.

	// 먼저 들어온 게 먼저 나가는 데이터구조  Queue ->  선입 선출
	//	정반대의 구조						  Stack ->  선입 후출

	// 함수가 사용하는 메모리 영역은 Stack 영역
	

	// 함수의 작동 원리
	// 1. main 함수에서 add 함수를 호출
	
	
	//      Stack 영역
	//
	//		add 
	//      main

	// 2. add 함수에 a,b 를 보냄
	// 3. add 함수에서 a,b를 계산한 후 리턴을 만남
	// 4. return 값을 다시 main에 보낸 후 메모리 영역에서 사라짐.








	return 0;
}