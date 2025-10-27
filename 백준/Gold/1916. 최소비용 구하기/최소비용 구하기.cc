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

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 첫째 줄에 도시의 개수 n(1≤n≤1,000)이 주어지고 
	// 둘째 줄에는 버스의 개수 m(1≤m≤100,000)이 주어진다. 
	// 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 
	// 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 
	// 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 
	// 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.

	// 그리고 m + 3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다.
	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> Edges;
	Edges.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Edges[a].push_back({ c,b });
	}

	int st, ed;
	cin >> st >> ed;
	
	vector<int> D;
	D.resize(N + 1, 0x7f7f7f7f);
	D[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,st });

	vector<int> pre;
	pre.resize(N + 1);

	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();

		if (D[cur.second] != cur.first)
			continue;

		for (int i = 0; i < Edges[cur.second].size(); i++)
		{
			pair<int, int>& edge = Edges[cur.second][i];
			if (D[edge.second] > D[cur.second] + edge.first)
			{
				D[edge.second] = D[cur.second] + edge.first;
				pq.push({ D[edge.second], edge.second });
				pre[edge.second] = cur.second;
			}
		}	
	}

	cout << D[ed] << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
