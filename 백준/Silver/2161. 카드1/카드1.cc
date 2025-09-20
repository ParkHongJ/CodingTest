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

	int N;
	cin >> N;
	
	queue<int> q;

	for (int i = 1; i <= N; ++i)
	{
		q.push(i);
	}

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();

		if (q.size() > 1)
		{
			q.push(q.front());
			q.pop();
		}
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}