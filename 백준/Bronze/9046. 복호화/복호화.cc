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

	int N;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; ++i)
	{
		string str;
		getline(cin, str);

		vector<int> v;
		v.resize('z' - 'a' + 1);

		int maxValue = 0;
		for (int j = 0; j < str.length(); ++j)
		{
			if (str[j] != ' ')
			{
				int index = str[j] - 'a';
				++v[index];

				maxValue = max(maxValue, v[index]);
			}
		}

		bool bEqual = false;
		bool btmp = false;
		int maxIndex = 0;
		for (int j = 0; j < v.size(); ++j)
		{
			if (v[j] == maxValue && bEqual)
			{
				btmp = true;
				break;
			}
			if (v[j] == maxValue)
			{
				bEqual = true;
				maxIndex = j;
			}
		}
		if (btmp)
		{
			cout << '?' << '\n';
		}
		else
		{
			cout << (char)(maxIndex + 'a') << '\n';
		}
		
	}
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}