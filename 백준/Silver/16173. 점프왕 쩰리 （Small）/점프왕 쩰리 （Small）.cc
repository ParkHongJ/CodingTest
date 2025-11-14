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
#include <unordered_set>
#pragma warning(disable :4996)
using namespace std;

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	vector<vector<int>> board(N);
	vector<vector<bool>> visit(N);

	for (int i = 0; i < N; ++i)
	{
		board[i].resize(N);
		visit[i].resize(N);
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });

	bool arrived = false;
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();

		if (visit[cur.second][cur.first])
			continue;

		visit[cur.second][cur.first] = true;

		for (int dir = 0; dir < 2; ++dir)
		{
			int nx = cur.first + (dx[dir] * board[cur.second][cur.first]);
			int ny = cur.second + (dy[dir] * board[cur.second][cur.first]);

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;

			q.push({ nx,ny });
		}

		if (cur.first == N - 1 && cur.second == N - 1)
		{
			arrived = true;
			break;
		}
	}

	if (arrived)
	{
		cout << "HaruHaru" << '\n';
	}
	else
	{
		cout << "Hing" << '\n';
	}
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
