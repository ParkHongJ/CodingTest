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
#pragma warning(disable :4996)
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };


void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N;

	cin >> N;

	stack<pair<int, int>> s;
	
	vector<vector<int>> v;
	vector<vector<bool>> vis;
	vector<int> idx;
	vector<int> answer;

	v.resize(N);
	vis.resize(N);

	for (int i = 0; i < N; ++i)
	{
		v[i].resize(N);
		vis[i].resize(N);
		string str;
		cin >> str;
		for (int j = 0; j < N; ++j)
		{
			v[i][j] = str[j] - '0';
		}
	}

	int dan = -1;
	while (true)
	{
		if (s.empty())
		{
			//새로운 단지를 찾아야한다.

			bool bFound = false;
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					if (vis[i][j] == false && v[i][j] == 1)
					{
						//현재 단지를 증가시키고
						answer.push_back(1);
						++dan;

						vis[i][j] = true;
						bFound = true;

						s.push({ j,i });
						break;
					}
				}
				if (bFound)
				{
					break;
				}
			}
			if (bFound == false)
			{
				break;
			}
		}

		pair<int, int> cur = s.top();
		s.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			{
				continue;
			}

			if (vis[ny][nx] == false && v[ny][nx] == 1)
			{
				vis[ny][nx] = true;
				++answer[dan];
				s.push({ nx, ny });
			}
		}
	}

	cout << answer.size() << '\n';

	sort(answer.begin(), answer.end());
    
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}