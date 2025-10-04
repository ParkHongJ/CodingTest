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
	vector<long long> v;
	for (int i = 0; i < N; ++i)
	{
		long long input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	//어느숫자가 몇번 불렸는지
	vector<pair<int, long long>> answer;
	
	pair<int, long long> p = { 1, v[0] };
	
	for (int i = 1; i < v.size(); ++i)
	{
		if (p.second != v[i])
		{
			answer.push_back(p);
			p.first = 1;
			p.second = v[i];
		}
		else
		{
			++p.first;
		}

		if (v.size() - 1 == i)
		{
			answer.push_back(p);
		}
	}

	sort(answer.begin(), answer.end(), [](const pair<int, long long>& A, const pair<int, long long>& B){
		if (A.first == B.first)
		{
			return A.second < B.second;
		}
		return A.first > B.first;
	});

	if (answer.empty())
	{
		cout << v[0] << '\n';
	}
	else
	{
		cout << answer[0].second << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}