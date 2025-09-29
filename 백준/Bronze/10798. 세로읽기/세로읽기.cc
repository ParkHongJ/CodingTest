#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#include <cassert>
#pragma warning(disable :4996)
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0,0 };

void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<string> v;

	string answer = "";

	int maxlength = 0;
	for (int i = 0; i < 5; i++)
	{
		string str;
		getline(cin, str);

		v.push_back(str);
		maxlength = max(maxlength, (int)str.length());
	}
	for (int i = 0; i < 5; i++)
	{
		if (v[i].length() < maxlength)
		{
			int dest = maxlength - v[i].length();
			for (int j = 0; j < dest; ++j)
			{
				v[i] += " ";
			}
		}
	}
	for (int i = 0; i < v[0].length(); ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (v[j][i] != ' ')
			{
				answer += v[j][i];
			}
		}
	}
	cout << answer << '\n';
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}