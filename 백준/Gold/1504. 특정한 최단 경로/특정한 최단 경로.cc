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
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 첫째 줄에 정점의 개수 N과 간선의 개수 E가 주어진다.
	// (2 ≤ N ≤ 800, 0 ≤ E ≤ 200,000) 둘째 줄부터 E개의 줄에 걸쳐서 세 개의 정수 a, b, c가 주어지는데, 
	// a번 정점에서 b번 정점까지 양방향 길이 존재하며, 그 거리가 c라는 뜻이다. (1 ≤ c ≤ 1,000)
	// 다음 줄에는 반드시 거쳐야 하는 두 개의 서로 다른 정점 번호 v1과 v2가 주어진다. (v1 ≠ v2, v1 ≠ N, v2 ≠ 1) 
	// 임의의 두 정점 u와 v사이에는 간선이 최대 1개 존재한다.
	
	// 첫째 줄에 두 개의 정점을 지나는 최단 경로의 길이를 출력한다. 그러한 경로가 없을 때에는 -1을 출력한다.
	int N, E;
	cin >> N >> E;
	vector<vector<pair<long long, int>>> Edges;
	Edges.resize(N + 1);
	const long long INF = (long long)4e18;

	for (int i = 0; i < E; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		Edges[a].push_back({ c,b });
		Edges[b].push_back({ c,a });
	}
	int v1, v2;
	cin >> v1 >> v2;

	vector<long long> d1(N + 1, INF), dv1(N + 1, INF), dv2(N + 1, INF);

	for (int st : {1, v1, v2})
	{
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

		vector<long long> dist;
		dist.resize(N + 1, INF);

		dist[st] = 0;
		pq.push({ 0, st });

		while (!pq.empty())
		{
			pair<long long, int> cur = pq.top(); pq.pop();

			if (cur.first != dist[cur.second])
				continue;

			for (int i = 0; i < Edges[cur.second].size(); i++)
			{
				pair<long long, int> edge = Edges[cur.second][i];

				if (dist[edge.second] > dist[cur.second] + edge.first)
				{
					dist[edge.second] = dist[cur.second] + edge.first;
					pq.push({ dist[edge.second], edge.second });
				}
			}
		}

		if (st == 1)  d1 = dist;
		if (st == v1) dv1 = dist;   
		if (st == v2) dv2 = dist;

	}

	long long pathA = INF;
	// 1→v1→v2→N
	if (d1[v1] < INF && dv1[v2] < INF && dv2[N] < INF)
	{
		pathA = d1[v1] + dv1[v2] + dv2[N]; // 1→v1→v2→N
	}
	long long pathB = INF;
	if (d1[v2] < INF && dv2[v1] < INF && dv1[N] < INF)
	{
		pathB = d1[v2] + dv2[v1] + dv1[N]; // 1→v2→v1→N
	}

	long long ans = min(pathA, pathB);

	if (ans >= INF)
		cout << -1 << '\n';
	else          
		cout << ans << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
