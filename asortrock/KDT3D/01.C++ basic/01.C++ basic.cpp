// 솔루션 탐색기 -> 모든 파일 표시로 변경

// 프로젝트 우클릭 > 속성 -> 중간 디렉터리, 출력 디렉터리 변경
// 프로젝트 우클릭 -> 속성 -> c++20

//빌드
// 실행 파일을 만드는 과정
// - 전처리(Preprocess) : 소스코드에 담긴 메타 정보를 처리한다
// - 컴파일(Compile): 소스코드를 머신이 읽을 수 있는 파일로 변환한다
//                     (기계어 (바이너리(0,1)) 로 변환)
// - 링크(Link): 컴파일 단계에서 변환된 여러 object 파일을 실행가능 파일로 합친다
//              (우리가 작성한 소스코드 + 가져다 쓴 코드(라이브러리) 등을 합친다)

// *.pdb
// - 디버깅을 위한 기호 정보가 들어있다.
// - 실제로 유저에게 배포할때는 포함하면 안된다. 

// 컴파일러
// - 컴파일러 제조사가 컴파일러를 표준 C++ 문법을 따라서 컴파일 되게 구현한 프로그램
// - MSVC(MicroSort Visual C, C++) Compiler
// - gcc


// include 전처리 지시자
// (전처리 지시자는 컴파일러에게 알려주는 기능)
// include 뒤에 나오는 파일을 포함하겠다
// 포함이란 #include 부분에 대상 파일을 복사 붙여넣기 한다


// 단축키
// ctrl + - : 전에 보던 줄로 감.
// namespace : 다른곳에서 못 쓰게 함
// ctrl k d : 정리
// ctrl k c : 주석
// ct k u : 주석해제
// 컨트롤 F12 가 선언으로 이동
// 컨트롤 k,o 가 헤더랑 cpp 이동
// F12 정의로 이동
// 디버깅 종료 : 컨트롤 쉬프트 b



// Input Output Stream 입출력 담당하는 기능
#include <iostream>
#include <format>
#include "Function/Function.h"
#include <array>


int Glnt = 0;

bool FirstTrue()
{
	std::cout << "FirstTrue\n";
	return true;
}
bool FirstFalse()
{
	std::cout << "FirstFalse\n";
	return false;
}

void Function2();

// 메인이라는 함수는 시작하는 지점

int main()


