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

	// 첫째 줄에 컴퓨터의 수 N (1 ≤ N ≤ 1000)가 주어진다.

	// 둘째 줄에는 연결할 수 있는 선의 수 M(1 ≤ M ≤ 100, 000)가 주어진다.

	// 셋째 줄부터 M + 2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어진다.
	// 이 비용의 정보는 세 개의 정수로 주어지는데, 만약에 a b c 가 주어져 있다고 하면 a컴퓨터와 b컴퓨터를 연결하는데 비용이 c(1 ≤ c ≤ 10, 000) 만큼 든다는 것을 의미한다.
	// a와 b는 같을 수도 있다.
	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> computer;
	computer.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a==b)
		{
			continue;
		}
		computer[a].push_back({ c,b });
		computer[b].push_back({ c,a });
	}
	vector<bool> visit;
	visit.resize(N + 1);
	visit[1] = true;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (size_t i = 0; i < computer[1].size(); ++i)
	{
		pq.push(computer[1][i]);
	}

	int answer = 0;
	int cnt = 0;
	while (!pq.empty() && cnt != N - 1)
	{
		pair<int, int> cur = pq.top(); pq.pop();
		if (visit[cur.second] == false)
		{
			visit[cur.second] = true;

			answer += cur.first;
			cnt++;
			for (int i = 0; i < computer[cur.second].size(); i++)
			{
				pq.push(computer[cur.second][i]);
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
