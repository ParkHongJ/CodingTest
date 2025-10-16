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
#pragma warning(disable :4996)
using namespace std;


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0,0 };

void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	int N, M;
	cin >> N >> M;

	//i번째 노드와 연결된 노드들의 인덱스
	vector<vector<pair<int,int>>> Nodes;
	Nodes.resize(N + 1);

	for (int i = 0; i < N - 1; ++i)
	{
		int A, B, Dist;
		cin >> A >> B >> Dist;
		Nodes[A].push_back({ Dist, B});
		Nodes[B].push_back({ Dist, A});
		//정렬해도 ㄱㅊ아보임
	}

	for (int i = 1; i <= N; ++i)
	{
		sort(Nodes[i].begin(), Nodes[i].end());
	}

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B; //A와 B사이의 거리
		
		vector<bool> visit;
		visit.resize(N + 1, false);

		queue<int> q;
		q.push(A);
		
		int dist[10000] = { 0 };
		while (!q.empty())
		{
			int cur = q.front(); q.pop();

			visit[cur] = true;
			bool vis = false;
			for (int j = 0; j < Nodes[cur].size(); ++j)
			{
				int neighbor = Nodes[cur][j].second;

				if (visit[neighbor])
				{
					continue;
				}

				vis = true;
				
				dist[neighbor] = dist[cur] + Nodes[cur][j].first;

				q.push(neighbor);
			}
		}
		cout << dist[B] << '\n';
	}
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}