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
	
	int N, M;
	//큐의 크기 N과 뽑아내려고 하는 수의 개수 M
	cin >> N >> M;

	deque<int> dq;
	for (int i = 1; i <= N; ++i)
	{
		dq.push_back(i);
	}
	queue<int> q;
	for (int i = 0; i < M; ++i)
	{
		int target = 0;
		cin >> target;
		q.push(target);
	}

	int answer = 0;
	while (!q.empty())
	{
		int target = q.front(); q.pop();
		
		int pos = 0;

		for (int i = 0; i < dq.size(); ++i) 
		{
			if (dq[i] == target) 
			{
				pos = i; 
				break; 
			}
		}

		if (pos <= (int)dq.size() / 2) 
		{
			// 왼쪽 회전
			while (pos--) 
			{
				dq.push_back(dq.front());
				dq.pop_front();
				++answer;
			}
		}
		else 
		{
			// 오른쪽 회전 
			int r = dq.size() - pos;
			while (r--) 
			{
				dq.push_front(dq.back());
				dq.pop_back();
				++answer;
			}
		}

		// 이제 target이 맨 앞
		dq.pop_front();
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}