#include "Function.h"

void AllocateWrong(int* InPointer)
{
	// Memory ´©¼ö!
	InPointer = new int{ 10 };
}

void AllocateCorret(int** InDoublePointer)
{
	*InDoublePointer = new int{ 10 };
}

void AllocateCorret2(int*& InDoublePointer)
{
	InDoublePointer = new int{ 10 };
}

void Deallocate(int* InPointer)
{
	delete InPointer;
	InPointer = nullptr;
}

void Dealloca2(int** InDoublePointer)
{
	delete* InDoublePointer;
	*InDoublePointer = nullptr;
}