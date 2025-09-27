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

	string str;
	cin >> str;

	int cnt = 0;
	string answer;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.')
		{
			if (cnt % 2 != 0)
			{
				cout << -1 << '\n'; 
				return;
			}

			int A = cnt / 4;
			int B = (cnt - (A * 4)) / 2;
			cnt = 0;

			for (int j = 0; j < A; ++j)
			{
				answer += "AAAA";
			}
			for (int j = 0; j < B; ++j)
			{
				answer += "BB";
			}
			answer = answer + str[i];
		}
		else
		{
			++cnt;
		}
	}

	if (cnt != 0)
	{
		if (cnt % 2 != 0)
		{
			cout << -1 << '\n';
			return;
		}
		int A = cnt / 4;
		int B = (cnt - (A * 4)) / 2;
		cnt = 0;

		for (int j = 0; j < A; ++j)
		{
			answer += "AAAA";
		}
		for (int j = 0; j < B; ++j)
		{
			answer += "BB";
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