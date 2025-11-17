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
	
	int N;
	cin >> N;

	vector<int> v(N);
	vector<int> hol;
	vector<int> jak;
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];

		if (i % 2 == 0)
		{
			hol.push_back(v[i]);
		}
		else
		{
			jak.push_back(v[i]);
		}
	}

	sort(hol.begin(), hol.end());
	sort(jak.begin(), jak.end());

	int tmp = 0;
	for (int i = 0; i < hol.size(); ++i, tmp += 2)
	{
		v[tmp] = hol[i];
	}

	tmp = 1;
	for (int i = 0; i < jak.size(); ++i, tmp += 2)
	{
		v[tmp] = jak[i];
	}

	bool sorted = true;

	for (int i = 1; i < N; ++i)
	{
		if (v[i] < v[i - 1])
		{
			sorted = false;
			break;
		}
	}

	if (sorted)
	{
		cout << "YES" << '\n';
	}
	else
	{
		cout << "NO" << '\n';
	}
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
