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

//우좌상하
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	vector<int> d;
	d.resize(200005, -1);

	int N, M;
	cin >> N >> M;

	//현재 좌표
	queue<int> q;
	q.push(N);

	d[N] = 0;
	while (d[M] == -1)
	{
		int cur = q.front(); q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (nxt < 0 || nxt>100000) continue;
			if (d[nxt] != -1) continue;
			d[nxt] = d[cur] + 1;
			q.push(nxt);
		}
	}
	cout << d[M] << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
