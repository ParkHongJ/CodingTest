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

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		stack<char> temp;

		for (int j = 0; j < str.size(); ++j)
		{
			if (temp.empty())
			{
				temp.push(str[j]);
				continue;
			}
			if (temp.top() == str[j])
			{
				temp.pop();
				continue;
			}
			temp.push(str[j]);
		}
		if (temp.empty())
		{
			answer++;
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