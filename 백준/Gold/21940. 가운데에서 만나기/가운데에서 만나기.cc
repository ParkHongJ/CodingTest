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

//우좌상하
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 도시 N과 도로 개수 M
	int N, M;
	cin >> N >> M;
	const int maxint = 0x3f3f3f3f;

	vector<vector<int>> D;
	D.resize(N + 1);
	
	for (int i = 1; i <= N; i++)
	{
		D[i].resize(N + 1, maxint);
	}
	for (int i = 1; i <= N; i++)
	{
		D[i][i] = 0;
	}

	for (int i = 0; i < M; ++i)
	{
		int a, b, t;
		cin >> a >> b >> t;
		D[a][b] = min(D[a][b], t);
	}


	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (D[i][k] >= maxint || D[k][j] >= maxint)
					continue;

				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	int K;
	cin >> K;
	vector<int> town;
	town.resize(N + 1);
	for (int i = 0; i < K; ++i)
	{
		int s;
		cin >> s;

		//현재 친구 s에 대해 각 j번째 도시에 대해 왕복시간을 계산
		for (int j = 1; j <= N; ++j)
		{
			if (j == s) continue;
			
			//길이 없다면
			if (D[s][j] >= maxint || D[j][s] >= maxint) continue;

			town[j] = max(town[j], D[s][j] + D[j][s]);
		}
	}
	vector<pair<int, int>> temp;

	for (int i = 1; i < town.size(); ++i)
	{
		temp.push_back({ town[i], i });
	}

	sort(temp.begin(), temp.end());

	vector<int> answer;
	int cost = temp[0].first;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].first > cost)
			break;
		answer.push_back(temp[i].second);
	}

	sort(answer.begin(), answer.end());
	
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
