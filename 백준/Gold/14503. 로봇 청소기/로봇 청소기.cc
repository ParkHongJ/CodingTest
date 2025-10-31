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
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

int N, M;
bool isValid(int x, int y)
{
	if (x < 0 || y < 0 || x >= M || y >= N)
		return false;
	return true;
}
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	cin >> N >> M;
	//0 북 1 동 2 남 3 서
	int r, c, d;
	cin >> r >> c >> d;
	
	vector<vector<int>> room;
	room.resize(N);

	for (int i = 0; i < N; i++)
	{
		room[i].resize(M);
		for (int j = 0; j < M; j++)
		{
			// 0 청소되지않은것
			// 1 벽
			int wall;
			cin >> wall;
			room[i][j] = wall;
		}
	}

	/*
	* 1 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
	* 2 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
	* 
	  1 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
	  2 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.

	  3 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
	  
	  1 반시계 방향으로 90 회전한다. 0 3 2 1
	  2 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
      3 1번으로 돌아간다.
	*/

	int answer = 0;
	while (true)
	{
		if (room[r][c] == 0)
		{
			//청소 해야한다.
			room[r][c] = 2;
			answer++;
		}

		//청소되지 않은 칸
		bool bAdjClean = false;

		//주변 4칸의 청소되지 않은 칸 검사
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = c + dx[dir];
			int ny = r + dy[dir];

			if (isValid(nx,ny) == false)
				continue;

			if (room[ny][nx] == 1)
				continue;

			//인접한 공간이 청소 가능하다면
			if (room[ny][nx] == 0)
			{
				bAdjClean = true;
				break;
			}
		}

		// 현재 칸의 주변 4칸이 청소가 불가능한경우 (이미 청소되었거나 벽이거나)
		if (!bAdjClean)
		{
			// 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진
			int nx, ny;
			
			int backDir = (d + 2) % 4;
			nx = c + dx[backDir];
			ny = r + dy[backDir];

			// 후진가능
			if (isValid(nx, ny) && room[ny][nx] != 1)
			{
				c = nx;
				r = ny;
			}
			else if (isValid(nx, ny) == false || room[ny][nx] == 1)
			{
				//후진 불가능
				break;
			}
			
		}
		else // 인접한 칸이 청소 가능하다면
		{
			// 반시계 방향으로 90 회전한다. 0 북 1 동 2 남 3 서
			d = (d + 3) % 4; // 0 - 3, 1 - 0, 2 - 1, 3 - 2;
			
			int nx, ny;
			nx = c + dx[d];
			ny = r + dy[d];

			// 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
			if (isValid(nx,ny) && room[ny][nx] == 0)
			{
				c = nx;
				r = ny;
			}
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
