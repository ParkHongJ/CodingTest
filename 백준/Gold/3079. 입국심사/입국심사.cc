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

#define X second 
#define Y first 

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	unsigned long long N, M;
	cin >> N >> M;
	
	vector<unsigned long long> T;
	
	while (N--)
	{
		long long time;
		cin >> time;
		T.push_back(time);
	}

	sort(T.begin(), T.end());

	unsigned long long high = T[T.size() - 1] * M; //친구들이 가장 오래걸리는 심사대로 갔을때 걸리는 "최대시간"

	unsigned long long low = 0;

	unsigned long long answer = 0;
	while (high >= low)
	{
		unsigned long long mid = (high + low) / 2;

		unsigned long long cnt = 0;
		for (int i = 0; i < T.size(); i++)
		{
			cnt += mid / T[i];
		}
		if (cnt >= M)
		{
			high = mid - 1;
			if (answer > mid || answer == 0)
				answer = mid;
		}
		else
			low = mid + 1;
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
