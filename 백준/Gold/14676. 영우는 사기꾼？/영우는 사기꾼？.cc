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
#pragma warning(disable :4996)
using namespace std;

//우좌상하
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

bool visit[15] = { false };

int answer = 0;
vector<int> v;

int GetValue(string s)
{
	int t = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		int cur = s[i];

		if (i + 1 < s.length())
		{
			int nxt = s[i + 1];
			
			if (v[cur] > v[nxt])
			{
				t += v[cur];
			}
			else if (v[cur] == v[nxt])
			{
				//연속된 문자라면 더함
				int cnt = 0;
				while (i + cnt < s.length())
				{
					t += v[cur];
					nxt = s[i + ++cnt];
					if (cur != nxt)
					{
						break;
					}
				}
				i += cnt - 1;
			}
			else // 왼쪽 로마자가 오른쪽보다 작은경우
			{
				t += v[nxt] - v[cur];
				++i;
			}
		}
		else
		{
			t += v[cur];
		}

		//int nxt = s[i + 1];

		//if (v[cur] > v[nxt])
		//{
		//	t += v[cur];
		//}
		//else if (v[cur] == v[nxt])
		//{
		//	//연속된 문자라면 더함
		//	int cnt = 1;
		//	int num = 0;
		//	while (cur == nxt && i + cnt <= s.length())
		//	{
		//		t += v[cur];
		//		nxt = s[i + cnt];
		//		++cnt;
		//		++num;
		//	}
		//	i += num - 1;
		//}
		//else // 왼쪽 로마자가 오른쪽보다 작은경우
		//{
		//	t += v[nxt] - v[cur];
		//	++i;
		//	if (i + 1 >= s.length())
		//	{
		//		continue;
		//	}
		//}
		//if (i + 1 >= s.length())
		//{
		//	t += v[nxt];
		//}
	}
	return t;
}
string GetValue(int a)
{
	string s;
	if (v['M'] >= a)
	{
		a /= v['M'];
		s.push_back('M');
	}
	return string();
}
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	//사전 작업에 대한 정보
	vector<vector<int>> v;
	v.resize(N + 1);
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 0; i < v.size(); i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	vector<int> buildInfo;
	buildInfo.resize(N + 1);

	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a == 1)
		{
			// 건설
			if (!v[b].empty()) //건물 b를 건설하기 위해 사전작업이 필요한가?
			{
				//사전작업 검사
				
				for (int j = 0; j < v[b].size(); j++)
				{
					//사전에 필요한 j 건물이 건설되지 않았다면
					if (buildInfo[v[b][j]] <= 0)
					{
						cout << "Lier!" << '\n';
						return;
					}
				}
			}
			//바로 건설
			++buildInfo[b];
		}
		else
		{
			// 파괴
			// 건물이 안지어져있다면
			if (buildInfo[b] <= 0)
			{
				cout << "Lier!" << '\n'; 
				return;
			}
			--buildInfo[b];
		}
	}
	cout << "King-God-Emperor" << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
