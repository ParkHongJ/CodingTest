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
	
	vector<vector<bool>> visit(6);
	for (int i = 0; i < 6; i++)
	{
		visit[i].resize(6, false);
	}

	//6 -> 0
	//5 -> 1
	//A -> 0
	//B -> 1
	pair<int, int> before;
	pair<int, int> st;
	{
		string s;
		cin >> s;
		int row = s[0] - 'A';
		int col = 6 - (s[1] - '0');

		visit[col][row] = true;
		before.first = col;
		before.second = row;
		st.first = col;
		st.second = row;
	}
	for (int i = 1; i < 36; i++)
	{
		string s;
		cin >> s;
		int col = 6 - (s[1] - '0');
		int row = s[0] - 'A';

		if ((abs(col - before.first) * abs(col - before.first) + 
			abs(row - before.second) * abs(row - before.second)) != 5)
		{
			cout << "Invalid" << '\n';
			return;
		}

		if (i == 35)
		{
			if ((abs(col - st.first) * abs(col - st.first) +
				abs(row - st.second) * abs(row - st.second)) != 5)
			{
				cout << "Invalid" << '\n';
				return;
			}
		}
		if (visit[col][row] == false)
		{
			visit[col][row] = true;
			before.first = col;
			before.second = row;
		}
		else
		{
			cout << "Invalid" << '\n';
			return;
		}
	}
	cout << "Valid" << '\n';
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
