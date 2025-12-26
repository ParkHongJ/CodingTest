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

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, Edges;
	cin >> N >> Edges;

	vector<vector<int>> v(N + 1);

	for (int i = 1; i <= Edges; i++)
	{
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}

	bool visit[10005] = { false };
	queue<int> q;
	q.push(1);
	int answer = 0;
	visit[1] = true;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		if (visit[cur] == false)
		{
			visit[cur] = true;
			++answer;
		}

		for (int i = 0; i < v[cur].size(); i++)
		{
			if (visit[v[cur][i]] == false)
			{
				q.push(v[cur][i]);
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
