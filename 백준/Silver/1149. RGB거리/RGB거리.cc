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

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

enum Color
{
	R = 0,
	G = 1,
	B = 2
};
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	/*
	*	1. 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
		2. N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
		3. i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다
	*/

	// R G B = O
	// R R B = X
	// R B R = O
	// R B R B = O

	//집의 수 N과
	// 각 집을 칠하는데 드는 RGB비용 3개
	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(3));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> v[i][j];
		}
	}

	// 0 0 시작
	// ++i, j가 같으면 칠할 수 없다.

	vector<vector<int>> temp(v);

	for (int i = 1; i < N; i++)
	{
		temp[i][R] = min((temp[i - 1][B] + v[i][R]), (temp[i - 1][G] + v[i][R]));
		temp[i][G] = min((temp[i - 1][R] + v[i][G]), (temp[i - 1][B] + v[i][G]));
		temp[i][B] = min((temp[i - 1][G] + v[i][B]), (temp[i - 1][R] + v[i][B]));
	}

	cout << min(temp[N - 1][B], min(temp[N - 1][R], temp[N - 1][G])) << '\n';
	
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
