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

	// N개의 도시가 있고 M개의 두 도시를 연결하는 케이블의 정보와 
	// K개의 YNY발전소가 설치된 도시가 주어지면 케이블 설치 비용을 "최소"로 사용
	int N, M, K;
	cin >> N >> M >> K;

	vector<bool> Gen;
	Gen.resize(N + 1);

	for (size_t i = 0; i < K; ++i)
	{
		int genCity;
		cin >> genCity;
		Gen[genCity] = true;
	}
	
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({ w,u,v });
	}

	sort(edges.begin(), edges.end());
	int answer = 0;
	for (int i = 0; i < edges.size(); ++i)
	{
		int a, b, w;
		tie(w, a, b) = edges[i];

		int aroot = find(a);
		int broot = find(b);
		
		if (Gen[aroot] && Gen[broot])
			continue;

		if (Gen[aroot])
		{
			if (uni(a, b)) 
			{
				answer += w;
			}
		}
		else
		{
			if (uni(b,a))
			{
				answer += w;
			}
		}
	}
	cout << answer << '\n';
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}