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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int direction = 0;
	
	int M, N;
	cin >> M >> N;

	pair<int, int> cur = { 0,0 };

	while (N--)
	{
		string command;
		cin >> command;
		
		if (command == "MOVE")
		{
			int d;
			cin >> d;

			int nx = cur.first + dx[direction] * d;
			int ny = cur.second + dy[direction] * d;

			if (nx < 0 || ny < 0 || nx > M || ny > M)
			{
				cout << -1 << '\n';
				return;
			}

			cur.first = nx;
			cur.second = ny;
		}
		else
		{
			int dir;
			cin >> dir;

			// TURN 0 명령은 현재 위치에서 왼쪽으로 90도 회전, 
			// TURN 1 명령은 현재 위치에서 오른쪽으로 90도 회전

			if (dir == 0)
			{
				direction = (direction + 3) % 4;
			}
			else
			{
				direction = (direction + 1) % 4;
			}
		}
	}

	cout << cur.first << " " << cur.second << '\n';
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
