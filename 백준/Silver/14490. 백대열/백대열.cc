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

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	string s;
	cin >> s;

	int N, M;
	bool toggle = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ':')
		{
			string t = s.substr(0, i);
			N = stoi(t);
			t = s.substr(i + 1, s.length() - i);
			M = stoi(t);
			break;
		}
	}
	while (true)
	{
		int temp = min(N, M);
		int a = 1;

		int t = 0;
		while (a <= temp)
		{
			if (N % a == 0 && M % a == 0)
			{
				t = a;
			}
			++a;
		}

		if (t == 1)
		{
			break;
		}
		N /= t;
		M /= t;
	}
	cout << N << ":" << M << '\n';
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
