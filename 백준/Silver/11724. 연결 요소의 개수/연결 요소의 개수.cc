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

	//정점의 개수 N과 간선의 개수 M (N은 1부터 N까지)
	int N, M;
	cin >> N >> M;

	vector<bool> visit(N + 1);

	vector<vector<int>> edges(N + 1);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	int component = 0;

	for (size_t i = 1; i <= N; i++)
	{
		if (visit[i])
			continue;

		queue<int> q;

		q.push(i);

		while (!q.empty())
		{
			int cur = q.front(); q.pop();

			if (visit[cur] == false)
				visit[cur] = true;
            else
				continue;
            
			for (int j = 0; j < edges[cur].size(); ++j)
			{
				if (visit[edges[cur][j]])
					continue;

				q.push(edges[cur][j]);
			}
		}

		++component;
	}
	cout << component << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
