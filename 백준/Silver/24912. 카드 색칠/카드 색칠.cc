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

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

void BackJoon()
{
	
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	vector<int> cards(N);

	for (int i = 0; i < N; i++)
	{
		cin >> cards[i];
	}

	bool isAnswer = true;
	for (int i = 0; i < N; i++)
	{
		if (cards[i] != 0)
			continue;
		
		vector<bool> visit(5, false);

		if (i - 1 >= 0)
		{
			visit[cards[i - 1]] = true;

			if (i + 1 < N)
			{
				if (cards[i + 1] != 0)
				{
					visit[cards[i + 1]] = true;
				}
			}

			for (int j = 1; j <= 3; j++)
			{
				if (visit[j] == false)
				{
					cards[i] = j;
					break;
				}
			}
			if (cards[i] == 0)
			{
				isAnswer = false; 
				break;
			}
		}
		else
		{
			if (i + 1 < N)
			{
				if (cards[i + 1] != 0)
				{
					visit[cards[i + 1]] = true;
				}
			}

			for (int j = 1; j <= 3; j++)
			{
				if (visit[j] == false)
				{
					cards[i] = j;
					break;
				}
			}
			if (cards[i] == 0)
			{
				isAnswer = false;
				break;
			}
		}
	}

	if (isAnswer)
	{
		for (int i = 0; i < N; i++)
		{
			cout << cards[i] << " ";
		}
	}
	else
	{
		cout << -1 << '\n';
	}
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
