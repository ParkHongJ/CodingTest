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
	
	//모든 원소가 양의 정수인 집합이 있을 때, 
	// 원소를 거꾸로 뒤집고 그 원소를 오름차순으로 정렬하는 프로그램을 작성하세요

	long N;
	cin >> N;

	vector<long> v;
	for (long i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		int first = 0;
		int last = str.length() - 1;
		while (first < last)
		{
			if (first >= str.length() || last < 0 || first == last)
			{
				break;
			}
			char temp = str[first];
			str[first] = str[last];
			str[last] = temp;
			
			++first;
			--last;
		}
		string temp;

		bool bZero = false;
		for (int j = 0; j < str.length(); ++j)
		{
			//처음 0을 만나면
			
			if (str[j] == '0' && !bZero)
			{
				continue;
			}
			else
			{
				temp += str[j];
				bZero = true;
			}
		}

		if (!temp.empty())
		{
			v.push_back(stoll(temp));
		}
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}