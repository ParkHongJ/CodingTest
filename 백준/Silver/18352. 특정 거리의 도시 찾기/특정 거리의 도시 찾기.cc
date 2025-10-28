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

	// 첫째 줄에 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X가 주어진다.
	// (2 ≤ N ≤ 300,000, 1 ≤ M ≤ 1,000,000, 1 ≤ K ≤ 300,000, 1 ≤ X ≤ N) 
	// 둘째 줄부터 M개의 줄에 걸쳐서 두 개의 자연수 A, B가 공백을 기준으로 구분되어 주어진다. 
	// 이는 A번 도시에서 B번 도시로 이동하는 단방향 도로가 존재한다는 의미다. (1 ≤ A, B ≤ N) 
	// 단, A와 B는 서로 다른 자연수이다.
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector<pair<int, int>>> Edges;
	Edges.resize(300000);
	for (int i = 0; i < M; i++)
	{
		int A, B; 
		cin >> A >> B;
		Edges[A].push_back({ 1,B });
	}

	vector<int> dist;
	dist.resize(300000, 0x7f7f7f7f);

	dist[X] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, X });
	
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();
		if (cur.first != dist[cur.second])
			continue;

		for (int i = 0; i < Edges[cur.second].size(); i++)
		{
			//현재 정점의 이웃간선 edge
			pair<int, int>& edge = Edges[cur.second][i];
			if (dist[edge.second] > dist[cur.second] + edge.first)
			{
				dist[edge.second] = dist[cur.second] + edge.first;
				pq.push({ dist[edge.second], edge.second });
			}
		}
	}

	vector<int> answer;
	for (int i = 0; i < dist.size(); i++)
	{
		if (dist[i] == K)
		{
			answer.push_back(i);
		}
	}
	if (answer.empty())
	{
		cout << -1 << '\n';
		return;
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
