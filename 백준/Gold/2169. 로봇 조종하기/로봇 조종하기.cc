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

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);


	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N + 1, vector<int>(M + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> v[i][j];
		}
	}

	vector<vector<int>> dp(N + 1, vector<int>(M + 1, -(1LL << 60)));
	dp[1][1] = v[1][1];

	for (int j = 2; j <= M; j++)
	{
		dp[1][j] = dp[1][j - 1] + v[1][j];
	}

	vector<int> left(M + 1, -(1LL << 60)), right(M + 1, -(1LL << 60));
	for (int i = 2; i <= N; ++i)
	{
		left[1] = dp[i - 1][1] + v[i][1];
		for (int j = 2; j <= M; j++)
		{
			left[j] = max(left[j - 1], dp[i - 1][j]) + v[i][j];
		}

		right[M] = dp[i - 1][M] + v[i][M];
		for (int j = M - 1; j >= 1; --j)
		{
			right[j] = max(right[j + 1], dp[i - 1][j]) + v[i][j];
		}

		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = max(left[j], right[j]);
		}
	}
	cout << dp[N][M];
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}

