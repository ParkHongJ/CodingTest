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

vector<vector<int>> dirs;

vector<vector<long long>> board;
int arr[5] = { -1,-1,-1,-1,-1 };
//이전에 선택한 숫자 m과 이전 row
void func(int m, int k)
{
	if (k == 5)
	{
		vector<int> vtemp;
		for (int i = 0; i < 5; ++i)
		{
			vtemp.push_back(arr[i]);
		}
		dirs.push_back(vtemp);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		arr[k] = i;
		func(arr[k], k + 1);
	}
}
//dir 방향으로 옮겼을때 나오는 합.
void Calculate(int dir, vector<vector<long long>>& sumBoard, long long& answer)
{
	vector<vector<bool>> visit;
	visit.resize(sumBoard.size());

	for (int i = 0; i < sumBoard.size(); ++i)
	{
		visit[i].resize(sumBoard.size());
	}

	int N = sumBoard.size();
	int sx = 0, sy = 0;

	if (dir == 1)
	{
		sy = sumBoard.size() - 1;
	}
	else if (dir == 3)
	{
		sx = sumBoard.size() - 1;
	}

	long long first = 0;
	pair<int, int> firstIndex = { -1,-1 };
	long long second = 0;
	pair<int, int> secondIndex = { -1,-1 };

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int nx = sx + dx[dir] * -j;
			int ny = sy + dy[dir] * -j;

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				break;

			if (visit[ny][nx] == true)
				continue;

			//first가 정해지지 않았다면
			if (sumBoard[ny][nx] != 0 && first == 0)
			{
				first = sumBoard[ny][nx];
				firstIndex = { nx, ny };
			}
			else if (sumBoard[ny][nx] != 0 && first != 0)
			{
				second = sumBoard[ny][nx];
				secondIndex = { nx, ny };
			}
			
			//둘다 값이 같다면
			if (first != 0 && second != 0 && first == second)
			{
				int cx = firstIndex.first, cy = firstIndex.second;
				pair<int, int> newPos = firstIndex;
				for (int k = 1; k < N; ++k)
				{
					int nnx = cx + dx[dir] * k;
					int nny = cy + dy[dir] * k;

					if (nnx < 0 || nny < 0 || nnx >= N || nny >= N)
						break;

					if (visit[nny][nnx])
						break;

					if (sumBoard[nny][nnx] != 0)
						break;

					newPos = { nnx, nny };
				}
				answer = max(answer, first + second);

				sumBoard[newPos.second][newPos.first] = first + second;
				visit[newPos.second][newPos.first] = true;

				if (newPos != firstIndex)
				{
					sumBoard[firstIndex.second][firstIndex.first] = 0;
				}
				sumBoard[secondIndex.second][secondIndex.first] = 0;
				first = 0; second = 0;
			}
			else if (first != 0 && second != 0 && first != second)
			{
				//둘다 값이 다르면 first 를 갱신

				int cx = firstIndex.first, cy = firstIndex.second;
				pair<int, int> newPos = firstIndex;
				for (int k = 1; k < N; ++k)
				{
					int nnx = cx + dx[dir] * k;
					int nny = cy + dy[dir] * k;

					if (nnx < 0 || nny < 0 || nnx >= N || nny >= N)
						break;

					if (visit[nny][nnx])
						break;

					if (sumBoard[nny][nnx] != 0)
						break;

					newPos = { nnx, nny };
				}

				if (newPos != firstIndex)
				{
					sumBoard[newPos.second][newPos.first] = first;
					sumBoard[cy][cx] = 0;
				}

				first = second;
				firstIndex = { nx, ny };
				second = 0;
			}
		}
		if (first != 0)
		{
			int cx = firstIndex.first, cy = firstIndex.second;
			pair<int, int> newPos = firstIndex;
			for (int k = 1; k < N; ++k)
			{
				int nnx = cx + dx[dir] * k;
				int nny = cy + dy[dir] * k;

				if (nnx < 0 || nny < 0 || nnx >= N || nny >= N)
					break;

				if (visit[nny][nnx])
					break;

				if (sumBoard[nny][nnx] != 0)
					break;

				newPos = { nnx, nny };
			}

			if (newPos != firstIndex)
			{
				sumBoard[newPos.second][newPos.first] = first;
				sumBoard[cy][cx] = 0;
			}
		}
		first = 0; second = 0;	

		//상or하면 다음루프에 sx가 증가
		if (dir == 0 || dir == 1)
		{
			++sx;
		}
		else
		{
			++sy;
		}
	}
}
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	

	func(0, 0);

	int N;
	cin >> N;

	board.resize(N);

	long long answer = 0;

	for (int i = 0; i < N; ++i)
	{
		board[i].resize(N);
		for (int j = 0; j < N; ++j)
		{
			long long input;
			cin >> input;
			board[i][j] = input;
		}
	}

	for (int i = 0; i < dirs.size(); ++i)
	{
		vector<vector<long long>> sumBoard = board;
		long long sum = 0;
		for (int j = 0; j < dirs[i].size(); ++j)
		{
			Calculate(dirs[i][j], sumBoard, sum);
		}
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				answer = max(answer, sumBoard[j][k]);
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