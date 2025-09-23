#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#include <cassert>
#pragma warning(disable :4996)
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0,0 };

void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, L, R;
	cin >> N >> L >> R;

	vector<vector<int>> country;
	country.resize(N);

	for (int i = 0; i < N; ++i)
	{
		country[i].resize(N);
		for (int j = 0; j < N; ++j)
		{
			int Citizen;
			cin >> Citizen;
			country[i][j] = Citizen;
		}
	}

	int answer = 0;

	while (true)
	{
		//국경선을 계산해야한다.
		//국경선이 열린것끼리 1로 만들어야함
		vector<vector<bool>> visit;
		visit.resize(N);

		for (int i = 0; i < N; i++)
		{
			visit[i].resize(N);
		}

		
		bool bMoved = false;
		//인접한 나라들의 인덱스
		vector<pair<int, vector<pair<int, int>>>> vppp;
		vector<pair<int, int>> vp;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visit[i][j])
				{
					continue;
				}

				int Avg = 0;
				queue<pair<int, int>> Q;
				Q.push({ j,i });
				visit[i][j] = true;

				bool bUpdate = false;
				while (!Q.empty())
				{
					pair<int, int> Cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int x = Cur.X + dx[dir];
						int y = Cur.Y + dy[dir];

						if (x < 0 || y < 0 || x >= N || y >= N)
						{
							continue;
						}

						if (visit[y][x])
						{
							continue;
						}

						//인구차이가 L명이상 R명이하라면
						int Sub = abs(country[Cur.Y][Cur.X] - country[y][x]);
						if (Sub >= L &&
							Sub <= R)
						{
							visit[Cur.Y][Cur.X] = 1;
							visit[y][x] = 1;

							Q.push({ x, y });
							Avg += country[y][x];
							vp.push_back({ x,y });
							bMoved = true;
							bUpdate = true;
						}
					}
				}

				//BFS가 한번 끝났다
				//일정부분 평균 계산과 국경선 개방이 끝났다.
				//평균값과 방문한곳들을 바로적용하면안되고 하루가 지날때까지 기다려야한다.
				//<평균값, 열린나라'들'>
				if (bUpdate)
				{
					Avg += country[i][j];
					vp.push_back({ j,i });

					Avg = Avg / vp.size();
					vppp.push_back({ Avg, vp });
					vp.clear();
				}
			}
		}


		for (int i = 0; i < vppp.size(); ++i)
		{
			for (int j = 0; j < vppp[i].second.size(); ++j)
			{
				pair<int, int> Cur = vppp[i].second[j];
				country[Cur.Y][Cur.X] = vppp[i].first;
			}
		}

		if (!bMoved)
		{
			break;
		}
		++answer;
	}
	cout << answer << '\n';
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();	getch();
	return 0;
}