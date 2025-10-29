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

	//첫째 줄에 도시의 수 N(2 ≤ N ≤ 100,000), 도로의 수 M(1 ≤ M ≤ 500,000), 면접장의 수 K(1 ≤ K ≤ N)가 공백을 두고 주어진다.
	// 도시는 1번부터 N번까지의 고유한 번호가 매겨진다.

	// 다음 M개의 줄에 걸쳐 한 줄마다 도시의 번호 U, V(U ≠ V)와 도로의 길이 C(1 ≤ C ≤ 100, 000)가 공백을 두고 순서대로 주어진다.
	// 이는 도시 U에서 V로 갈 수 있는 도로가 존재하고, 그 거리가 C라는 뜻이다.

	//	마지막 줄에 면접장이 배치된 도시의 번호 K개가 공백을 두고 주어진다.
	
	int N, M, K;
	cin >> N >> M >> K;
	
	vector<vector<pair<long long, int>>> Edges;
	Edges.resize(N + 1);
	
	for (int i = 0; i < M; i++)
	{
		long long U, V, C;
		cin >> U >> V >> C;
		Edges[V].push_back({ C,U });
	}
	const long long INF = (long long)4e18;
	vector<int> city;
	vector<long long> dist;
	dist.resize(N + 1, INF);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	for (int i = 0; i < K; i++)
	{
		int numCity;
		cin >> numCity;
		city.push_back(numCity);

		dist[numCity] = 0;
		pq.push({ 0, numCity });
	}
	//각 도시에서 면접장까지의 거리 중, 그 거리가 가장 먼 도시에서 오는 면접자에게 교통비를 주려고 한다.

	// 승범이를 위해 면접장까지의 거리가 가장 먼 도시와 그 거리를 구해보도록 하자.

	vector<pair<long long, int>> answerCities;

	while (!pq.empty())
	{
		pair<long long, int> cur = pq.top(); pq.pop();

		if (dist[cur.second] != cur.first)
			continue;

		for (int j = 0; j < Edges[cur.second].size(); ++j)
		{
			pair<long long, int>& edge = Edges[cur.second][j];

			if (dist[edge.second] > dist[cur.second] + edge.first)
			{
				dist[edge.second] = dist[cur.second] + edge.first;
				pq.push({ dist[edge.second], edge.second });
			}
		}
	}

	long long maxDist = 0;
	for (int j = 1; j <= N; ++j)
	{
		if (dist[j] >= INF)
		{
			continue;
		}
		maxDist = max(maxDist, dist[j]);
	}

	for (int j = 1; j <= N; ++j)
	{
		if (dist[j] == maxDist)
		{
			answerCities.push_back({ maxDist, j });
		}
	}

	sort(answerCities.begin(), answerCities.end(), less<pair<long long, int>>());

	long long maxTempDist = 0;
	int minCity = 0x7f7f7f7f;
	for (int i = 0; i < answerCities.size(); ++i)
	{
		if (maxTempDist <= answerCities[i].first)
		{
			maxTempDist = answerCities[i].first;
			minCity = min(minCity, answerCities[i].second);
		}
	}
	cout << minCity << '\n';
	cout << maxTempDist << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
