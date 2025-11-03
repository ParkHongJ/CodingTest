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

	int N, K;
	cin >> N >> K;
	string s;
	
	vector<int> number;
	while (N--)
	{
		char input;
		cin >> input;
		s += input;
		number.push_back(input - '0');
	}
	sort(number.begin(), number.end());
	string compare;
	for (int i = 0; i < number.size(); i++)
	{
		compare += number[i] + '0';
	}
	queue<pair<string, int>> q;
	
	
	unordered_set<string> visit;

	int answer = 0;

	q.push({ s, 0 });

	while (!q.empty())
	{
		pair<string,int> cur = q.front(); q.pop();
		
		if (cur.first == compare)
		{
			cout << cur.second << '\n';
			return;
		}
		for (int i = 0; i <= s.length() - K; i++)
		{
			string num1 = cur.first.substr(0, i);
			string num2 = cur.first.substr(i, K);
			string num4 = cur.first.substr(i + K, cur.first.length());
			
			reverse(num2.begin(), num2.end());

			string num3 = num1 + num2 + num4;

			if (visit.find(num3) != visit.end())
			{
				//이미 방문했다면
				continue;
			}
			visit.insert(num3);

			q.push({ num3, cur.second + 1 });
		}
	}

	cout << -1 << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
