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

	int N, M;
	cin >> M >> N;

	vector<vector<int>> dist(N);
	for (int i = 0; i < N; i++)
	{
		dist[i].resize(M, 0x7f7f7f7f);
	}

	vector<string> room;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		room.push_back(str);
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.push({ 0, 0, 0 });
	dist[0][0] = 0;

	while (!pq.empty())
	{
		int cost, y, x;
		tie(cost, y, x) = pq.top(); pq.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;

			int temp = 0;
			if (room[ny][nx] == '1')
			{
				temp = 1;
			}
			else
			{
				temp = 0;
			}

			if (dist[ny][nx] > dist[y][x] + temp)
			{
				dist[ny][nx] = dist[y][x] + temp;

				pq.push({ dist[ny][nx], ny, nx });

			}
		}
	}
	cout << dist[N - 1][M - 1] << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
