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
	
	int T;
	cin >> T;
	while (T--)
	{
		long long a[2][200005];

		int N;
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			cin >> a[0][i];
		}
		for (int i = 1; i <= N; i++)
		{
			cin >> a[1][i];
		}

		long long dp[2][200005] = { 0 };
		
		dp[0][0] = 0;
		dp[1][0] = 0;
		
		dp[0][1] = a[0][1];
		dp[1][1] = a[1][1];

		for (int i = 2; i <= N; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + a[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + a[1][i];
		}
		cout << max(dp[0][N], dp[1][N]) << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}

