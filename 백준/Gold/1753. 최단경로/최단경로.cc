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

	vector<vector<pair<int, int>>> Edges;
	
	int V, E, K;
	cin >> V >> E >> K;
	
	Edges.resize(V + 1);

	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		// u에서 v로 가는 가중치 w인 간선
		cin >> u >> v >> w;
		Edges[u].push_back({ w, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({ 0, K });
	
	vector<int> D;
	D.resize(V + 1, 0x7f7f7f7f);
	D[K] = 0;

	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();
		if (D[cur.second] != cur.first)
			continue;

		for (int i = 0; i < Edges[cur.second].size(); ++i)
		{
			pair<int, int> edge = Edges[cur.second][i];
			if (D[edge.second] > D[cur.second] + edge.first)
			{
				D[edge.second] = D[cur.second] + edge.first;
				pq.push({ D[edge.second], edge.second });
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (D[i] == 0x7f7f7f7f)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << D[i] << '\n';
		}
	}
	// i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 
	// 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
