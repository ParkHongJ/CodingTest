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


	stack<int> s;
	int N;
    cin>>N;
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		if (input == 0)
		{
			s.pop();
		}
		else
			s.push(input);
	}

	long long answer = 0;
	while (!s.empty())
	{
		answer += s.top();
		s.pop();
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}