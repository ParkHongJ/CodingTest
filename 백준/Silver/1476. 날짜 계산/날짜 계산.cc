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
	
	int E, S, M;
	cin >> E >> S >> M;

	int A = 0, B = 0, C = 0;
	int answer = 0;
	while (true)
	{
		if (A == E && B == S && C == M)
		{
			break;
		}

		++A;
		++B;
		++C;

		if (A > 15)
		{
			A = 1;
		}
		if (B > 28)
		{
			B = 1;
		}
		if (C > 19)
		{
			C = 1;
		}

		++answer;
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}