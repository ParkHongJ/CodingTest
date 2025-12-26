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

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int M, N, H;
	cin >> M >> N >> H;

	int tomatos = 0;
	int cooktomatos = 0;

	vector<vector<vector<int>>> board(H);
	vector<vector<vector<bool>>> visit(H);

	queue<tuple<int, int, int>> q;

	for (int i = 0; i < H; i++)
	{
		board[i].resize(N);
		visit[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			board[i][j].resize(M);
			visit[i][j].resize(M);
			for (int k = 0; k < M; k++)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] != -1)
				{
					++tomatos;
				}
				if (board[i][j][k] == 1)
				{
					++cooktomatos;
				}
				if (board[i][j][k] == 1 && visit[i][j][k] == false)
				{
					visit[i][j][k] = true;
					q.push({ k,j,i });
				}
			}
		}
	}

	int answer = 0;

	while (true)
	{
		bool isChange = false;

		int loop = q.size();
		for (int i = 0; i < loop; i++)
		{
			int x, y, z;
			tie(x, y, z) = q.front(); q.pop();

			for (int dir = 0; dir < 6; ++dir)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				int nz = z + dz[dir];

				if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H)
					continue;

				if (board[nz][ny][nx] == 0)
				{
					board[nz][ny][nx] = 1;
					isChange = true;
					++cooktomatos;
					q.push({ nx,ny,nz });
				}
			}
		}
			
		
		if (!isChange)
		{
			if (cooktomatos != tomatos)
				answer = -1;

			break;
		}
		++answer;
	}

	cout << answer << '\n';
}


int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
