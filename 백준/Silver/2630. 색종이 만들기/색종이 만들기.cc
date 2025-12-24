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
#include <cmath>
#pragma warning(disable :4996)
using namespace std;

vector<vector<int>> board;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int white = 0;
int blue = 0;

void func(int x, int y, int n);
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;

	board.resize(N);

	for (int i = 0; i < N; i++)
	{
		board[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	func(0,0, N);

	cout << white << '\n';
	cout << blue << '\n';
}

void func(int x, int y, int n)
{
	int pivot = board[y][x];
	
	bool same = true;
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (pivot != board[i][j])
			{
				same = false;
				break;
			}
		}

		if (!same)
			break;
	}

	if (same)
	{
		if (pivot == 1)
		{
			++blue;
		}
		else
		{
			++white;
		}
	}
	else
	{
		int nxt = n / 2;
		func(x, y, nxt);
		func(x + nxt, y, nxt);
		func(x, y + nxt, nxt);
		func(x + nxt, y + nxt, nxt);
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
