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

	/*
	*	첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 
		둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.
	*/
	int N;
	cin >> N;

	vector<vector<int>> Edges(N + 1);
	
	for (int i = 1; i <= N; i++)
	{
		int A, B;
		cin >> A >> B;

		Edges[A].push_back(B);
		Edges[B].push_back(A);
	}

	vector<int> parent(N + 1, 0);
	parent[1] = -1;

	
	queue<int> q;
	q.push(1);

	vector<bool> visit(N + 1);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		if (visit[cur])
			continue;
		visit[cur] = true;

		for (int j = 0; j < Edges[cur].size(); ++j)
		{
			int neighbor = Edges[cur][j];

			if (parent[neighbor] != 0)
				continue;

			if (parent[cur] != 0)
			{
				parent[neighbor] = cur;
			}
			if (visit[neighbor])
				continue;

			q.push(neighbor);
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
