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

	// 첫째 줄에 도시의 개수 n이 주어지고 둘째 줄에는 버스의 개수 m이 주어진다. 
	// 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 
	// 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 
	// 버스의 정보는 버스의 시작 도시 a, 도착 도시 b, 한 번 타는데 필요한 비용 c로 이루어져 있다. 
	// 시작 도시와 도착 도시가 같은 경우는 없다. 비용은 100,000보다 작거나 같은 자연수이다.

	// 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.

	// 도시 A에서 B로 가는데 필요한 비용의 최솟값

	vector<vector<int>> D;
	int N, M;
	cin >> N >> M;
	D.resize(N + 1);

	const int aaa = 0x3f3f3f3f;
	for (int i = 1; i <= N; i++)
	{
		D[i].resize(N + 1, aaa);
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		D[a][b] = min(D[a][b], cost);
	}
	for (int i = 1; i <= N; i++)
	{
		D[i][i] = 0;
	}
	//거쳐가는정점 i
	for (int i = 1; i <= N; ++i)
	{
		for (int s = 1; s <= N; ++s)
		{
			for (int t = 1; t <= N; ++t)
			{
				D[s][t] = min(D[s][t], D[s][i] + D[i][t]);
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (D[i][j] >= aaa)
			{
				cout << "0" << " ";
			}
			else
			{
				cout << D[i][j] << " ";
			}
		}
		cout << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
