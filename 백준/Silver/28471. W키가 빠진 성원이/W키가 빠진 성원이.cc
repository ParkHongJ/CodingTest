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

//상우하좌
//왼상오상 왼하 오하 
//아래방향은 없다
int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1};
int dy[8] = { -1, 0, 0, 0, -1, -1, 1, 1};

#define X second 
#define Y first 
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	vector<string> board;
	board.resize(N);
	vector<vector<bool>> visit;
	visit.resize(N);
	for (int i = 0; i < N; ++i)
	{
		visit[i].resize(N, false);

		string s;
		cin >> s;
		board[i] = s;
	}

	pair<int, int> st;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 'F')
			{
				st = { i,j };
				break;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(st);
	
	int answer = 0;
	visit[st.Y][st.X] = true;

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();

		for (int dir = 0; dir < 8; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[ny][nx] || board[ny][nx] == '#')
				continue;
			
			visit[ny][nx] = true;

			++answer;

			q.push({ ny, nx });
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
