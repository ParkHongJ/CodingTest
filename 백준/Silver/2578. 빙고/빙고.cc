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

//상하좌우
int dx[4] = { 0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};

int N = 5, M = 5;

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	

	//cin >> N >> M;

	vector<pair<int, int>> v; //n번째 숫자가 x,y어디에 있는지
	v.resize(N * M + 1);

	vector<vector<long long>> board;
	board.resize(N);
	for (int i = 0; i < N; ++i)
	{
		board[i].resize(M);
		for (int j = 0; j < M; ++j)
		{
			long long input;
			cin >> input;
			board[i][j] = input;

			v[input] = { i,j };
		}
	}

	vector<long long> row;
	vector<long long> col;
	vector<long long> lt;
	vector<long long> rt;

	row.resize(N + 1);
	col.resize(M + 1);

	int bingo = 0;
	for (int i = 0; i < N * M; ++i)
	{
		long long input;
		cin >> input;
		
		pair<int,int> cur = v[input];
		int nx = cur.first;
		int ny = cur.second;
		
		++row[nx];
		++col[ny];

		if (row[nx] >= M)
		{
			++bingo;
		}
		if (col[ny] >= N)
		{
			++bingo;
		}

		//[][] 0 4, 1 3, 2 2, 3 1, 4 0
		
		if (nx == 2 && ny == 2)
		{
			lt.push_back(0);
			rt.push_back(0);

			if (rt.size() >= N)
			{
				++bingo;
			}
			if (lt.size() >= M)
			{
				++bingo;
			}
		}
		else if (nx == ny)
		{
			//좌상단에서 우하단빙고
			lt.push_back(0);
			if (lt.size() >= M)
			{
				++bingo;
			}
		}
		else if ((nx + ny) / 2 == 2 && (nx + ny) % 2 == 0)
		{
			rt.push_back(0);
			if (rt.size() >= N)
			{
				++bingo;
			}
		}

		

		if (bingo >= 3)
		{
			cout << i + 1 << '\n';
			return;
		}
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}