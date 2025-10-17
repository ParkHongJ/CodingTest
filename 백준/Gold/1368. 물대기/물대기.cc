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

int arr[100000];
bool isUsed[100000];

vector<int> p;
int find(int x)
{
	if (p[x] < 0)
	{
		return x;
	}
	return p[x] = find(p[x]);
}
bool uni(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
		return false;

	p[v] = u;
	return true;
}

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	
	// 첫 줄에는 논의 수 N(1 ≤ N ≤ 300)이 주어진다. 
	// 다음 N개의 줄에는 i번째 논에 우물을 팔 때 드는 비용 Wi(1 ≤ Wi ≤ 100,000)가 순서대로 들어온다. 
	// 다음 N개의 줄에 대해서는 각 줄에 N개의 수가 들어오는데 
	// 이는 i번째 논과 j번째 논을 연결하는데 드는 비용 
	// Pi,j(1 ≤ Pi,j ≤ 100,000, Pi,j = Pj,i, Pi,i = 0)를 의미한다.
	int N;
	cin >> N;
	
	// weight, from, to
	p.resize(N + 1, -1);

	priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

	for (int i = 0; i < N; ++i)
	{
		int weight;
		cin >> weight;
		pq.push({ weight, i, N });
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int weight;
			cin >> weight;

			if (i >= j)
				continue;

			pq.push({ weight, i, j });
		}
	}

	//첫 줄에 모든 논에 물을 대는데 필요한 최소비용을 출력한다.
	int answer = 0;
	int edge = 0;
	while (true)
	{
		int weight, from, to;
		tie(weight, from, to) = pq.top(); pq.pop();
		
		if (uni(to, from)) //유니온파인드가 성공했다면 (성공적으로 그룹에 등록되었다면)
		{
			//물을 대는데 필요한 비용을 더함.
			answer += weight;
			++edge;
		}

		if (N == edge)
		{
			break;
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
