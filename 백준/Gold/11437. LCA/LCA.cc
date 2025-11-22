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

vector<int> depth;
vector<int> parent;

vector<vector<int>> adj;
void func(int root, int d);
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;

	//i번째 정점의 현재 깊이

	depth.resize(N + 1);
	adj.resize(N + 1);
	parent.resize(N + 1);
	
	parent[1] = 1;
	depth[1] = 0;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	func(1, 0);
	int test = 0;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a == b)
		{
			cout << a << '\n';
			continue;
		}
		while (true)
		{
			if (depth[a] != depth[b])
			{
				if (depth[a] > depth[b])
				{
					if (parent[a] == b)
					{
						cout << parent[a] << '\n';
						break;
					}
					a = parent[a];
				}
				else
				{
					if (parent[b] == a)
					{
						cout << parent[b] << '\n';
						break;
					}
					b = parent[b];
				}
			}

			if (parent[a] == parent[b])
			{
				cout << parent[a] << '\n';
				break;
			}

			if (depth[a] == depth[b])
			{
				a = parent[a];
				b = parent[b];
			}
		}
	}
}
void func(int root, int d)
{
	int level = d + 1;
	for (int i = 0; i < adj[root].size(); ++i)
	{
		int neighbor = adj[root][i];
		
		//이미 부모가 설정되어있으면
		if (parent[root] != 0 && parent[neighbor] == 0)
		{
			parent[neighbor] = root;
			depth[neighbor] = d + 1;
			func(neighbor, d + 1);
		}
	}
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
