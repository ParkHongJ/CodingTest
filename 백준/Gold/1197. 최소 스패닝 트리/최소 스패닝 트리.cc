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

//부모 정점이 저장된 배열을 p
vector<int> p(100005, -1);
//정점x의 그룹
int find(int x)
{
	if (p[x] < 0)
	{
		return x;
	}
	else
	{
		return p[x] = find(p[x]);
	}
}
bool uni(int u, int v)
{
	int uRoot = find(u);
	int vRoot = find(v);

	if (uRoot == vRoot)
		return false;

	p[vRoot] = uRoot; 
	return true;
}

void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 
	// 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 
	// 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 
	// 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. 
	// C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

	// 그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 
	// 임의의 두 정점 사이에 경로가 있다.
	// 최소 스패닝 트리의 가중치가 - 2, 147, 483, 648보다 크거나 같고, 2, 147, 483, 647보다 작거나 같은 데이터만 입력으로 주어진다.

	int V, E;
	cin >> V >> E;

	vector<tuple<int, int, int>> graph; 
	for (int i = 0; i < E; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		graph.push_back({ C, A, B });
	}
	
	sort(graph.begin(), graph.end());

	long answer = 0;

	for (int i = 0; i < graph.size(); ++i)
	{
		int weight = get<0>(graph[i]);

		if (uni(get<1>(graph[i]), get<2>(graph[i])) == false)
		{
			continue;
		}

		answer += weight;
	}
	cout << answer << '\n';
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}