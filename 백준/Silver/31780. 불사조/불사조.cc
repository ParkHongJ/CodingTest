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
#include <unordered_set>
#pragma warning(disable :4996)
using namespace std;

//우좌상하
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

bool visit[105] = { false };

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	long long X, M;
	cin >> X >> M;
	//조상포닉스 마력 X
	//명령횟수 M

	//명령이 1회 생길 때 마다 마력 (X = X / 2) (X = X / 2)
	//

	long long answer = 0;
	
	queue<pair<pair<int,int>, int>> q;
	
	q.push({ {0, X}, 0 });
	vector<bool> visit;
	visit.resize(2100000, false);
	int depth = 0;
	int cnt = 0;

	//i번째 단계
	while (!q.empty())
	{
		pair<pair<int, int>, int> cur = q.front(); q.pop();
		int magic = cur.first.second / 2;
if (cur.first.first >= visit.size())
	continue;
		if (visit[cur.first.first] == true)
			continue;

		if (cur.second > M)
			continue;

		visit[cur.first.first] = true;

		answer += cur.first.second;

		q.push({ { ++cnt, magic}, cur.second + 1 });
		q.push({ { ++cnt, cur.first.second - magic }, cur.second + 1 });
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
