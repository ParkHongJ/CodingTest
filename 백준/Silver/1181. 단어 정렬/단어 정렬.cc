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

	
	vector<vector<string>> answer;
	answer.resize(51);
	
	int N;
	cin >> N;

	set<string> s;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		if (s.find(str) == s.end())
		{
			answer[str.length()].push_back(str);
			s.insert(str);
		}
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		sort(answer[i].begin(), answer[i].end());
		for (int j = 0; j < answer[i].size(); ++j)
		{
			cout << answer[i][j] << '\n';
		}
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}