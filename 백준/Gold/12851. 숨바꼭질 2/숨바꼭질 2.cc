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

//우좌상하
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

bool visit[15] = { false };

int answer = 0;
vector<int> v;

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> dist;
	vector<int> cnt;

	dist.resize(200005, -1);
	cnt.resize(200005, 0);

	queue<pair<int, int>> q;

	q.push({ N,0 });
	cnt[N] = 1;
    dist[N] = 0;
	while (!q.empty())
	{
		//위치, 시간
		pair<int, int> cur = q.front(); q.pop();

		for (auto nxt : {cur.first + 1, cur.first * 2, cur.first - 1})
		{
			if (nxt < 0 || nxt >= dist.size())
				continue;
			
			if (dist[nxt] == -1)
			{
				dist[nxt] = cur.second + 1;
				cnt[nxt] = cnt[cur.first];
				q.push({ nxt, cur.second + 1 });
			}
			else if (dist[nxt] == cur.second + 1)
			{
				cnt[nxt] += cnt[cur.first];
			}
		}
	}
	cout << dist[K] << '\n' << cnt[K] << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
