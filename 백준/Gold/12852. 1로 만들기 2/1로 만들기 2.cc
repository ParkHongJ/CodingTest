#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <cmath>
#pragma warning(disable :4996)
using namespace std;
int dp[1000005];
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	/*
	*	X가 3으로 나누어 떨어지면, 3으로 나눈다.
		X가 2로 나누어 떨어지면, 2로 나눈다.
		1을 뺀다.
	*/


	fill(dp, dp + 1000005, 2147483647);

	dp[1] = 0;
	vector<int> answer;
	answer.push_back(N);

	for (int i = 2; i <= N; i++)
	{
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}

		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		dp[i] = min(dp[i], dp[i - 1] + 1);

	}

	cout << dp[N] << '\n';

	while (N != 1)
	{
		vector<int> temp;
		if (N % 2 == 0)
		{
			temp.push_back(N / 2);
		}
		if (N % 3 == 0)
		{
			temp.push_back(N / 3);
		}
		if (N - 1)
		{
			temp.push_back(N - 1);
		}

		//현재 N을 3으로 나눈거, 2로나눈거, -1을 한것중에 최소값을 취한다.
		int minNum = dp[temp[0]];
		int minIdx = temp[0];
		for (int i = 1; i < temp.size(); i++)
		{
			if (minNum > dp[temp[i]])
			{
				//더 작은 최소값
				minNum = dp[temp[i]];
				minIdx = temp[i];
			}
		}
		N = minIdx;
		answer.push_back(minIdx);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
}


int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
