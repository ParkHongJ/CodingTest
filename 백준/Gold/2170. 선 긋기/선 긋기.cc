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

#define X first
#define Y second

//상하좌우
int dx[4] = { 0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	//선을 그은 횟수 N (1 ≤ N ≤ 1,000,000)
	//두 점의 위치 x, y (-1,000,000,000 ≤ x < y ≤ 1,000,000,000)

	int N;
	cin >> N;
	
	vector<pair<long long, long long>> v;

	v.resize(N);
	for (int i = 0; i < N; ++i)
	{
		long long x, y;
		cin >> x >> y;
		v[i] = { x,y };
	}

	sort(v.begin(), v.end());

	pair<long long, long long> cur = v[0];
	long long answer = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		//현재 선분 안쪽에 v[i]의 x가 있다면 두 선분은 합쳐서 계산한다. 
		if (cur.second >= v[i].first && cur.second < v[i].second)
		{
			cur.second = v[i].second;
		}
		else if (cur.second < v[i].first)
		{
			//현재 선분 밖에있다면 현재 선분의 길이를 최종길이에 더한다.
			answer += cur.second - cur.first;
			cur = v[i];
		}

		if (i + 1 >= v.size())
		{
			answer += cur.second - cur.first;
		}
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}