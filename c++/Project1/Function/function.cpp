#include "function.h"

int AddFunction(const int A, const int B)
{
	int Result = A + B;
	return Result;
}

double AddFunction(const double A, const double B)
{
	double Result = A + B;
		return Result;
}

unsigned long long Factorial(unsigned char C)
{
	if (unsigned char(C == 0))
	{
		return 1;

	}
	return C * (C - 1);
}


