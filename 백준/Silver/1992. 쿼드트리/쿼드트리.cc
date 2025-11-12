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

//상우하좌
//왼상오상 왼하 오하 
//아래방향은 없다
int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1};
int dy[8] = { -1, 0, 0, 0, -1, -1, 1, 1};

int N;
vector<string> board;
string answer;

void func(int x, int y, int width);
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	cin >> N;

	board.resize(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}

	func(0, 0, N);
	cout << answer << '\n';
}
void func(int x, int y, int width)
{
	if (x < 0 || y < 0)
		return;

	bool exit = false; //영역 안에 흑백이 섞여있다면

	char color = '2';

	for (int i = y; i < y + width; ++i)
	{
		for (int j = x; j < x + width; ++j)
		{
			if (color == '2')
			{
				color = board[i][j];
			}
			if (board[i][j] != color)
			{
				exit = true;
				break;
			}
		}
		if (exit)
			break;
	}

	//좌상 우상 좌하 우하 
	if (exit)
	{
		answer += '(';
		width = width / 2;
		func(x, y, width);
		func(x + width, y, width);
		func(x, y + width, width);
		func(x + width, y + width, width);
		answer += ')';
	}
	else
	{
		if (color == '0')
		{
			answer += '0';
		}
		else
			answer += '1';
	}
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
