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
            // 유니코드
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
