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
#include <cmath>
#pragma warning(disable :4996)
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N);
	vector<vector<int>> depthMap(N);
	vector<vector<bool>> visit(N);

	pair<int, int> goal;
	for (int i = 0; i < N; i++)
	{
		board[i].resize(M);
		depthMap[i].resize(M, -1);
		visit[i].resize(M);
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				goal = { j,i };
				depthMap[i][j] = 0;
			}
			if (board[i][j] == 0)
			{
				depthMap[i][j] = 0;
			}
		}
	}
	
	queue<tuple<int, int, int>> q;
	q.push({ goal.first, goal.second, 0 });

	while (!q.empty())
	{
		tuple<int, int, int> tup = q.front(); q.pop();

		pair<int, int> cur;
		int depth;
		tie(cur.first, cur.second, depth) = tup;

		if (visit[cur.second][cur.first] == false)
		{
			visit[cur.second][cur.first] = true;
			//depthMap[cur.second][cur.first] = min(depthMap[cur.second][cur.first], depth);
			depthMap[cur.second][cur.first] = depth;
		}
		else
			continue;
			
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N || visit[ny][nx] == true)
				continue;
			if (board[ny][nx] == 0)
			{
				continue;
			}
			q.push({ nx,ny, depth + 1 });		
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << depthMap[i][j] << " ";
		}
		cout << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
