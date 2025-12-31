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

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;
	vector<int> ladder(105);
	vector<int> snake(105);

	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		ladder[A] = B;
	}

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		snake[A] = B;
	}
	
	bool visit[105] = { false };
	queue<pair<int,int>> q;
	q.push({ 1, 0 });

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();

		if (visit[cur.first] == false)
		{
			visit[cur.first] = true;
		}

		if (cur.first == 100)
		{
			cout << cur.second << '\n';
			break;
		}

		for (auto nxt : { cur.first + 1, cur.first + 2, cur.first + 3,
			cur.first + 4, cur.first + 5, cur.first + 6 })
		{
			if (nxt > 100)
				continue;

			int nextPos = nxt;
			if (ladder[nxt] != 0)
			{
				nextPos = ladder[nxt];
			}
			
			if (snake[nxt] != 0)
			{
				nextPos = snake[nxt];
			}

            if (visit[nextPos])
				continue;
            
			q.push({ nextPos, cur.second + 1 });
		}
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
