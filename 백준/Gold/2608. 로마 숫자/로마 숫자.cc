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

	string a, b;
	cin >> a >> b;
	v.resize(10000);
	v['I'] = 1;
	v['V'] = 5;
	v['X'] = 10;
	v['L'] = 50;
	v['C'] = 100;
	v['D'] = 500;
	v['M'] = 1000;
	//보통 큰 숫자를 왼쪽에 작은 숫자를 오른쪽에 쓴다. 그리고 그 값은 모든 숫자의 값을 더한 값이 된다. 
	// 예를 들어 LX = 50 + 10 = 60 이 되고, MLI = 1000 + 50 + 1 = 1051 이 된다.
	// I	V	X	L	C	D	M
	// V L D 1번 나머지 3번
	int sum = GetValue(a) + GetValue(b);

	cout << sum << '\n';
	const int    V[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
	static const string S[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
	
	string answer;
	for (int i = 0; i < 13; ++i)
	{
		while (sum >= V[i])
		{
			sum -= V[i]; answer += S[i];
		}
	}
	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
