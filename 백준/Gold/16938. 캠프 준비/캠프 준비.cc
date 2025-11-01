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
#pragma warning(disable :4996)
using namespace std;

//우좌상하
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

bool visit[15] = { false };

int answer = 0;
vector<long long> v;

int N;
long long L, R, X;
long long best = 0;
long long worst = 0;
long long sum = 0;
int cnt = 0;
//현재 고른 난이도, 난이도의 합, 최고난이도, 최저난이도, 몇개골랐는지
void func(int st)
{
	if (cnt >= 2 && best - worst >= X)
	{
		if (sum >= L && sum <= R)
		{
			++answer;
		}
	}

	for (int i = st; i <= N; ++i)
	{
		if (visit[i] == true)
			continue;
		if (sum + v[i] > R)
			continue;

		visit[i] = true;
		sum += v[i];
		long long prevBest = best;
		long long prevWorst = worst;
		if (cnt == 0)
		{
			best = worst = v[i];
		}
		else
		{
			best = max(best, v[i]);
			worst = min(worst, v[i]);
		}
		++cnt;
		func(i);
		--cnt;
		sum -= v[i];
		visit[i] = false;
		best = prevBest;
		worst = prevWorst;

	}
}

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	cin >> N >> L >> R >> X;
	
	v.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int A;
		cin >> A;
		v[i] = A;
	}

	func(1);
	cout << answer;
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
