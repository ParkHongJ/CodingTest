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

//우좌상하
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

int arr[100000];
bool isUsed[100000];

vector<int> v;
vector<vector<bool>> command;
long maxanswer = 0;
long minanswer = 0;

void func(int m)
{
	//if (m == N)
	//{
	//	string str;
	//	for (int i = 0; i < K; i++)
	//	{
	//		str += to_string(arr[i]);
	//	}

	//	//중복이 아니라면
	//	if (s.find(str) == s.end())
	//	{
	//		++answer;
	//		s.insert(str);
	//	}
	//	return;
	//}

	//for (int i = 0; i < N; ++i)
	//{
	//	if (isUsed[i] == false)
	//	{
	//		arr[m] = v[i];
	//		isUsed[i] = true;
	//		func(m + 1);
	//		isUsed[i] = false;
	//	}
	//}
}
vector<int> p;
int find(int x)
{
	if (p[x] < 0)
	{
		return x;
	}
	return p[x] = find(p[x]);
}
bool uni(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
		return false;

	p[v] = u;
	return true;
}

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 입력으로 첫 줄에 행성의 수 N (1 ≤ N ≤ 1000)이 주어진다.

	// 두 번째 줄부터 N + 1줄까지 각 행성간의 플로우 관리 비용
	
	// 모든 행성을 연결했을 때, 최소 플로우의 관리비용을 출력한다.
	int N;
	cin >> N;
	
	vector<vector<pair<int, int>>> v;
	v.resize(N);

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			int cost;
			cin >> cost;
			v[i].push_back({ cost, j });
		}
	}
	
	vector<bool> visit;
	visit.resize(N, false);
	visit[0] = true;

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int i = 0; i < v[0].size(); i++)
	{
		pq.push(v[0][i]);
	}

	long answer = 0;
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();
		if (visit[cur.second] == false)
		{
			// 방문하지 않았다면
			visit[cur.second] = true;

			for (int i = 0; i < v[cur.second].size(); i++)
			{
				if (v[cur.second][i].first == 0)
					continue;
				pq.push(v[cur.second][i]);
			}

			answer += cur.first; // 코스트를 추가
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
