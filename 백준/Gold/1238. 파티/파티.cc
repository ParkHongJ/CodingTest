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

	// 첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 10,000), X가 공백으로 구분되어 입력된다. 
	// 두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다. 
	// 시작점과 끝점이 같은 도로는 없으며, 시작점과 한 도시 A에서 다른 도시 B로 가는 도로의 개수는 최대 1개이다.

	// 모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.
	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> Edges;
	Edges.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Edges[a].push_back({ c,b });
	}

	int answer = 0;
	for (int i = 1; i <= N; ++i)
	{
		int path = 0;
		for (int k = 0; k < 2; ++k)
		{
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


			vector<int> D;
			D.resize(N + 1, 0x7f7f7f7f);			
			
			if (k == 1)
			{
				pq.push({ 0, X });
				D[X] = 0;
			}
			else
			{
				pq.push({ 0, i });
				D[i] = 0;
			}

			while (!pq.empty())
			{
				pair<int, int> cur = pq.top(); pq.pop();
				if (D[cur.second] != cur.first)
					continue;
				for (int j = 0; j < Edges[cur.second].size(); ++j)
				{
					pair<int, int>& edge = Edges[cur.second][j];

					if (D[edge.second] > D[cur.second] + edge.first)
					{
						D[edge.second] = D[cur.second] + edge.first;
						pq.push({ D[edge.second], edge.second });
					}
				}
			}
			if (k == 1)
			{
				path += D[i];
			}
			else
			{
				path += D[X];
			}
		}
		answer = max(answer, path);
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
