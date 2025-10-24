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

	int N, M, R;
	cin >> N >> M >> R;
	const int maxint = 0x3f3f3f3f;
	vector<vector<int>> D;
	D.resize(N + 1);
	
	vector<vector<int>> next;
	next.resize(N + 1);

	//i번째 지역에 있는 아이템의 수
	vector<int> items;
	items.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		D[i].resize(N + 1, maxint);
		next[i].resize(N + 1);
	}
	for (int i = 1; i <= N; ++i) D[i][i] = 0;
	for (int i = 1; i <= N; i++)
	{
		int item;
		cin >> item;
		items[i] = item;
	}

	for (int i = 0; i < R; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		if (l < D[a][b]) 
		{
			D[a][b] = l;
			D[b][a] = l;
		}
		next[a][b] = b;
		next[b][a] = a;
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (D[i][k] >= maxint || D[k][j] >= maxint)
					continue;
				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}

	int answer = 0;
	
	//  지역에 착지했을때.
	for (int land = 1; land <= N; ++land)
	{
		int sum = 0;
		for (int dest = 1; dest <= N; ++dest)
		{
			if (D[land][dest] <= M)
			{
				sum += items[dest];
			}
		}
		if (sum > answer) answer = sum;
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