{    // 브레이크 포인트(Break point): F5로 프로그램을 실행(디버거를 붙여서 실행) F9 또는 왼쪽 가장자리 클릭
	 // F10: 한 줄씩 실행 가능
	 // 디버거가 활성화된 상태에서 & Breakpoint 등으로 멈춰있는 상태에서
	 // 우클릭 -> 디스어셈블리로 이동을 클릭하면 어셈블리 코드 확인 가능

#pragma region 01. 표준 입출력 (cout, cin)
  //   int 는 4바이트                                        
  //  int a = 10;                                              
  //  int b { 0 };                                             
  //  std::cout << "숫자를 입력해주세요:";                     
  //  std::cin >> a; // 입력을 기다리는 것               
  //                                                           
  //                                                           
  //   // std라는 namespace(카테고리)에 있는 cout 함수를 호출    주석 한 번에 걸기 shift + ctrl , ctrl + k c,u
  //  std::cout << "안녕하세요 저는 " << a << "살입니다." << std::endl;



#pragma endregion

#pragma region 02. 리터럴
	{
		// 리터럴은 코드에 표시한 숫자나 문자열과 같은 값 을 의미
		// 십진수
		int V{ 100 };
		// 8진수 : 0144
		int V2{ 0144 }; // 쓸 일 없다
		// 16진수 : 0x64
		int V3{ 0x64 };
		// 2진수 :0b01100100 // 쓸 일 없다
		int V4{ 0b01100100 };

		// 부동소수점(floating point): 3.14f
		float F{ 3.14f };

		//배정도 부동소수점(double): 3.14
		double D{ 3.14 };

		// 단일 문자
		char C{ 'a' }; // ASCII 코드 표에 따라 숫자가 저장됨

		// 문자열 "" 단일문자 ''
	}
#pragma endregion

#pragma region 03. 변수(Valuable)*
	{
		// 1Byte == 8Bit ( 표현 가능한 범위 0 ~ 255)
		// 2진수로 나타내는 경우 1111 1111
		// 0000 ~ 1111
		// 1024Byte == 1KB
		// 1024KB == 1MB
		// 1024MB == 1GB
		// 1024GB == 1TB

		// 자료형: 타입 크기는 Byte에 해당 
		// 정수형: char(1Byte), short(2Byte), int(4Byte), long(4Byte), long long(8Byte), __int64(8Byte)
		//        주로 쓰는 것: char, int
		// 실수형: float(4Byte), double(8Byte)
		// 2진수를 10진수로 바꾸는거 알아두자. 아님 계산기

		{
			int Var{ 0 }; // 초기화 연산자로 변수를 선언과 동시에 초기화한다.
			Var = 10; // 대입 연산자를 사용해서 값을 변경
		}
		{

			//4Byte 정수형 signed 타입
			// signed 타입: 음수를 표현할 수 있다
			signed int Var{ -1 };
			Var = Var + 1;

			// unsigned 를 붙이면 부호가 없는 타입
			unsigned int Var2{ (unsigned int)-1 };
			Var2 = Var2 + 1;

			unsigned int Var3{ 4294967295 };
			Var3 = Var3 + 1;

			unsigned char C = 254;
			C = C + 1;
			C = C + 1000;
		}
		{    // 2Byte 정수형
			// -32,768 ~ 32,767
			short S1{ 32767 };
			S1 = S1 + 1;   // -32,768
			S1 = S1 - 1;   // +32,767

			signed short S2{ 20 };
			unsigned short S3 = 30;

		}
		{
			// 4Byte 정수형
			long L1{ 14L };
		}
		{
			// 8Byte 정수형
			long LL1{ 14LL };
			unsigned int Val3{ 4294967295 };
			unsigned int Val4{ (unsigned int)4294967296 };
			long long LL2{ 4294967296 };
			// long long LL3{ (unsigned int)4294967296 };
		}
		{

			// 4Byte 실수형
			// 단정도 부동소수점
			// 부동소수점은 오차가 발생할 수 있다.

			float F{ 3.14F };
			int Int{ (int)3.14F };

			// debug 인 경우 메모리 뒷쪽에
			// 추가정보가 기본적으로 들어가 있어서
			// 이를 비활성화 하면 변수 크기만큼만 공간을 확보한다
			// 프로젝트 속성 -> C/C++ -> 코드생성 -> 기본 런타임 검사 -> 기본값

		}

		{
			// 8Byte 실수형

			double D{ 3.14 };

		}

		{
			// 1Byte 정수형

			unsigned char C = 255;
			char C2 = (char)255;
			unsigned char C3 = 'A'; // ASCII 코드 표에 대응되는 수치로 변환해서 저장
			int Int = 'A';
			int Int2 = 65;
		}

		// 유니코드 (다국어 처리가 가능, char는 단일 문자 가능)

		{

			// 2Byte
			wchar_t W{ L'A' };
			wchar_t W2{ L'가' };
			// char C{ L'가' }; 표기 불가
		}
		// 부울타입 : 참과 거짓
		{

			// 1Byte
			bool B0 = true; // 1
			bool B1 = false; // 0
			bool B2 = 0; // false
			bool B3 = 1; // true
			bool B4 = 22; // true
		}



		// 부동소수점 오차
		{

			// double Value = 0.0;
			// if (Value == 0.0)
			// {
			//     std::cout << "Value 가 0 입니다.\n";
			// }
			//
			// Value = Value + 0.1;
			// Value = Value + 0.1;
			// Value = Value + 0.1;
			//
			// if (Value == 0.3)
			// {
			//     std::cout << "Value가 0.3 입니다.\n";
			// }

		}
		{
			// 초기화

			int intNolnit; // 초기화를 하지 않은 변수
			// 초기화: 변수를 선언함과 동시에 값을 지정하는것
			int intnolnit = 10; // 초기화가 아니라 값을 대입

			int intzerolnit = 0; // 선언과 동시에 값을 지정(초기화)
			int intzerolnit2 = { 0 };
			int intzerolnit3{ };  // 자동으로 0으로 초기화
			float Float{}; // 0으로 초기화 
		}
		// 형변환(cast): 서로 다른 타입으로 변환
		// C++ 타입(int, float, ...) 이 있기 때문에 타입간 변환이 필요한 상황이 생김
		{
			float Float{ 3.14F };
			int Int = Float;   // 묵시적 casting "경고"
			int Int2 = (int)Float; // 명시적 casting, C 스타일 cast
			int Int3 = int(Float); // 명시적 casting, C 스타일
			int Int4 = static_cast<int>(Float); // C++ 버전의 명시적 cast

			// 2Byte 정수
			short Short{ 10 };
			// 4Byte 정수
			int Int5 = Short; // 묵시적 casting
			// int가 short 보다 크고, 둘 다 정수 타입이라 경고 안 뜸.

			int Int6 = 999999;
			short Short1 = Int6; // 값이 잘림!, 경고도 발생하지 않는데 주의해서 사용 해야 겠습니다.
			
			double D = 3.1415;
			int i1 = D;

		}

	}
#pragma endregion

#pragma region 04. 지역변수, 전역변수와 메모리
	{
		// 지역변수는 지금까지 사용한 바와 같이 스코프({})의 시작과 끝 내부에서 선언되는
		// 변수를 의미합니다

		// 전역변수는 함수 밖에서 선언된 변수를 의미합니다.
		// 선언된 전역변수는 선언 이후에서는 스코프 내부에서 접근 가능

		Glnt = 500;

		// 유저 영역의 메모리 공간은 크게 4가지로 구성.
		// [코드 영역] : 소스코드가 기계어로 변환되어 실제 로직을 수행하는 코드 정보
		// [데이터 영역] : 전역변수, static 변수 등
		// [Heap] : 동적할당 (아직 배우지 않음)
		// [Stack] : 지역 변수

		// [프로그램의 메모리 구조]
		// -------------- 소스 코드 영역 ------------
		// ... 여러분 또는 누군가가 작성해둔 코드가 어셈으로 기록되어 있다
		// -------------- 데이터 영역 ----------------
		// ... 전역변수, static(정적) 변수
		// -------------- Heap 영역 ----------------
		// ... 동적 할당 (실행 중에 메모리 요청을 하는 것)
		// ..
		// ..
		// ..
		// ..
		// (RBP + 상대주소(0)) [a] (4byte)
		// (RBP + 상대주소(1)) [b] (4byte)
		// (RBP + 상대주소(2)) [c] (4byte)
		// (RBP + 상대주소(3)) [d] (4byte)
		// (RBP + 상대주소(4)) [e] (4byte)
		// (함수의 변수목록의 시작주소인 RBP 기준으로 + 상대 주소)
		// ....
		// ---------------- Stack 영역 ----------------

		/*
		[Code 영역]
		{
		   (0x00007FF7AF454FB3) Main 함수 기준점으로 부터 Stack의 시작 지점으로 부터 일정 위치가 떨어진 곳에 1을 넣어라
		}

		[Stack 영역]
		{

			- Main의 Stack 시작 위치
			- (0x00000003FA00F7A8)a = 10
			- b = ...
		}

		*/
		int a, b, c, d, e, f, g, h, i, j, k;

		a = 10;
		b = 20;
		c = 30;
		d = 40;
		e = 50;
	}
#pragma endregion

#pragma region 05. 연산자들
	{
		// 단항(unary; 유너리) 연산자: 표현식(expression) 하나를 계산
		// 이항(binary; 바이너리) 연산자: 표현식 2개를 계산
		// 삼항(temary; 텀메리) 연산자: 표현식 3개를 계산

		// 대입 연산자[이항]: 오른쪽 값을 왼쪽의 표현식에 대입하는 연산자
		{
			int i;
			i = 0;
			int k;
			k = 1;
		}
		// [단항] 표현식의 참 / 거짓 (참: 보통1, 0이 아닌 값 / 거짓: 0)
		{
			bool b1{ true };     // 참
			bool b2{ 1 };        // 참
			bool b3{ false };    // 거짓
			bool b4{ 0 };        // 거짓

			bool b5{ !true };    // 참이 아니다(부정, not) == 거짓(false)
			bool b6(!false);   // 거짓이 아니다 == 참(true)

			bool b7{ true };     // 참
			bool b8{ !b7 };      // b7이 참인데 b7(참)이 아니다 == 거짓 (!은 not 의 의미.)
		}

		// [이항]사칙 연산
		{
			int a{ 1 + 2 }; // 1 + 2 = 3
			int b{ a + 3 }; // a + 3 = 6

			int c{ 1 - 2 }; // 1 - 2 = -1
			unsigned int c2{ unsigned int(1 - 2) }; // 1 - 2 = -1 -> unsigned int 엄청 큰 값

			int d{ c * 3 }; // -1 * 3 = -3

			int e{ 10 / 3 }; // 3 int 로 하면 소수점이 날아감.
			float f{ 10 / 3 }; // int(10) / int(3) = int(3) -> float f = 3
			float f2{ 10.f / 3.f };
		}
		// [이항] mod, 나머지 연산자
		{
			int m{ 10 % 3 };   // 몫 3, 나머지 1
			int m2{ 5 % 2 };   // 몫 2, 나머지 1
			int m3{ 6 % 2 };   // 몫 3, 나머지 0
		}

		// [단항]후행 / 선행 연산자
		{
			// 후행 증가
			{
				int i{ 0 };
				// i++
				int k = i++; // k: 0, i: 1

				// 식 내부에 후행 연산자를 쓰지 마라
				// 실수할 여지가 많다
			}

			//  선행 증가
			{
				int i{ 0 };
				//++i;
				int k = ++i;   // k:1, i: 1

			}

			// 후행 감소
			{
				int i{ 0 };
				//--i;
				int k{ --i }; // k: 0, i: -1
			}
			// 선행 감소
			{
				int i{ 0 };
				//--i;
				int k{ --i }; // k: -1, i: -1
			}
		}

		// 사칙연산 축약 표현
		{
			int i{ 1 };
			int k{ 2 };

			// i = i + k; // 1 + 2 -> 3
			i += k; // 1 + 2 -> 3
			i += 2; // 3 + 2 -> 5

			i -= 2; // 5 - 2 = 3

			i *= 2; // 3 * 2 = 6
			i /= 2; // 6 / 2 = 3
			i %= 2; // 3 % 2 = 몫 1 나머지 1 <<
		}

		// 비트 단위 연산   * and, or는 중요
		{
			// AND 연산
			{
				// 둘 다 1이면 결과가 1
				// 하나라도 0이면 결과가 0
				//
				// 0010 = 2
				// 1111 = 15
				// ------ AND
				// 0010 = 2
				char c1 = 0b0010;
				char c2 = 0b1111;
				char c3 = c1 & c2; // 2  & 문자가 AND 연산 문자
			}
			// OR 연산
			{
				// 둘중에 하나라도 1이면 결과가 1
				// 둘다 0이면 결과가 0
				//
				// 0010      -> 2
				// 1110      -> 14
				// ------- OR
				// 1110      -> 14
				char c1 = 0b0010;
				char c2 = 0b1110;
				char c3 = c1 | c2; // -> 14   or 문자는 shift + 원화문자
			}

			// XOR 연산 (exclusive or)
			{
				// 서로 다르면 결과가 1
				// 서로 같으면 결과가 0
				//
				// 0010
				// 1111
				// ------- XOR
				// 1101

				char c1 = 0b0010;
				char c2 = 0b1111;
				char c3 = c1 ^ c2; // 13

				// 1101
				// 0010
				// ------- XOR
				// 1111
				c3 = c3 ^ c1;
				c3 = c3 ^ c1;
				c3 = c3 ^ c1;
				c3 = c3 ^ c1;
				c3 = c3 ^ c1;
			}
			// 비트 이동(shift) 연산
			{
				// 왼쪽으로 비트 이동
				{
					// 0000 0001
					// 왼쪽으로 한 칸 이동
					// 0000 0010
					unsigned char C0 = 5;       // 0000 0101 : 5
					unsigned char C1 = C0 << 1; // 0000 1010 : 8 + 2 = 10
					unsigned char C2 = C0 << 2; // 0001 0100 : 20
					unsigned char C3 = C0 << 3; // 0010 1000 : 40
					unsigned char C4 = C0 << 4; // 0101 0000 : 80
					unsigned char C5 = C0 << 5; // 1010 0000 : 160
					unsigned char C6 = C0 << 6; // 0100 0000 : 64  <- 1이 한 칸 밀리면서 날아감
					unsigned char C7 = C0 << 7; // 1000 0000 : 128
					unsigned char C8 = C0 << 8; // 0000 0000 : 0
				}
				// 오른쪽으로 비트 이동
				{
					unsigned char C0 = 80;      // 0101 0000 : 80
					unsigned char C1 = C0 >> 1; // 0010 1000 : 40
					unsigned char C2 = C0 >> 2; // 0001 0100 : 20
					unsigned char C3 = C0 >> 3; // 0000 1010 : 10
					unsigned char C4 = C0 >> 4; // 0000 0101 : 5
					unsigned char C5 = C0 >> 5; // 0000 0010 : 2
					unsigned char C6 = C0 >> 6; // 0000 0001 : 1
					unsigned char C7 = C0 >> 7; // 0000 0000 : 0
					unsigned char C8 = C0 >> 8; // 0000 0000 : 0
				}
				// 음수의 경우 비트 이동이 조금 다르게 동작
				{
					// MSB(Most Signnificant Bit) '1'111 1111
					char C0 = -1;       // 1111 1111 : -1 
					{
						// bit Shift : CPU마다 다르다 (Intel, AMD) -> ( ASM )
						// ms에서 제공하는 방식 (컴파일러 MS)
						// MSB가 Sign역할
						// >> MSB로 계속 채워 넣는다.
						// 1111 1111 -> -1 
						//              -1 / 2  -> -1 -1 -1 -1
						// 1000 0000 -127
						//            >> 1 : -63 (1100 0000)
						//            >> 1 : -31 (1110 0000)
						//            >> ...1 : -1 (1111 1111)


						char C1 = C0 >> 1; // 1111 1111 : -1
						char C1_ = C1 >> 1; // 1111 1111 : -1

					}
					{
						char C1 = C0 << 1; // 1111 1110 : -2
						char C2 = C0 << 2; // 1111 1100 : -4
						char C7 = C0 << 7; // 1000 0000 : -128
						char C8 = C0 << 8; // 0000 0000 : 0
					}
				}
			}
		}


		// 삼항 연산자(tematy operator) / 조건 연산자
		{
			int i = 0;

			//      (조건문) ? 참일때 : 거짓일때
			//  조건을 만족하면 : 기준으로 왼 아니면 오른쪽

			int k1 = (i == 0) ? 10 : -10;
			int k2 = (i != 0) ? 10 : -10;
		}

		// 연산자 우선순위
		{
			int i1 = 10 - 5 * 5; // 10 - 25 = -15
			int i2 = (10 - 5) * 5; // 5 * 5 = 25
		}

	}
#pragma endregion
#pragma region 06. 열거형(enum; enumerated type; 이넘)*
	{
		{
			const int Iron = 0;
			const int Bronze = 1;
			const int Silver = 2;
			const int Gold = 3;

			int MyTier = Gold;
			if (MyTier == Gold)
			{
				std::cout << "골드 티어 입니다.\n";
			}
		}
		{
			enum class ETier : unsigned char
			{
				Iron,
				Bronze, /*= 10*/
				Silver,
				Gold,
			};

			unsigned char MyTier = (unsigned char)ETier::Gold;
			ETier MyTier2 = ETier::Silver;
			ETier MyTier3 = (ETier)3; // ETier::Gold
			if (MyTier2 == ETier::Silver)
			{
				std::cout << "실버 티어 입니다.\n";
			}
			if (MyTier2 == ETier::Gold)
			{
				std::cout << "골드 티어 입니다.\n";
			}
		}
	}
#pragma endregion
#pragma region 07. 구조체(struct) 중요!
	{
		enum class ETier : unsigned char
		{
			None,
			Iron,
			Bronze,
			Silver,
			Gold,
		};

		int HP = 10;
		int MP = 20;
		ETier Tier = ETier::None;
		// HP = 20;

		struct FPlayer
		{
			int HP = 10;
			int MP = 20;
			ETier Tier = ETier::None;
			// 3Byte padding  int 가 4Byte 이기 때문에 남음 위에서 ETier 는 unsigned char 라고 했기 때문에 1Byte
		};

		// FPlayer: 구조체 타입 (구조체: 데이터를 묶어둠)
		// Player: 인스턴스(instance; 실체화된 사례) (메모리에 만들어진 것)
		FPlayer Player{ .MP = 100,.Tier = ETier::Gold };
		FPlayer Player2;
		Player2.HP = 200;
		Player2.MP = 300;
		Player2.Tier = ETier::Iron;

		std::cout << "[Player Info]\n";
		std::cout << "HP: " << Player2.HP << ", MP: " << Player2.MP << ", Tier: " << (int)Player2.Tier << std::endl;
		std::cout << std::format("HP: {}, MP: {}, Tier: {}\n", Player2.HP, Player2.MP, (int)Player2.Tier);
#pragma pack(push, 1)
		struct FPadding // 프라그마 팩을 사용할 때는 네트워크 전송할 때, 읽기 쓰기가 필요 없기 때문.
		{
			char C;
			// 3Byte padding이 숨겨져 있다 
			// 지금 가장 큰 기본 자료형 크기가 4Byte라서 4Byte padding 이 잡힘

			int l;

			char C1;
			// 3Byte padding이 잡힌다.
			// 이런 상황을 피하려면 padding을 고려해서 C1 변수를 C아래쪽으로 옮겨야
			// 낭비되는 byte 를 줄일 수 있다.

		};
#pragma pack(pop) // 다시 보기

		/*struct  FPadding2
		{
			char C1;
			int l;
		}*/

		// 64bit(8Byte) 환경에서 한번에 접근해서 연산할 수 있는 최대 단위가 8Byte
		// padding을 비활성화 해서 다음과 같은 경우
		// char / double (9Byte)
		// [00] / [ 00 00 00 00 00 00 00 00 ]
		// [00] / [ 00 00 00 00 00 00 00 ] // [ 00 ] // double 을 읽으려면 2번 접근해야됨

		// padding 을 넣게되면
		// [00] 00 00 00 00 00 00 00 / [00 00 00 00 00 00 00 00]

		// double에 값을 쓰거나 읽으려고 했을때 padding이 잡혀있지 않으면
		// 2번 접근해야 하는 상황이 발생할 수 있다
		// 그렇기 때문에 속도 저하 가능성이 있음.

	}
#pragma endregion
#pragma region 08. 조건문(if / switch) 중요
	{
		int  V = 0;
		if (V == 0)
		{
			std::cout << "V == 0\n";
		}

		int V2 = 0;
		// std::cin >> V2;
		if (V2 == 100)
		{
			std::cout << "V2 == 100\n";
		}
		else if (V2 == 70)
		{
			std::cout << "V2 == 70\n";
		}
		else if (V2 == 50)
		{
			std::cout << "V2 == 50\n";
		}
		else if (V2 == 60)
		{
			std::cout << "V2 == 60\n";
		}
		else
		{
			std::cout << std::format("V2 : {}\n", V2);
		}
	}

	// switch
	{
		int V2 = 0;
		std::cin >> V2;
		switch (V2)
		{
		case 100:
			std::cout << "V2 == 100\n";
			break;
		case 50:
			std::cout << "V2 == 50\n";
			break;
		default: // if의 else 
			std::cout << "defalte\n";
			break;
		}

		enum class ETier : unsigned char
		{
			None,
			Iron,
			Bronze,
			Silver,
			Gold,
		};
		struct FPlayer
		{
			int HP = 10;
			int MP = 10;
			ETier Tier = ETier::None;
		};
		FPlayer Player{ .MP = 100,.Tier = ETier::Gold };

		std::cout << "[Player Info]\n";
		std::cout << std::format("HP: {}, MP: {},", Player.HP, Player.MP);
		switch (Player.Tier)
		{
		case ETier::None:
			std::cout << "ETier::None";
			break;
		case ETier::Iron:
			std::cout << "ETier::Iron";
			break;
		case ETier::Silver:
			std::cout << "ETier::Silver";
			break;
		case ETier::Gold:
			std::cout << "ETier::Gold";
			break;
		default:
			break;

		}
		std::cout << std::endl;

		switch (Player.Tier)
		{
		case ETier::None:
			std::cout << "ETier::None";
			break;
		case ETier::Iron:
		case ETier::Bronze:
		case ETier::Silver:
			std::cout << "Iron or Bronze or Silver";
			break;
		case ETier::Gold:
			std::cout << "ETier::Gold";
			break;
		default:
			break;
		}
		std::cout << std::endl;

		if (Player.Tier == ETier::None)
		{
			std::cout << "ETier::None";
		}

		else if (Player.Tier == ETier::Iron || Player.Tier == ETier::Bronze || Player.Tier == ETier::Silver)
		{
			std::cout << "Iron or Bronze or Silver";
		}

		else if (Player.Tier == ETier::Gold)
		{
			std::cout << "ETier::Gold";
		}
		std::cout << std::endl;
	}

#pragma endregion

#pragma region 09. 논리 연산자
	{
		// !: 논리 부정
		if (!false) // !false == true
		{
			std::cout << "!false\n";
		}

		// 논리곱 (AND)
		// && : 양쪽 조건이 모두 참인경우 -> ture
		//      하나라도 거짓인 경우 -> false
		int a = 10;
		int b = 20;
		// 1. a == 10 ? true
		// 2. b == 10 ? false
		// if(true && false) -> false
		if (a == 10 && b == 10)
		{
			std::cout << "a == 10 && b == 10\n";
		}

		// 1. a == 10 ? true
		// 2. b == 20 ? true
		// if(true && true) => true
		if (a == 10 && b == 20)
		{
			std::cout << "a == 10 && b == 20\n";
		}

		int c = 30;
		// 1. a == 10? true
		// 2. b == 20? true
		// 3. c == 20? false
		// if(true && true && false) -> false
		if (a == 10 && b == 20 && c == 20);
		{
			std::cout << "a == 10 && b == 20 && c == 20\n";
		}

		// int a = 10;
		// int b = 20;
		// 논리합(OR)      and 와 or 많이 씀.
		// 1. a == 10? true
		// if(true) -> true
		if (a == 10 || b == 10)
		{
			std::cout << "a == 10 || b == 10";
		}

		// 1. b == 10 ? false
		// 2. a == 10 ? true
		// if(false || true) -> true
		if (b == 10 || a == 10)
		{
			std::cout << "a == 10 || b == 10\n";
		}

		// 1. b == 50 ? false
		// 2. a == 60 ? false
		// if(false || false) -> false
		if (b == 50 || a == 60)
		{
			std::cout << "b == 50 || a == 60\n";
		}

		if (FirstFalse())
		{
			std::cout << "FirstTrue\n";
		}
		else
		{
			std::cout << "FirstTrue\n";
		}

		std::cout << "[Test]\n";
		// 1. FirstTrue -> true 함수 내부 진행은 F11 한 줄씩 그냥 진행은 F10
		if (FirstTrue() || FirstFalse())
		{
			std::cout << "FirstTrue\n";
		}
		std::cout << "[Test2]\n";
		if (FirstTrue() && FirstTrue())
		{
			std::cout << "FirstTrue\n";
		}

		// 1. FirstFalse -> false
		// 2. FirstTrue -> true
		// if(false || true) -> true
		if (FirstFalse() || FirstTrue())
		{
			std::cout << "FirstTrue\n";
		}

		const bool bFirst = FirstTrue();
		const bool bSecond = FirstFalse();
		if (bFirst || bSecond)
		{
			std::cout << "true\n";
		}


	}
#pragma endregion
#pragma region 10. 함수(function) 매우 중요
	{
		// 규모가 큰 프로그램에서 모든 코드를 main 안에 담게 되면
		// 관리적인 측면에서 힘들 것 같습니다.
		// 코드 가독성(읽기 쉬운 정도)를 높히려면 코드를 간결하고 명확한
		// 함수 단위로 나누는 것이 좋겠습니다.

		// C++에서 함수를 사용하려면 먼저 함수 선언을 해야합니다
		// 반환타입 함수이름 (입력 파라미터(옵션; 있어도 되고 없어도됨))
		// void    FunctionName (int a, int b)

		// 디버거가 붙어 있는 상황에서 F11을 눌러서 함수 내부로
		// 진입할 수 있다.

		// 함수도 시작 주소가 있습니다.
		// 함수를 호출한다는건
		// >> 돌아올 다음주소를 백업 해두고
		// >> 호출할 함수의 주소로 이동
		// >> 함수 수행
		// >> 리턴을 만나면 백업해둔 주소로 이동
		FunctionName(10, 20);

		// 이 함수를 호출하는 위치 기준으로 이 라인보다 위에 함수가
		// 있다는 것을 알려주지 않으면 함수를 찾을 수 없습니다.


		// 콜링 컨벤션(Calling Conventions)
		// 함수를 호출하는 방식
		// __cdecl, __stdcall, __thiscall, __fastcall

		int Result = AddFunction(10, 20);

		// 파라미터를 던지는 경우 특정 레지스터(메모리)에 값을 백업 했다가
		// 함수 내부로 진입해서 그 레지스터(메모리)에서 다른 메모리로 값을 복원한다
		// 추가적으로 함수로 이동하는 과정 (비용) 추가적으로 발생
		// 함수 호출의 오버해드라고 표현 합니다.

		int a = 10, b = 20;

		// int InA = a;
		// int InB = b;
		int Result2 = AddFunction(a, b);
		double Result3 = AddFunction(10.34, 3.14);

		// 재귀 함수 호출이 많이 발생하는 경우  * 재귀 문제 풀어보려면 c++ 하노이의 탑
		// Debug 설정일 때 함수 호출 오버해드로 인해서
		// 한 번의 함수 호출로 구현해둔 함수에 비해 느릴 수 있다.
		unsigned long long Result4 = Factorial(10);
		std::cout << Result4 << std::endl;


	}

#pragma endregion
#pragma region 11. Bit flag
	{
		unsigned char Property1 = EPropertyFlags::EProperty1;
		HasFlags(Property1);
		unsigned char Property3 = EPropertyFlags::EProperty3;
		HasFlags(Property3);

		// 0000 0001
		// 0000 0100
		// ---------- OR
		// 0000 0101
		unsigned char Property13 = EPropertyFlags::EProperty1 | EPropertyFlags::EProperty3;
		HasFlags(Property13);

		unsigned char Property135 = Property13;
		//Property135 = Property135 | EPropertyFlags::EProperty5;
		Property135 |= EPropertyFlags::EProperty5;
		HasFlags(Property135);

		unsigned char Property35 = Property135; // 1만 빼는것

		// EPropertyFlags::EProperty1: 0000 0000
		// ~EPropertyFlags::EProperty1: 1111 1110   ~은 !이랑 똑같음.
		// 0001 0101
		// 1111 1110
		// ---------- AND
		// 0001 0100

		Property35 = Property35 & ~EPropertyFlags::EProperty1;
		HasFlags(Property35);

		// 0000 0010
		// 0000 1000
		// ---------- OR
		// 0000 1010
		unsigned char Toggle = EProperty2 | EProperty4;
		HasFlags(Toggle); // 켰다 껐다

		// 0000 1010 (2, 4)
		// 0000 1000 (4)
		// --------- XOR (같으면 0 다르면 1)
		// 0000 0010 (2)
		Toggle = Toggle ^ EProperty4;
		HasFlags(Toggle);
		// 0000 0010 (2)
		// 0000 1000 (4)
		// ---------- XOR
		// 0000 1010 (2,4)
		Toggle = Toggle ^ EProperty4;
		HasFlags(Toggle);

		unsigned char Flags = EPropertyFlags::ENone;
		// 지정
		Flags = EProperty1;

		// 켜기
		Flags |= EProperty2;

		// 끄기
		Flags &= ~EProperty2;

		// 토글 (껏다 켰다)
		Flags ^= EProperty3; // 켜짐 
		Flags ^= EProperty3; // 꺼짐
		Flags ^= EProperty3; // 켜짐
		Flags ^= EProperty3; // 꺼짐

	}
#pragma endregion
#pragma region 12. 배열 (array)
	{
		int a{}, b{}, c{};
		a = 1;
		b = 2;
		c = 3;

		// 1차원 배열
		{
			// int 데이터 5개(count)를 만들겠다
			int Array[5]{ 5,4,1,8,3 };

			// 0번 index(또는 원소)에 1을 넣겠다
			// Array의 시작 주소로 부터 타입의 크기(int) * 인덱스만큼 건너뛴 값을 편집한다
			// Array 시작주소 + TypeSize(int) * index
			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;

			int Size = sizeof(int);   // 4Byte
			int Size2 = sizeof(Size); // 4Byte
			int ArraySize = sizeof(Array); // 20Byte : int(4) * 갯수
			int ArrayElemSize = sizeof(Array[0]); // 4Byte
			int ArrayElemCount = ArraySize / ArrayElemSize; // 20 / 4 = 5
		}
		// 2차원 배열
		{
			// Array[0][0] Array[0][1] Array[1][0] Array[1][1] Array[1][2]
			int Array[2][3]{};
			Array[0][0] = 0;
			Array[0][1] = 1;
			Array[0][2] = 2;
			Array[1][0] = 3;
			Array[1][1] = 4;
			Array[1][2] = 5;

		}

		// 1차원 배열 (std::array)
		{

			std::array<int, 5> Array{ 0,5,3,1,5 }; // include <array>
			Array[0] = 0;
			Array[1] = 1;
			Array[2] = 2;
			Array[3] = 3;
			Array[4] = 4;

			// typedef unsigned __int64 size_t;
			// typerdef는 왼쪽에 있는 타입을 오른쪽에 있는 이름으로 바꿈
			size_t Size = Array.size();
		}
	}
#pragma endregion
#pragma region 13. 반복문(loop) 중요2
	{
		// while
		{
			int i = 0;
			while (i < 5)
			{
				std::cout << std::format("i: {}\n", i);
				++i;

				if (i == 3)
				{
					std::cout << "i가 3일때 탈출!\n";
					break;
				}
			}

		}

		// do while      한 번은 거짓이여도 실행함.
		{
			int i{ 30 };
			do
			{
				std::cout << "Test\n";
			} while (i < 5);
		}

		// for
		{
			// 초기화; 판별식; for문이 끝나고 실행될 코드
			for (int i = 0, j = 5; i < 5; ++i, ++j, FirstTrue())
			{
				std::cout << std::format("i:{},j:{}\n", i, j);
			}
		}   // int i = 10;

		const int Size = 6;
		int Array[Size]{};
		for (int i = 0; i < Size; ++i)
		{
			// Array[0] = 0;
			// Array[1] = 1;
			Array[i] = i;
		}

		// 범위기반 for(range based for)
		for (int i : Array)
		{
			std::cout << i << std::endl;
		}

		std::array<int, Size> StdArray{};
		size_t ArraySize = StdArray.size();
		for (size_t i = 0; i < ArraySize; ++i)
		{

			StdArray[i] = i;
		}

		for (int i : StdArray)
		{
			std::cout << std::format("i값은:{}\n", i);
		}

		// CTAD(class template argument deduction: 클래스 템플릿 인수 추론
		// C++20
		for (std::array Array2{ 1,2,3 }; int i : Array2)
		{
			std::cout << std::format("i값은: {}\n", i);
		}
		// Array2;

		// 추가적으로, if 도 조건문 이전에 int i = 0; 와 같이 초기화 구문을 넣을 수 있다.
		if (int i = 0; i < 10)
		{

		}
	}
#pragma endregion
#pragma region 14. 포인터 동적 할당(pointer매우중요, dynamic allocation) + 레퍼런스 
	{   // 배열, 포인터, 이해 못하면 다음것들이 진행이 안됨.
		// 메모리 할당과 이를 관리하는 것은 C++프로그래밍에서 문제가 발생하기 쉬움
		// 품질이 뛰어난 C++프로그램을 작성하기 위해서는 메모리 내부 작동 방식을 이해하고 있어야 함
		// 이번 시간에는 동적 메모리를 다루는 과정에서 어떤 위험에 빠질 수 있는지 이 상황을
		// 해결하거나 방지하는 방법을 알아보자.

		// low-lever(저수준; 낮은수준) 메모리 연산 방법은 new, new[], delete, delete[]
		// 또는 C스타일의 malloc(memory allocation), free라는 함수를 사용하는 방법이 있다
		// 요즘 와서는 로우레벨 메모리 연산을 최대한 피하는 추세
		// ex) 표준 라이브러리에서 제공하는 vector라는 컨테이너(동적 배열)이 있는데
		// 이를 사용하면 필요할 때 메모리를 늘리거나 줄일 수 있다
		// 또는 동적으로 할당한 메모리를 사용하지 않으면 자동으로 해제해주는 shard_ptr 등의
		// 스마트 포인터를 사용하기도 한다

		// 동적 메모리를 이용하면 컴파일 시간에 크기를 확정할 수 없는 데이터를 다룰 수 있다
		{
			// 지역변수는 시작과 끝 스코프({}) 내부에서 선언되는 변수를 의미합니다.

			// 유저 영역의 메모리 공간은 크게 4구획을 나누어 져있다고 생각하시면 편합니다.
			// [코드 영역]   : 소스코드가 기계어로 변환되어 실제 로직을 수행하는 코드 정보
			// [데이터 영역] : 전역변수, static변수 등
			// [Heap]        : 동적 할당 (아직 배우지 않음)
			// [Stack]       : 지역 변수


			// [프로그램의 메모리 구조]
			// ---------------- 소스 코드 영역 -------------
			// ... 여러분 또는 누군가가 작성해둔 코드가 어셈으로 기록되어 있다
			// -----------------데이터 영역 ----------------
			// ... 전역변수, static(정적) 변수
			// ----------------- Heap 영역 -----------------
			// ... 동적 할당 (실행 중에 메모리 요청을 하는 것)
			// ..
			// ..
			// 
			// 
			// .. 
			// // 지역 변수, 함수 호출 이후 복귀 주소 등
			// --------------- Stack 영역 ------------------

			// 실행시간(런타임)에 동적으로 메모리 공간이 필요한 경우 OS
			// 에 메모리를 요청해야 하는데, 이런 과정에서 커널에 요청할 필요 o
			// 커널은 OS 중 항상 메모리에 올라가 있는 운영체제의 핵심으로, 하드웨어와 응용프로그램
			// 사이에서 인터페이스 역할을 제공합니다.
			// 커널에 요청하는 경우 이를 system call 이라고 합니다. (메모리 할당을 할때마다 system call이 발생
			// 하지는 않을 수 있다)
			// 이 system call은 유저 영역과 커널 영역을 넘나드는 호출로서 상당한 비용을 지불하게 된다
		}
		{
			// 64비트 환경에서는 포인터의 크기가 8Byte
			// 32비트 환경에서는 포인터의 크기가 4Byte
			// [Stack}
			// [0xfff] Pointer(8Byte;64bit 기준) = nullptr

			// Pointer 변수는 주소를 들고 있을 것이다.
			// 그리고, 그 주소로 접근하면 int 변수가 있을 것이다.
			int* Pointer{ nullptr }; // 실제 값은 0, 프로그래머를 위해서 0을
			// 쓰는 것 보다 nullptr 을 넣어주면 더 명확하게 의미 전달 가능

			// 포인터의 크기는 플랫폼 bit수에 대응해서 변경됩니다
			// 32bit라면 최대 표현 가능한 주소가 unsigned int 범위에 해당
			// 즉 4byte 만 있으면 모든 32bit 주소를 표한 가능
			// 64bit 라면 총 8Byte로 모든 주소를 표현 할 수 있다.

			// [Stack]
			// [0xfff..] Size (8Byte; size_t 의 크기가 64bit에서는 8Byte)
			// [0xfff..] Size2
			// int*의 의미는 지금 내가 가지고 있는 주소(*)로 가면 그 값은 int다 
			size_t Size = sizeof(int*); // 이 부분 sizeof 인트포인터의 값을 인트로 해석하겠다 하지만 64비트 환경에서 주소는 8Byte로 표현되니 size = 8

			// char*의 의미는 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~        그 값은 char
			size_t Size2 = sizeof(char*);
		}
		{
			// [Stack]                                     // [Heap]
			// [0xfff...] a(4Byte) = 100
			// [0xfff...] 4Byte padding
			// [0xfff...] Pointer(8Byte) = nullptr
			// [0xfff...] b(4Byte) = 20
			int a = 100;
			int* Pointer{ nullptr }; // 0으로 해도 무관하지만 사용자의 편의를 위해 nullptr
			int	b = 20;

			// [Stack]                                      // [Heap]
			// [0xfff...] a(4Byte) = 100
			// [0xfff...] 4Byte padding
			// [0xfff...] Pointer(8Byte) = 0x100 <---------  [0x100] int [4Byte] = 10            
			// [0xfff...] b(4Byte) = 20

			// &의 의미 : 주소를 불러오겠다
			// new int : 동적할당으로 힙 메모리를 쓰겠다
			// new int[] : 동적할당으로 힙 메모리를 int [] 개 만큼 쓰겠다
			// new int{} : 동적할당으로 힙 메모리의 int 값을 {} 로 초기화 하겠다
			Pointer = new int{ 10 };

			// [Stack]                                      // [Heap]
			// [0xfff...] Pointer(8byte) = 0x100 <---------   [0x100] int[4Byte] = 10 -> 999
			// 이곳에 붙은 포인터 기호는 역참조 연산이라고 이야기 한다
			*Pointer = 999;

			// [Stack]                                      // [Heap]
			// [0xfff...] Pointer(8Byte) = 0x100 <---------   [0x100] int[4Byte] = 999
			// [0xfff...] Read(4Byte) = 999
			int Read = *Pointer;

			// 할당한 메모리를 해제  new 와 delete 는 세트 사용을 했으니 더 사용하지 않을거라고 선언.
			delete Pointer;
			// int Read2 = *Pointer;

			// https://en.wikipedia.org/wiki/Magic_number_(programming)
			{
				// [Stack]                                      // [Heap]
				// [0xffffff0] a(4Byte) = 100
				// ...
				// [0xfff...] Pointer2(8Byte) = 0xffffff0;
				int* Ponter2 = &a;
				std::cout << std::format("Pointer2: {:X} &a: {:X}, *Pointer2: {}, a: {}\n", (size_t)Ponter2, (size_t)&a, *Ponter2, a);
				*Ponter2 = 1234;

				std::cout << std::format("Pointer2: {:X} &a: {:X}, *Pointer2: {}, a: {}\n", (size_t)Ponter2, (size_t)&a, *Ponter2, a);
				// int* Ponter3 = (int*)0xFFFFFFFFFFF;

			}
		}
		{   // [Stack]                                      // [Heap]
			// [0xfff...] Pointer(8Byte) = 0x100
			int* Pointer{ nullptr };

			// [Stack]                                      // [Heap]
			// [0xfff...] Pointer(8Byte) = 0x100 <--------     [0x100] int [4Byte] = 10
			Pointer = new int{ 10 };

			// 할당한 메모리를 해제하지 않고 넘어가는 경우 이를,
			// 메모리 누수(메모리 릭, memory leak)이라고 부릅니다.

			// 동적 할당한 메모리를 다른 주소로 덮어 쓰는 경우에도
			// 원본 주소를 해제할 수 없다.
			// Pointer = (int*)10000;

			delete Pointer;
		}
		{
			// C언어를 배우셨다면 malloc을 사용해서 메모리를 할당 했을 텐데,
			// C++에서도 사용할 수 있습니다.
			// malloc과 new는 큰 차이가 있습니다.
			// 아직 배우지는 않았지만, new와 delete는 초기화 및 struct 또는 class에서
			// 생성자와 소멸자를 호출해주는 역할을 수행합니다.
			// 그러나, malloc은 순수하게 memory 할당만 해줍니다.
			// int*를 new로 동적할당 할때는 초기화를 할 수 있었습니다.
			// 하지만 malloc은 초기화 불가
			int* Pointer = (int*)malloc(sizeof(int));
			*Pointer = 1000;
			free(Pointer);
		}
		{
			// [Stack]                                      // [Heap]
			// [0xfff...] Pointer(8Byte) = 0x100              0x100 [int][int][int][int][int][int]
			int* ArrayPointer = new int[6] {0, 1, 2, 3, 4, 5};
			ArrayPointer[0] = 1000;
			ArrayPointer[1] = 1200;

			// 0x100 + 0 * sizeof(int) = 0x100
			*ArrayPointer = 9999;
			// 0x100 + 1 * sizeof(int) = 0x104
			*(ArrayPointer + 1) = 8888;

			for (int i = 0; i < 6; ++i)
			{
				ArrayPointer[i] = i + 10;

				// Array(int*) + 0    Array + 1      Array + 2         Array + 3
				// [00 00 00 01]    [00 00 00 02]   [00 00 00 03]     [00 00 00 04]
				*(ArrayPointer + i) = i;
			}
			// 1,2,3, 이렇게 주소로부터 상대적으로 떨어진 위치를 말로 표현할때 offset이라고 함

			*((char*)ArrayPointer + 1) = 255;
			*((char*)ArrayPointer + 2) = 255;
			*((char*)ArrayPointer + 3) = 255;
			*((short*)ArrayPointer + 1) = 9999;
			*((__int64*)ArrayPointer + 0) = 9999;
			*((__int64*)ArrayPointer + 1) = 9999;
			delete[] ArrayPointer;

			// 2차원 이상 배열도 동적 할당으로 구현 가능하나,
			// 실무에서 거의 쓰지 않음.
		}
		{
			struct FStruct
			{
				// 생성자: 인스턴스가 만들어질때 호출되는 함수
				// __thiscall: 호출하는 쪽에서 파라미터로 자기자신의 주소를 전달
				FStruct(/*Fstruct* This*/) // this 는 기준을 잡아주는것.
				{
					// this + 0Byte -> Value
					// this + 4Byte -> Value2
					this;
					int a = this->Value;
					int B = this->Value2;
					std::cout << std::format("V: {}, V2: {}\n", this->Value, Value2);

				}
				FStruct(const int InValue)
					// 초기화 순서는 변수를 선언한 순서대로 동작한다
					: /*Value2(Value, */ Value(InValue)/*, Value2(Value)*/
				{
					std::cout << std::format("V: {}, V2: {}\n", Value, Value2);
				}
				// 소멸자: 인스턴스가 소멸되는 시점에 호출되는 함수
				// 컴파일러가 소멸예측 지점 (Stack: 스코프를 벗어나는 지점, Heap: delect를 하는 시점
				// 에 코드에 소멸자를 호출하도록 심어둔다
				~FStruct()
				{

				}
				int Value = 10;
				int Value2 = 20;
			};
			FStruct Struct;// = FStruct();
			FStruct Struct2 = FStruct(100);

			FStruct* StructPointer = new FStruct(12);
			StructPointer->Value = 999;
			int* Test = (int*)StructPointer + 1;
			*Test = 888;
			delete StructPointer;

			{
				// malloc은 요청한 size 만큼 메모리 블록만 할당.
				// new는 요청한 size 만큼 메모리 블럭을 할당 후 초기화(struct 와 같은 경우 생성자 호출)
				FStruct* MallocStruct = (FStruct*)malloc(sizeof(FStruct));

				// free는 해당 메모리 블록을 할당 해제
				// delect와 다르게 소멸자는 호출하지 않는다
				free(MallocStruct);
			}

			// 저수준의 동적할당은 사용빈도가 줄었다고 했지만,
			// 포인터는 사용하지 않는날이 없는 수준

			{
				int Value = 0;
				// Function call, 인자 복사
				// int InValue = Value;
				// Value = InValue;

				Value = CallByValue(Value);

				FParam Param = FParam();
				Param.Value[2] = 1234;
				//FParam InParam = FParam(Param);
				Param = CallByValue(Param);
			}
			{
				int a = 0;
				int* Pointer = &a;
				a = 999;
				// *Pointer = 1234;

				// int* InPointer = Pointer;
				// *InPointer = 1234;
				// *Pointer = 1234;
				CallByPointer(&a);
				CallByPointer(Pointer);

				FParam Param = FParam();
				FParam* ParamPointer = &Param;

				FParam* InPointer = &Param;
				InPointer->Value[0] = 9999;
				InPointer->Value[5] = 5555;
				(*InPointer).Value[0] = 1234;
				CallByPointer(&Param);
				CallByPointer(ParamPointer);
			}
			{
				FParam Param; TestConstructor(&Param);

				FTTest TTest;
				TestConstructor(&TTest);

				int a = 200;
				int b = 400;

				TestConstructor((void*)&a);
			}
			{
				// 레퍼런스, 참조

				// 포인터와 레퍼런스의 차이

				int a = 5;
				int* Pointer = &a; // 대상을 a로 변경
				*Pointer = 100;    // a의 값이 변경됨

				// Pointer는 가리키던 대상을 바꿀 수 있다.
				int b = 999;
				Pointer = &b;     // 대상을 b로 변경
				*Pointer = 1234;  // b의 값이 변경됨

				// 포인터도 레퍼런스와 같이 사용하는법
				int* const PointerLikeReference = &a;
				// PointerLikeReference = &b; // * 오른쪽에 const가 붙으면 가르키던 대상을 바꿀 수 없다
				*PointerLikeReference = 10000;
				const int* ConstPointer = &a; // * 왼쪽에 const가 붙으면 가르키던 대상의 값을 바꿀 수 없다
				// *ConstPointer = 9999;
				ConstPointer = &b;

				const int* const PointerCantChange = &a; // 둘 다 변경 불가
				/*PointerCantChange = &b;
				*PointerCantChange = 1000;*/

				int& Reference = a; // 처음 초기화 시점에 반드시 대상이 와야하며, 이후 변경할 수 없다.
				Reference = b;      // 주소가 바뀌는 것이 아니라, 처음 연동한 a의 값이 b에 있는 값(1234)로 변경
				// Reference = &b;  // 이후 가르키던 주소를 변경할 수 없다.

				int TestValue = 0;
				CallByReference(TestValue);
				CallByPointer(&TestValue);

				FParam Param;
				CallByReference(Param);
			}
			{

				// 매크로로 조건문은 사용 안 하는것을 권장
				int* Pointer = nullptr;
				FunctionWithPointer(Pointer);
				int a = 10;
				FunctionWithPointer(&a);

				if (Pointer == nullptr)
				{
					Pointer = new int{ 5 };
					FunctionWithPointer(Pointer);

					int* PointerB = Pointer;
					SAFE_DELETE(Pointer);
					FunctionWithPointer(Pointer);

					// PointerB는 댕글링 포인터
					// 이미 delete 된 메모리 주소를 들고있는 상황
				}
				{
					int* PointerB = new int{ 5 };
					int& ReferenceB = *PointerB;
					ReferenceB = 999;
					*PointerB = 1234;
					SAFE_DELETE(PointerB);
					FunctionWithReference(ReferenceB);
				}
			}
			{
			}
			{
				int a = 10, b = 20;
				Swap(&a, &b);
			}
			{
				std::array Numbers{ 1,2,3,4,5,6,7,8,9,10 };
				std::vector<int> Odds, Evens;
				SeperateOddsAndEvens(Numbers, Odds, Evens);
			}

		}
	}
#pragma endregion
#pragma region 15. SmartPointer 중요
	{
		using namespace std; // std 안 붙여도됨.
		// unique_ptr
		{
			// unique_ptr 생성 및 역참조
			// 소멸자 호출이 되면서 Heap memory를 delete 한다.
			{
 				unique_ptr<int> Unique = make_unique<int>(100);
				*Unique = 1000;
			}
			// 다른 unique_ptr에 대입을 할 수 없다.
			{
				unique_ptr<int> Unique = make_unique<int>(100);
				*Unique = 1000;
				// unique_ptr<int> Unique2 = Unique; 이게 안됨 
				int* Pointer = Unique.get();
				*Pointer = 999; // Unique 값도 바뀜.
				CallByPointer(Unique.get());
				TestUnique(Unique);
				TestUnique(&Unique);
			
			}






		}








	}
}

















// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
