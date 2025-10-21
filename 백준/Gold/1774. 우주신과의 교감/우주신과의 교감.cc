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

	int N, M;
	cin >> N >> M;
	
	vector<pair<int, int>> v;
	v.resize(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		int x, y; 
		cin >> x >> y;
		v[i] = { x,y };
	}

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b; //이미 연결되어있는 두 점
		uni(a, b);
	}
	
	vector<tuple<double, int, int>> edge;
	
	//모든 정점을 돌면서 간선을 만들어야할것같은데
	for (int i = 1; i <= N; ++i)
	{
		for (int j = i + 1; j <= N; ++j)
		{
			long long dx = (long long)v[j].first - (long long)v[i].first;
			long long dy = (long long)v[j].second - (long long)v[i].second;
			double cost = sqrt((double)dx * dx + (double)dy * dy);
						
			edge.push_back({ cost, i, j });
		}
	}

	sort(edge.begin(), edge.end());

	double answer = 0;

	for (int i = 0; i < edge.size(); ++i)
	{
		double cost;
		int a, b;
		tie(cost, a, b) = edge[i];
		
		if (uni(a,b))
		{
			answer += cost;
		}
	}

	cout << fixed << setprecision(2);
	cout << answer << '\n';
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}