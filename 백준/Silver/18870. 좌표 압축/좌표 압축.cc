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

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	vector<int> v(N);
	
	unordered_map<int, int> m;
	set<int> s;
	vector<int> sorted;
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		m.insert({ v[i], -1 });
		auto iter = s.insert(v[i]);
		if (iter.second)
		{
			sorted.push_back(v[i]);
		}
	}

	sort(sorted.begin(), sorted.end());

	for (int i = 0; i < N; ++i)
	{
		//나보다 작은걸 찾은적이 없다면
		if (m[v[i]] < 0)
		{
			int idx = lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin();
			m[v[i]] = idx;
		}

		cout << m[v[i]] << " ";
	}
	
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
