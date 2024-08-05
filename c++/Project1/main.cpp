
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


// define 을 사용함으로써 이점
// 1. 가독성
// 2. 코드 유지보수 용이

int main()
{
	

	// �ڷ��� (ũ����� byte)
	// ������ : char(1), short(2), int(4), long(4), long long(8)
	// �Ǽ��� : float(4), double(8)
	// �������� �Ǽ����� �����ϴ� ������ ���� ó������� �ٸ��� ����.
	int i = 0;

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
	iStatus &= ~THIRSTY;
}