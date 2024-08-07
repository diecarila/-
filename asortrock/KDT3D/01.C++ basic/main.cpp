#include <vector>
#include <array>
#include <iostream>

void Swap(int* Pointer, int* Pointer2)
{
	int temp = *Pointer;
	*Pointer = *Pointer2;
	*Pointer2 = temp;
}

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

void main()
{
	int a = 10, b = 20;
	Swap(&a, &b);

	std::array Numbers{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> Odds, Evens;
	SeperateOddsAndEvens(Numbers, Odds, Evens);
}