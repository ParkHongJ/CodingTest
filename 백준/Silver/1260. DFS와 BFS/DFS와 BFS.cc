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
#include <list>
#include <iomanip>
#include <math.h>
#pragma warning(disable :4996)
using namespace std;

void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, V;
	cin >> N >> M >> V;

	vector<vector<int>> graph(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (size_t i = 1; i <= N; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	queue<int> q;
	q.push(V);
	bool visit[1005] = { false };
	bool DFSvisit[1005] = { false };

	stack<int> s;
	s.push(V);

	while (!s.empty())
	{
		int cur = s.top(); s.pop();

		if (DFSvisit[cur] == true)
			continue;

		cout << cur << " ";
		DFSvisit[cur] = true;

		for (int i = graph[cur].size() - 1; i >= 0; --i)
		{
			s.push(graph[cur][i]);
		}
	}
	cout << '\n';
	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		if (visit[cur] == true)
			continue;

		cout << cur << " ";
		visit[cur] = true;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			q.push(graph[cur][i]);
		}
	}

}
int main()
{
	BackJoon();//출력할때 endl;넣자
	return 0;
}