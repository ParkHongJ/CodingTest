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
int board[502][502];
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };


void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	while (!q.empty())
	{
		int first = q.front();
		q.pop();

		for (int i = 0; i < K - 1; ++i)
		{
			if (!q.empty()) 
			{
				q.pop();
			}
		}

		// 남아있는 청설모
		int left = q.size() + 1;

		// 남아있는 청설모가 K보다 작으면 첫번째를 제외한 모든게 사라진다.
		if (left < K)
		{
			if (q.empty())
			{
				cout << first;
			}
			else
			{
				cout << q.front();
			}
			break;
		}

		// 남아있는 청설모가 2마리 이상이면
		if (left >= 2)
		{
			q.push(first);
		}
		else
		{
			cout << q.front();
		}
	}
	/*int N, M, H;

	cin >> M >> N >> H;



	queue<pair<int, int>> q;
	
	vis[0][0] = 1;
	
	q.push({ 0,0 });
	
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
			if (vis[nx][ny] || board[nx][ny] != 1)
			{
				continue;
			}
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}*/
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}