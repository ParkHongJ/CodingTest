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

vector<int> v;
vector<vector<bool>> command;
long maxanswer = 0;
long minanswer = 0;

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 오르막길인 경우 점선, 내리막길인 경우 실선
	// 점선 -> 실선은 가능하지만
	// 실선 -> 점선루트는 불가능하다.

	// 최악, 최선의 경로 간 피로도의 차이를 계산
	// 입력의 첫 번째 줄에는 건물의 개수 N(1 ≤ N ≤ 1,000)과 도로의 개수 M(1 ≤ M ≤ N(N-1)/2) 이 주어진다. 
	// 입력의 두 번째 줄부터 M+1개의 줄에는 A, B(1 ≤ A, B ≤ N), C 가 주어진다. 
	// 이는 A와 B 건물에 연결된 도로가 있다는 뜻이며, C는 0(오르막길) 또는 1(내리막길)의 값을 가진다. 
	// 같은 경로 상에 2개 이상의 도로가 주어지는 경우는 없으며, 입구는 항상 1번 건물과 연결되어 있다. 
	// 입구와 1번 도로 간의 연결 관계는 항상 2번째 줄에 주어진다. 
	// 입구에서 모든 건물로 갈 수 있음이 보장된다.

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> v;
	v.resize(N + 1);

	for (int i = 0; i < M + 1; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({ C,B });
		v[B].push_back({ C,A });
	}

	vector<bool> visit;
	visit.resize(N + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	visit[0] = true;

	for (int i = 0; i < v[0].size(); ++i)
	{
		pq.push(v[0][i]);
	}

	int weight = 0;
	int best = 0;
	
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();
		
		if (visit[cur.second] == false)
		{
			visit[cur.second] = true;

			
			if (cur.first == 0)
			{
				++weight;
			}

			for (int i = 0; i < v[cur.second].size(); ++i)
			{
				//이전에 내리막으로 왔고 현재 길이 오르막이라면 성립 불가.
				pair<int, int> neighbor = v[cur.second][i];
				if (visit[neighbor.second])
					continue;

				pq.push(v[cur.second][i]);
			}
		}
	}
	best += weight * weight;

	int worst = 0;
	weight = 0;
	
	visit.clear();
	visit.resize(N + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> worstpq;

	visit[0] = true;
	for (int i = 0; i < v[0].size(); ++i)
	{
		worstpq.push(v[0][i]);
	}

	while (!worstpq.empty())
	{
		pair<int, int> cur = worstpq.top(); worstpq.pop();

		if (visit[cur.second] == false)
		{
			visit[cur.second] = true;


			if (cur.first == 0)
			{
				++weight;
			}

			for (int i = 0; i < v[cur.second].size(); ++i)
			{
				//이전에 내리막으로 왔고 현재 길이 오르막이라면 성립 불가.
				pair<int, int> neighbor = v[cur.second][i];
				if (visit[neighbor.second])
					continue;

				worstpq.push(v[cur.second][i]);
			}
		}
	}
	worst = weight * weight;
	cout << abs(best - worst) << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
