/*
================================================================================================================================================================================================
문제
커다란 공연장을 빌려서 록 페스티벌을 개최하려고 합니다.
이 페스티벌은 여러 날 동안 진행되며, 하루에 한 팀의 밴드가 공연장에서 콘서트를 하게 됩니다.
전체 밴드를 몇 팀 섭외할 지는 아직 결정하지 않았지만, 페스티벌의 간판 스타인 L개의 팀은 이미 섭외가 끝난 상태입니다.
따라서 페스티벌은 최소 L일 이상 진행하게 됩니다.
이번에 사용할 공연장은 하루 빌리는 데 드는 비용이 매일 매일 다릅니다.
때문에 공연 일정을 잘 정해서 공연장 대여 비용을 줄이려고 합니다.
앞으로 N일간의 공연장 대여 비용을 알고 있다고 합시다.
이 중 L일 이상을 연속해서 대여하되, 공연장을 하루 빌리는 데 드는 평균 비용을 최소화하려면 어떻게 공연장을 빌려야 할까요 ?
예를 들어 앞으로 6일간 공연장을 빌리는 데 드는 비용이 각{ 3, 1, 2, 3, 1, 2 }라고 합시다.
이미 세 팀을 섭외했다고 하면, 3일 대신 4일 동안 공연을 진행해서 평균 비용을 더 저렴하게 할 수 있습니다. 
3일 동안의 평균 대여 비용을 최소화하는 방법은 2일째부터 4일째까지 공연장을 대여하는 것인데, 이 때 하루 평균(1 + 2 + 3) / 3 = 2의 비용이 듭니다.
반면 2일째부터 5일째까지 공연장을 대여하면 평균 비용이(1 + 2 + 3 + 1) / 4 = 7 / 4밖에 되지 않습니다.
================================================================================================================================================================================================
입력
입력의 첫 줄에는 테스트 케이스의 수 C(C ≤ 100)가 주어집니다.
각 테스트 케이스의 첫 줄에는 공연장을 대여할 수 있는 날들의 수 N(1 ≤ N ≤ 1000)과 이미 섭외한 공연 팀의 수 L(1 ≤ L ≤ 1000, L ≤ N)이 주어집니다.
그 다음 줄에는 N개의 숫자로 공연장 대여 비용이 날짜별로 주어집니다.모든 비용은 100 이하의 자연수입니다.
================================================================================================================================================================================================
출력
입력에 주어지는 각 테스트 케이스마다 한 줄에 최소의 평균 대여 비용을 출력합니다.
10 - 7 이하의 절대 / 상대 오차가 있는 답은 정답 처리됩니다.
================================================================================================================================================================================================
예제 입력
2
6 3
1 2 3 1 2 3
6 2
1 2 3 1 2 3
================================================================================================================================================================================================
예제 출력
1.75000000000
1.50000000000
================================================================================================================================================================================================
*/
#include <iostream>

using namespace std;

void inputCase()
{
	int N; // 1 <= N <= 1000 날짜의 수
	int L; // 1 <= L <= 1000, L <= N 팀 수

	cin >> N >> L;

	int* cost = new int[N];

	for (int i = 0; i < N; ++i)
		cin >> cost[i];

	double min = 9999;
	for (int i = 0; i < N; ++i)
	{
		int sum = 0;
		int cnt = 0;
		for (int j = i; j < N; ++j)
		{
			sum += cost[j];
			cnt++;
			if (cnt < L)
				continue;
			else
			{
				if ((double)sum / cnt < min)
					min = (double)sum / cnt;
			}
		}
	}
	cout << fixed;
	cout.precision(11);
	cout << min << endl;
}

int main()
{
	int C; // c <= 100
	
	cin >> C;

	for (int i = 0; i < C; ++i)
	{
		inputCase();
	}
}