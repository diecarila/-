// 01-01.Memory.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
// 프로젝트 속성 -> C/C++ -> 일반 -> 추가 포함 디렉터리
// -> $(ProjectDir)Function
#include "Function.h"

// 전역 변수(Data 영역)
int GInt = 1234;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    // _CrtSetBreakAlloc(77);
    
    // ctrl + d 한 줄 복사
    // Stack memory
    {
        // Stack                                    // Heap
        // [4Byte]i1{1}
        // [4Byte]i2{2}
        // [4Byte]i3{3}

        int i1{ 1 }; // 디스어셈블리 보셈
        int i2{ 2 };
        int i3{ 3 };

        i1 = 10;
    }
    // Pointer, 동적할당
    {
        // 64bit 기준으로 포인터는 8바이트고
        // 8바이트인 이유는 64bit 주소를 모두 표기하기 위해서는
        // 2의 64승 값이 필요하다.

        // Stack                                    // Heap
        // [8Byte]Pointer{nullptr(0)}               
        int* Pointer{ nullptr };

        // Stack                                    // Heap
        // [8Byte]Pointer{0xHeapAddress}               [4Byte]*Pointer{444}  qword = 8바이트
        Pointer = new int{ 444 };     

        // Stack                                    // Heap
        // [8Byte]Pointer{0xHeapAddress}               [4Byte]*Pointer{555}  
        *Pointer = 555;
        *(char*)Pointer = 10;

         std::cout << Pointer << std::endl;
         delete Pointer;
         std::cout << Pointer << std::endl;
         Pointer = nullptr;
    }
    // Pointer, 지역 변수
    {
        // Stack                                    // Heap
        // [2Byte]A{0} <--------------------┐
        // [6Byte]Padding                   │
        // [8Byte]Pointer{0xVar A Address} -┘
        short A = 0;
        short* Pointer = &A;
        // Stack                                    // Heap
        // [2Byte]A{234} <------------------┐
        // [6Byte]Padding                   │
        // [8Byte]Pointer{0xVar A Address} -┘
        *Pointer = 234;
    }
    // Pointer, 전역 변수
    {
        // Stack                                    // Data
        // [8Byte]Pointer{0xDataAddress} -------->     [4Byte]GInt{1234} 
        int* Pointer = &GInt;
        *Pointer = 231; 
    }
    // Double Pointer, 동적 할당
    {
        // Stack                                    // Heap
        // [8Byte]Pointer{nullptr(0)}
        int** DoublePointer{ nullptr };

        // Stack                                    // Heap
        // [8Byte]Pointer{0xHeapAddress} -----------> [8Byte]*DoublePointer{trash(0xcdcdcdcd)
        DoublePointer = new int*;

        // Stack                                    // Heap
        // [8Byte]Pointer{0xHeapAddress} -----------> [8Byte]*DoublePointer{0xHeapAddress}
        //                                              ∇
        //                                            [4Byte]**DoublePointer{10}
        *DoublePointer = new int{ 10 };

        **DoublePointer = 1234;

        // Stack                                    // Heap
        // [8Byte]Pointer{0xHeapAddress} -----------> [8Byte]*DoublePointer{0xHeapAddress}
        //                                               ∇
        //                                             delete ! [4Byte]**DoublePointer{10}
        delete* DoublePointer;
        *DoublePointer = nullptr;
    
    }   
    // Double Pointer tip(COM; Component Object Model 공부 해보시면ㄷ ㅗ움이 됨)
    {
        int* Pointer = nullptr;
        /*int* InPointer = Pointer;
        int* InPointer = nullptr;
        InPointer = new int;*/
        //AllocateWrong(Pointer);
        AllocateCorret(&Pointer);
        int* Pointer2 = nullptr;
        AllocateCorret2(Pointer2);
        //Deallocate(Pointer);
        Deallocate(&Pointer);
        Deallocate2(&Pointer2);
        //delete Pointer;


    }
}
