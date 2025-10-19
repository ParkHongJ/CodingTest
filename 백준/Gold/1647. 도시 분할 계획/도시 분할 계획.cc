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

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 첫째 줄에 집의 개수 N, 길의 개수 M이 주어진다. N은 2이상 100,000이하인 정수이고, 
	// M은 1이상 1,000,000이하인 정수이다. 
	// 그 다음 줄부터 M줄에 걸쳐 길의 정보가 A B C 세 개의 정수로 주어지는데 
	// A번 집과 B번 집을 연결하는 길의 유지비가 C (1 ≤ C ≤ 1,000)라는 뜻이다.

	int N, M;
	cin >> N >> M;
	
	vector<vector<pair<int, int>>> v;
	v.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({ C,B });
		v[B].push_back({ C,A });
	}

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vector<bool> visit;
	visit.resize(N + 1, false);
	
	visit[1] = true;
	
	for (int i = 0; i < v[1].size(); ++i)
	{
		pq.push(v[1][i]);
	}
	int answer = 0;
	int last = 0;
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();
		if (visit[cur.second] == false)
		{
			visit[cur.second] = true;

			for (int i = 0; i < v[cur.second].size(); ++i)
			{
				pq.push(v[cur.second][i]);
			}
			answer += cur.first;
			last = max(last, cur.first);
		}
	}

	cout << answer - last << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
