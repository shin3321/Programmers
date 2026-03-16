#include <iostream>
#include <vector>



int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	//사야 할 기타 줄 개수
	int cnt;

	//받을 브랜드 개수
	int brandCnt;
	std::cin >> cnt >> brandCnt;

	std::vector<std::vector<int>> array(brandCnt, std::vector<int>(2));
	for (int i = 0; i < brandCnt; ++i)
	{
		std::cin >> array[i][0] >> array[i][1];
	}

	int minGroup = array[0][0];
	int minIndividual = array[0][1];

	//개수가 6개 미만이면 개별 개수 확인하기
	// 개수가 6개면 
	// 1. 묶음 개수 확인하기
	// 2. 개별 묶음 * 6개 계산하고 비교하기


	for (int i = 1; i < brandCnt; ++i)
	{
		//6개 묶음 중 가장 작은 값 구하기
		if (minGroup > array[i][0])
		{
			minGroup = array[i][0];
		}
		 
		//개별 중 가장 작은 값 구하기
		if (minIndividual > array[i][1])
		{
			minIndividual = array[i][1];
		}
	}


	//개수가 6개 초과면 
	// 1. 묶음 개수 확인하기
	// 2. 개별 묶음 * 6개 계산하기
	// 3. 제일 적은 값 구한 후 


	if (cnt <= 6)
	{
		if (minGroup < minIndividual * cnt)
		{
			std::cout << minGroup;
			return minGroup;
		}
		else
		{
			std::cout << minIndividual * cnt;
		}
	}

	//6개 초과일 때
	else
	{
		if (minGroup * ((cnt / 6) + 1) < minIndividual * cnt)
		{
			if (minGroup * ((cnt / 6) + 1) < (minGroup * (cnt / 6)) + (minIndividual * (cnt % 6)))
			{
				std::cout << minGroup * ((cnt / 6) + 1);
			}

			else
			{
				std::cout << (minGroup * (cnt / 6)) + (minIndividual * (cnt % 6));

			}
		}

		else
		{
			if (minIndividual * cnt < (minGroup * (cnt / 6)) + (minIndividual * (cnt % 6)))
			{
				std::cout << minIndividual * cnt;
			}
			else
			{
				std::cout << (minGroup * (cnt / 6)) + (minIndividual * (cnt % 6));

			}
		}
	}
}