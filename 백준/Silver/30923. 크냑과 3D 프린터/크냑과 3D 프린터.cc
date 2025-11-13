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
#pragma warning(disable :4996)
using namespace std;

//상우하좌
//왼상오상 왼하 오하 
//아래방향은 없다
int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1};
int dy[8] = { -1, 0, 0, 0, -1, -1, 1, 1};

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	vector<long long> height;

	unsigned long long N;
	cin >> N;
	height.resize(N);

	long long answer = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> height[i];

		//앞면 뒷면 윗면 바닥면
		answer += height[i] * 2;

		if (i - 1 >= 0)
		{
			answer += abs(height[i - 1] - height[i]);
		}
	}

	answer += N * 2;
	answer += height[0] + height[height.size() - 1];
	
	cout << answer << '\n';
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
