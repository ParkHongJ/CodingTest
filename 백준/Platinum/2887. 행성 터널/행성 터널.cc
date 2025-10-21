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

void func(int m)
{
	//if (m == N)
	//{
	//	string str;
	//	for (int i = 0; i < K; i++)
	//	{
	//		str += to_string(arr[i]);
	//	}

	//	//중복이 아니라면
	//	if (s.find(str) == s.end())
	//	{
	//		++answer;
	//		s.insert(str);
	//	}
	//	return;
	//}

	//for (int i = 0; i < N; ++i)
	//{
	//	if (isUsed[i] == false)
	//	{
	//		arr[m] = v[i];
	//		isUsed[i] = true;
	//		func(m + 1);
	//		isUsed[i] = false;
	//	}
	//}
}
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
vector<int> networkOptimization(int numRegions, int numConnections, int numTypes,
	const vector<int>& fromRegion,
	const vector<int>& toRegion,
	const vector<int>& connectionType)
{
	p.resize(numRegions + 1, -1);

	//numRegions 노드의 수
	//numConnections 모든 간선의 수
	//numTypes 연결 유형 수

	vector<vector<pair<int, int>>> v;
	v.resize(numTypes);

	//i번째 정점의 인접한 type과 목적지
	vector<vector<pair<int, int>>> graph;
	graph.resize(numRegions);

	for (int i = 0; i < numConnections; ++i)
	{
		int type = connectionType[i];
		
		v[type].push_back({ fromRegion[i], toRegion[i] });
		graph[fromRegion[i]].push_back({ type, toRegion[i] });
		graph[toRegion[i]].push_back({ type, fromRegion[i] });
	}


	//각 유형에 대한 루프
	for (int type = 0; type < v.size(); ++type)
	{
		//각 유형별 그룹을 만드는 루프
		for (int j = 0; j < v[type].size(); ++j)
		{
			// 유형별 간선의 정보가 뒤죽박죽이다. 
			// 단순히 루프를 통해 그룹을 구현하는건 별로다. 전체적 간선정보를 만드는게 나을듯.
			// DFS나 BFS로 찾으면 좋을듯?
			int from = v[type][j].first;
			int to = v[type][j].second;
			
			// 정점의 이웃들을 검사한다.
			for (int i = 0; i < graph[from].size(); i++)
			{
				int graphType = graph[from][i].first;

				//현재 정점과 연결된 유형이 같은 이웃만 검사
				if (type != graphType)
					continue;


			}
		}
	}
	return vector<int>();
}
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 첫째 줄에 행성의 개수 N이 주어진다. (1 ≤ N ≤ 100,000) 다음 N개 줄에는 각 행성의 x, y, z좌표가 주어진다. 
	// 좌표는 -10^9보다 크거나 같고, 10^9보다 작거나 같은 정수이다. 
	// 한 위치에 행성이 두 개 이상 있는 경우는 없다. 
	int N;
	cin >> N;

	
	vector<pair<long long, int>> planetx;
	vector<pair<long long, int>> planety;
	vector<pair<long long, int>> planetz;
	
	vector<tuple<long long, long long, long long>> planet;
	planet.resize(N);

	for (int i = 0; i < N; ++i)
	{
		long long x, y, z;
		cin >> x >> y >> z;
		planetx.push_back({ x, i });
		planety.push_back({ y, i });
		planetz.push_back({ z, i });
		planet[i] = { x,y,z };
	}

	// i번째 행성과 연결되어있는 이웃간선
	vector<vector<pair<long long, int>>> edges;
	edges.resize(N);

	//가까운 정점부터 순서대로
	sort(planetx.begin(), planetx.end());

	for (int i = 0; i < N - 1; ++i)
	{
		int from = planetx[i].second;
		int to = planetx[i + 1].second;
		edges[from].push_back({ abs(get<0>(planet[from]) - get<0>(planet[to])), to});
		edges[to].push_back({ abs(get<0>(planet[from]) - get<0>(planet[to])), from });
	}

	sort(planety.begin(), planety.end());
	for (int i = 0; i < N - 1; ++i)
	{
		int from = planety[i].second;
		int to = planety[i + 1].second;
		edges[from].push_back({ abs(get<1>(planet[from]) - get<1>(planet[to])), to });
		edges[to].push_back({ abs(get<1>(planet[from]) - get<1>(planet[to])), from });
		from = to;
	}

	sort(planetz.begin(), planetz.end());
	for (int i = 0; i < N - 1; ++i)
	{
		int from = planetz[i].second;
		int to = planetz[i + 1].second;
		edges[from].push_back({ abs(get<2>(planet[from]) - get<2>(planet[to])), to });
		edges[to].push_back({ abs(get<2>(planet[from]) - get<2>(planet[to])), from });
		from = to;
	}
	long long answer = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	vector<bool> visit;
	visit.resize(N, false);
	visit[0] = true;

	for (int i = 0; i < edges[0].size(); ++i)
	{
		pq.push(edges[0][i]);
	}

	while (!pq.empty())
	{
		pair<long long, int> cur = pq.top(); pq.pop();

		if (visit[cur.second])
			continue;

		visit[cur.second] = true;
		
		answer += cur.first;

		for (int i = 0; i < edges[cur.second].size(); ++i)
		{
			pq.push(edges[cur.second][i]);
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
