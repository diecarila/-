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


// Input Output Stream 입출력 담당하는 기능
#include <iostream>

int Glnt = 0;



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

        {
            // 유니코드 (다국어 처리가 가능, char는 단일 문자 가능)
            // 2Byte
            wchar_t W{ L'A' };
            wchar_t W2{ L'가' };
            // char C{ L'가' }; 표기 불가
        }

        {
            // 부울타입 : 참과 거짓
            // 1Byte
            bool B0 = true; // 1
            bool B1 = false; // 0
            bool B2 = 0; // false
            bool B3 = 1; // true
            bool B4 = 22; // true
        }
        {
            // 부동소수점 오차

            double Value = 0.0;
            if (Value == 0.0)
            {
                std::cout << "Value 가 0 입니다.\n";
            }

            Value = Value + 0.1;
            Value = Value + 0.1;
            Value = Value + 0.1;

            if (Value == 0.3)
            {
                std::cout << "Value가 0.3 입니다.\n";
            }

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

            /*int Int6 = 999999;
            short Short1 = Int6;*/ // 값이 잘림!, 경고도 발생하지 않는데 주의해서 사용 해야 겠습니다.
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
            bool b6( !false );   // 거짓이 아니다 == 참(true)

            bool b7{ true };     // 참
            bool b8{ !b7 };      // b7이 참인데 b7(참)이 아니다 == 거짓
        }
    
         // [이항]사칙 연산
        {
            int a{ 1 + 2 }; // 1 + 2 = 3
            int b{ a + 3 }; // a + 3 = 6

            int c{ 1 - 2 }; // 1 - 2 = -1
            unsigned int c2{ unsigned int(1 - 2) }; // 1 - 2 = -1 -> unsigned int 엄청 큰 값

            int d{ c * 3 }; // -1 * 3 = -3

            int e{ 10 / 3 }; // 3
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
    
         // 비트 단위 연산
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
                    unsigned char C6 = C0 << 6; // 0100 0000 : 64
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
                        char C1 = C0 >> 1; // 1111 1111 : -1
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
    
    }
#pragma endregion
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
