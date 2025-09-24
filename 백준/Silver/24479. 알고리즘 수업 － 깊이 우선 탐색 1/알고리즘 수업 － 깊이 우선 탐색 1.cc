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
#pragma warning(disable :4996)
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };


void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, M, R;

	cin >> N >> M >> R;

	stack<int> s;
	
	vector<vector<int>> v;
	vector<bool> vis;
	vector<int> idx;
	vector<int> answer;

	v.resize(N + 1);
	vis.resize(N + 1);
	idx.resize(N + 1);
	answer.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		sort(v[i].begin(), v[i].end());		
	}

	s.push(R);

	vis[R] = true;

	int cnt = 1;
	
	answer[R] = cnt++;

	while (!s.empty())
	{
		int cur = s.top();
		int& i = idx[cur];
		
		if (i == v[cur].size())
		{
			s.pop();
			continue;
		}

		int point = v[cur][i++];
		if (vis[point] == false)
		{
			vis[point] = true;
			answer[point] = cnt++;
			s.push(point);
		}
	}

	for (int i = 1; i < answer.size(); ++i)
	{
		cout << answer[i] << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}