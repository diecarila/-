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

unsigned long long Factorial(int A)
{
	int Value = 1; // 0부터 시작하면 값이 0이 되기 때문
	for (int b = 0; b < A - 1; ++b)  // b가 A-1 인 이유는 곱하는 수임.
	{
	  Value *= (b + 2);
	}
	return Value;
}

unsigned long long Factorial_Re (unsigned char C)
{
	if (unsigned char(C == 1))
	{
		return 1;

	}
	return C * Factorial_Re(C - 1);


}

int Fibonacci(int _iNum)
{
	if (1 == _iNum || 2 == _iNum)
	{
		return 1;
	}

	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue = 0;

	for (int i = 0; i < _iNum - 2; ++i)
	{
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;      // iPrev2 = iValue;    주의
		iPrev2 = iValue;	  // iPrev1 = iPrev2;
	}

	return iValue;

	int Fibonacci_Re(int _iNum);
	{
		if (1 == _iNum || 2 == _iNum)
		{
			return 1;
		}

		return Fibonacci_Re(_iNum - 1) + Fibonacci_Re(_iNum - 2);
	}
}


