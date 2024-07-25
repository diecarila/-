#include "Function.h"
#include <iostream>
void FunctionName(int a, int b)
{
	std::cout << a << b << std::endl;
}

int AddFunction(const int InA, const int InB)
{
	const int Resert = InA + InB;
	return Resert;
}

double AddFunction(const double InA, const double InB)
{
	const double Resert = InA + InB;
	return Resert;
}


