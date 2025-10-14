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

int N, K;
int arr[100000];
bool isUsed[100000];

int answer = 0;

//N개의 자연수와 자연수 M이 주어졌을 때, 
// 아래 조건을 만족하는 길이가 M인 수열
// N개의 자연수는 모두 다른 수이다.

set<string> s;

void func(int m)
{
	//if (m == K)
	//{
	//	string str;
	//	for (int i = 0; i < K; i++)
	//	{
	//		str += to_string(arr[i]);
	//	}

	//	//중복이 아니라면
	//	if (s.find(str) == s.end())
	//	{
	//		++answer;
	//		s.insert(str);
	//	}
	//	return;
	//}

	//for (int i = 0; i < N; ++i)
	//{
	//	if (isUsed[i] == false)
	//	{
	//		arr[m] = v[i];
	//		isUsed[i] = true;
	//		func(m + 1);
	//		isUsed[i] = false;
	//	}
	//}
}
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 상대방의 필드가 주어졌을 때, 연쇄가 몇 번 연속으로 일어날지 계산
	vector<string> board;
	board.resize(12);
	
	for (int i = 0; i < 12; ++i)
	{
		string input;
		cin >> input;
		board[i] = input;
	}

	//bfs로 인접한 뿌요를 터트리고 다시 갱신된 board를 기준으로 bfs
	//한번 bfs가 일어날때마다 (12 * 6) ^ 2 * N

	int answer = 0;

	while (true)
	{
		bool visit[12][6] = { false };
		
		vector<vector<pair<int, int>>> deletePuyo;

		for (int i = 0; i < 12; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (board[i][j] == '.')
					continue;

				queue<pair<int, int>> q;
				q.push({ j,i });
				
				visit[i][j] = true;

				char curPuyo = board[i][j];

				vector<pair<int, int>> v;
				v.push_back({ j,i });

				while (!q.empty())
				{
					pair<int, int>& cur = q.front(); q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = dx[dir] + cur.first;
						int ny = dy[dir] + cur.second;

						if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12)
						{
							continue;
						}

						//현재 검사하고있는 뿌요와 다르면 무시
						if (board[ny][nx] != curPuyo || visit[ny][nx])
						{
							continue;
						}
						else
						{
							//검사하고있는 뿌요라면
							visit[ny][nx] = true;
							q.push({ nx,ny });
							v.push_back({ nx,ny });
						}
					}
				}
				
				if (v.size() >= 4)
				{
					deletePuyo.push_back(v);
				}
			}
		}

		if (deletePuyo.empty())
		{
			//뿌요가 터지지 않았다.
			break;
		}

		for (int i = 0; i < deletePuyo.size(); ++i)
		{
			for (int j = 0; j < deletePuyo[i].size(); j++)
			{
				pair<int, int>& removePos = deletePuyo[i][j];
				visit[removePos.second][removePos.first] = false;
				board[removePos.second][removePos.first] = '.';
			}
		}


		for (int j = 0; j < 6; ++j)
		{
			string str;
			bool Update = false;
			for (int i = 0; i < 12; ++i)
			{
				if (board[i][j] != '.')
				{
					str += board[i][j];
					board[i][j] = '.';
				}
			}

			if (str.empty())
				continue;

			int k = 0;

			for (int i = 12 - str.length();  i < 12; ++i, ++k)
			{
				board[i][j] = str[k];
			}

		}
		answer++;
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}