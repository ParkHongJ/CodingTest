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
	

	int N;
	cin >> N;

	//길이, 자릿수의 합(숫자만), 사전순
	vector<tuple<int, int, string>> v;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		
		tuple<int, int, string> t;
		
		int length = str.length();
		int sum = 0;
		
		for (int j = 0; j < str.length(); ++j)
		{
			if (str[j] >= '0' && str[j] <= '9')
			{
				sum += str[j] - '0';
			}
		}

		t = make_tuple(length, sum, str);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		cout << get<2>(v[i]) << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}