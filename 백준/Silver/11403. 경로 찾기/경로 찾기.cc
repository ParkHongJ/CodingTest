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
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N));
	vector<vector<int>> answer(N, vector<int>(N, 0));

	vector<vector<int>> Edges(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 1)
			{
				Edges[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			//i에서 j로 가는 길이 있는가?

			vector<bool> visit(N);

			queue<int> q;
			q.push(i);

			bool bFound = false;
			while (!q.empty() && !bFound)
			{
				int cur = q.front(); q.pop();

				if (visit[cur] == true)
					continue;

				visit[cur] = true;

				for (int k = 0; k < Edges[cur].size(); ++k)
				{
					//도착점
					if (Edges[cur][k] == j)
					{
						answer[i][j] = 1;
						bFound = true;
						break;
					}

					if (visit[Edges[cur][k]] == true)
						continue;

					q.push(Edges[cur][k]);
				}
			}
			
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << answer[i][j] << " ";
		}
		cout << '\n';
	}
}


int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
