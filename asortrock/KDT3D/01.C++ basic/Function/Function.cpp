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

unsigned long long Factorial(unsigned char InF)
{
	if (InF == 0)
	{
		return 1;
	}
	return InF * Factorial(InF - 1);
}

void HasFlags(unsigned char InProperty)
{
	std::cout << "HasFlags\n";
	// 0000 0101
	// 0000 0001
	// ---------- AND
	// 0000 0001
	if (InProperty & EPropertyFlags::EProperty1)
	{
		std::cout << "EPropertyFlags::EProperty1\n";
	}
	if (InProperty & EPropertyFlags::EProperty2)
	{
		std::cout << "EPropertyFlags::EProperty2\n";
	}
	if (InProperty & EPropertyFlags::EProperty3)
	{
		std::cout << "EPropertyFlags::EProperty3\n";
	}
	if (InProperty & EPropertyFlags::EProperty4)
	{
		std::cout << "EPropertyFlags::EProperty4\n";
	}
	if (InProperty & EPropertyFlags::EProperty5)
	{
		std::cout << "EPropertyFlags::EProperty5\n";
	}
	if (InProperty & EPropertyFlags::EProperty6)
	{
		std::cout << "EPropertyFlags::EProperty6\n";
	}
	if (InProperty & EPropertyFlags::EProperty7)
	{
		std::cout << "EPropertyFlags::EProperty7\n";
	}
	if (InProperty & EPropertyFlags::EProperty8)
	{
		std::cout << "EPropertyFlags::EProperty8\n";
	}


}

int CallByValue(int InValue)
{
	InValue = 10;
	return InValue;
}

FParam CallByValue(FParam InParam)
{
	InParam.Value[0] = 9999;
	InParam.Value[5] = 5555;
	return InParam;
}

FParam::FParam()
{
	std::cout << "FParam\n";
}

FParam::~FParam()
{
	std::cout << "~FParam\n";
}

void CallByPointer(int* InPointer)
{
	*InPointer = 1234;
}

void CallByReference(int& InReference)
{
	InReference = 1234;
}

void CallByPointer(FParam* InPointer)
{
	InPointer->Value[0] = 9999;
	InPointer->Value[5] = 5555;

	(*InPointer).Value[2] = 2222;
}

void CallByReference(FParam& InReference)
{
	InReference.Value[0] = 9999;
	InReference.Value[5] = 5555;

	InReference.Value[2] = 2222;
}

void TestUnique(std::unique_ptr<int>& OutUnique) // �� �κ� �� �κ��� �����Ͷ� �׷���?
{
	*OutUnique += 100;
}

void TestUnique(std::unique_ptr<int>* OutUnique)
{
	*(*OutUnique) += 100;
}
void TestShared(std::shared_ptr<int>& OutShared)
{
	int* Pointer = OutShared.get();
	*OutShared += 100;
}
void TestWeak(std::weak_ptr<FParam> OutWeak)
{
	if (OutWeak.expired())
	{
		// _ASSERT(false);
		return;
	}

	std::shared_ptr<FParam> Shared = OutWeak.lock();
	FParam* Sharedd = Shared.get();
	long Count = Shared.use_count();
	Sharedd->A;
	Shared->A;
	OutWeak.lock()->A += 1234;
}
#include <cassert>
void FunctionWithPointer(int* OutPointer)
{
	// debug ����� �� �����ϴ� assert��
	// ���α׷����� ����� �Ǽ��� Ž���ϱ� ���ؼ� ���

	// if (OutPointer == nullptr) // ���� nullptr �̶��
	if (!OutPointer) // 0 -> !0 -> 1
	{
		// �ǽ� �����Ҷ� assert�� �����ؼ� �ּ� ó��
		// _ASSERT(false);
		return;
	}

	*OutPointer += 100;
}

void FunctionWithReference(int& OutPointer)
{
	OutPointer += 100;
}

//void swap(int& inoutfirst, int& inoutsecond)
//{
//	// temp = inoutfirst(20)
//	const int temp = inoutfirst;
//
//	// inoutfirst = 10(b);
//	inoutfirst = inoutsecond;
//
//	// inoutsecond = 20(temp; a)
//	inoutsecond = temp;
//}

void SeperateOddsAndEvens(const std::array<int, 10>& const InNumbers,
	std::vector<int>& const OutOdds, std::vector<int>& const OutEvens)
{
	for (int Value : InNumbers)
	{
		std::cout << Value << std::endl;

		// Ȧ�� ����
		// 1 / 2 : �� :0 ������:1 => Ȧ��
		// 2 / 2 : �� :1 ������:0 => ¦��
		if (Value % 2 == 1) //Ȧ��
		{
			OutOdds.push_back(Value);
		}
		else if (Value % 2 == 0) // ¦��
		{
			OutEvens.push_back(Value);
		}
		else
		{
			// Ȥ�� ���� ������ �ѹ� �� ���߰ڴ�,,,
			_ASSERT(false);
		}
	}
}

void Swap(int* Pointer, int* Pointer2)
{	
	int temp = *Pointer;
	*Pointer = *Pointer2;
	*Pointer2 = temp;
}

void SharedTestFunciton(std::shared_ptr<FSharedTest> InShared)
{
	InShared->A = 0;
}

FOddsAndEvens SeperateOddsAndEvens(const std::array<int, 10>& const InNumbers)
{
	// RVO
	std::vector<int> Odds, Evens;
	
		for (int Value : InNumbers)
		{
			std::cout << Value << std::endl;

			// Ȧ�� ����
			// 1 / 2 : �� :0 ������:1 => Ȧ��
			// 2 / 2 : �� :1 ������:0 => ¦��
			if (Value % 2 == 1) //Ȧ��
			{
				Odds.push_back(Value);
			}
			else if (Value % 2 == 0) // ¦��
			{
				Evens.push_back(Value);
			}
			else
			{
				// Ȥ�� ���� ������ �ѹ� �� ���߰ڴ�,,,
				_ASSERT(false);
			}
		}
		return FOddsAndEvens(Odds, Evens);
}

FOddsAndEvens SeperateOddsAndEvens2(const std::array<int, 10>& const InNumbers)
{
	// NRVO

	FOddsAndEvens OddsAndEvens;

	for (int Value : InNumbers)
	{
		std::cout << Value << std::endl;

		// Ȧ�� ����
		// 1 / 2 : �� :0 ������:1 => Ȧ��
		// 2 / 2 : �� :1 ������:0 => ¦��
		if (Value % 2 == 1) //Ȧ��
		{
			OddsAndEvens.Odds.push_back(Value);
		}
		else if (Value % 2 == 0) // ¦��
		{
			OddsAndEvens.Evens.push_back(Value);
		}
		else
		{
			// Ȥ�� ���� ������ �ѹ� �� ���߰ڴ�,,,
			_ASSERT(false);
		}
	}
	return OddsAndEvens;
}

