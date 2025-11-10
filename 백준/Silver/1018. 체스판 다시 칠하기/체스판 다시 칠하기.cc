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

#define X second 
#define Y first 

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<string> board;
	board.resize(N);
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		board[i] = s;
	}

	int answer = 0x7f7f7f7f;
	for (int l = 0; l < N; l++)
	{
		if (l + 7 >= N)
			continue;
		for (int m = 0; m < M; m++)
		{
			if (m + 7 >= M)
				continue;
			vector<string> tempBoard;
			tempBoard.resize(8);
			for (int row = 0; row < 8; row++)
			{
				tempBoard[row] = board[l + row].substr(m, m + 8);
			}
			for (int i = 0; i < 2; i++)
			{
				bool black = (bool)i;
				int cnt = 0;
				bool fillBlack = black;
				for (int j = 0; j < 8; j++)
				{
					for (int k = 0; k < 8; k++)
					{
						if (tempBoard[j][k] == 'B' && !fillBlack)
						{
							++cnt;
						}
						if (tempBoard[j][k] == 'W' && fillBlack)
						{
							++cnt;
						}
						fillBlack = !fillBlack;
					}
					fillBlack = !fillBlack;
				}
				answer = min(answer, cnt);
			}
		}
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
