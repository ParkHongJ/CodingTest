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
	
	int answer = 0;

	
	string str;
	cin >> str;
	
	vector<int> v;
	v.resize(10);

	//한 세트를 다 사용했는지 검사해야한다

	for (int i = 0; i < str.length(); ++i)
	{
		// 0 ~ 9
		int num = str[i] - '0';

		if (num == 6 || num == 9)
		{
			if (v[6] <= v[9])
			{
				++v[6];
			}
			else
			{
				++v[9];
			}
		}
		else 
		{
			++v[num];
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		answer = max(answer, v[i]);
	}

	cout << answer << '\n';

}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}