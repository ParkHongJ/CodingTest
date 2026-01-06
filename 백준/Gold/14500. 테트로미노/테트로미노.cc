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

int maxRect(int x, int y, const vector<vector<int>>& board);
int maxL(int x, int y, const vector<vector<int>>& board);
int maxZ(int x, int y, const vector<vector<int>>& board);
int maxR(int x, int y, const vector<vector<int>>& board);
int maxN(int x, int y, const vector<vector<int>>& board);

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	int maxNum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			maxNum = max(maxNum, maxRect(j, i, board));
			maxNum = max(maxNum, maxL(j, i, board));
			maxNum = max(maxNum, maxZ(j, i, board));
			maxNum = max(maxNum, maxR(j, i, board));
			maxNum = max(maxNum, maxN(j, i, board));
		}
	}
	cout << maxNum << '\n';
}
bool checkRange(int x, int y, const vector<vector<int>>& board)
{
	if (x < 0 || y < 0 || x >= board[0].size() || y >= board.size())
	{
		return false;
	}
	return true;
}

int maxRect(int x, int y, const vector<vector<int>>& board)
{
	// x y를 기준으로 4회전 했을때 사각형 범위안의 최대값
	int maxNum = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int nx = x + j;
			int ny = y + i;
			if (!checkRange(nx,ny, board))
				return 0;

			maxNum += board[ny][nx];
		}
	}
	return maxNum;
}
int maxL(int x, int y, const vector<vector<int>>& board)
{
	// x y를 기준으로 4회전 했을때 L범위 안의 최대값
	int maxNum = 0;

	int dx[8][4] = { {0,0,0,1}, {0,-1,-2,-2}, {0,0,0,-1}, {0,1,2,2},
	{0,0,0,-1}, {0,-1,-2,-2}, {0,0,0,1}, {0,1,2,2} };
	
	int dy[8][4] = { {0,1,2,2}, {0,0,0,1}, {0,-1,-2,-2}, {0,0,0,-1},
	{0,1,2,2}, {0,0,0,-1}, {0,-1,-2,-2}, {0,0,0,1} };

	for (int dir = 0; dir < 8; ++dir)
	{
		int temp = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[dir][i];
			int ny = y + dy[dir][i];
			if (!checkRange(nx, ny, board))
				break;
			temp += board[ny][nx];
		}
		maxNum = max(temp, maxNum);
	}
	return maxNum;
}
int maxZ(int x, int y, const vector<vector<int>>& board)
{
	// x y를 기준으로 4회전 했을때 Z범위 안의 최대값
	int maxNum = 0;

	int dx[4][4] = { {0,0,1,1}, {0,-1,-1,-2}, {0,0,-1,-1}, {0,-1,-1,-2} };
	int dy[4][4] = { {0,1,1,2}, {0,0,1,1}, {0,1,1,2}, {0,0,-1,-1} };

	for (int dir = 0; dir < 4; ++dir)
	{
		int temp = 0;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[dir][i];
			int ny = y + dy[dir][i];
			if (!checkRange(nx, ny, board))
				break;
			temp += board[ny][nx];
		}
		maxNum = max(temp, maxNum);
	}
	return maxNum;
}
int maxR(int x, int y, const vector<vector<int>>& board)
{
	// x y를 기준으로 2회전 했을때 ㅣ범위 안의 최대값
	int maxNum = 0;

	{
		int temp = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + i;
			int ny = y;
			if (!checkRange(nx, ny, board))
				break;
			temp += board[ny][nx];
		}
		maxNum = max(temp, maxNum);
	}
	{
		int temp = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x;
			int ny = y + i;
			if (!checkRange(nx, ny, board))
				break;
			temp += board[ny][nx];
		}
		maxNum = max(temp, maxNum);
	}
	return maxNum;
}
int maxN(int x, int y, const vector<vector<int>>& board)
{
	// x y를 기준으로 4회전 했을때 ㅜ범위 안의 최대값
	int maxNum = 0;

	int dx[4][4] = { {0,1,1,2}, {0,-1,0,0}, {0,-1,-1,-2,}, {0,1,0,0} };
	int dy[4][4] = { {0,1,0,0 }, { 0,1,1,2 }, { 0,-1,0,0 }, { 0, -1, -1, -2 } };

	for (int dir = 0; dir < 4; dir++)
	{
		int temp = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[dir][i];
			int ny = y + dy[dir][i];
			if (!checkRange(nx, ny, board))
				break;
			temp += board[ny][nx];
		}
		maxNum = max(temp, maxNum);
	}
	return maxNum;
}


int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
