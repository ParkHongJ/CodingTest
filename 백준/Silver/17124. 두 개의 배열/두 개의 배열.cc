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

	/*
	* 첫 줄에 테스트 케이스의 수 T (1 <= T <= 10)가 주어진다.

각 테스트 케이스는 세 줄에 걸쳐서 주어진다.

첫 줄에는 n과 m이 공백으로 구분되어 주어진다 (1 <= n, m <= 10^6).

두 번째 줄에는 공백으로 구분된 n개의 정수가 주어지며, A[1] 부터 A[n]을 나타낸다 (각각의 값은 1이상 10^9 이하이다).

세 번째 줄에는 공백으로 구분된 m개의 정수가 주어지며, B[1] 부터 B[m]을 나타낸다 (각각의 값은 1이상 10^9 이하이다).

앞서 언급한대로, A와 B는 각각 서로 다른 양의 정수들을 포함한 배열들이다.
	*/
	int T, N, M;

	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		vector<int> A, B;
		for (int i = 0; i < N; i++)
		{
			int input;
			cin >> input;
			A.push_back(input);
		}
		for (int i = 0; i < M; i++)
		{
			int input;
			cin >> input;
			B.push_back(input);
		}

		long long sum = 0;
		
		sort(B.begin(), B.end());

		for (int i = 0; i < N; i++)
		{
			//C[i] 는 배열 B에 있는 값 중 A[i] 에 가장 가까운 값 (절대값 차이가 가장 작은 값)으로 정의 된다. 
			//만약 이 조건을 만족하는 값들이 여럿 있는 경우, 그 중 가장 크기가 작은 값으로 정의 된다.
			int dest = A[i];
			int diff = 0x7f7f7f7f;
			int temp = 0;

			int it = lower_bound(B.begin(), B.end(), dest) - B.begin();

			if (it == B.size())
			{
				temp = B[it - 1];
			}
			else if (it > 0)
			{
				if (abs(B[it] - dest) < diff)
				{
					diff = abs(B[it] - dest);
					temp = B[it];
				}
				if (abs(B[it - 1] - dest) <= diff)
				{
					diff = abs(B[it - 1] - dest);
					temp = B[it - 1];
				}
				if (it < B.size() - 1)
				{
					if (abs(B[it + 1] - dest) < diff)
					{
						diff = abs(B[it + 1] - dest);
						temp = B[it + 1];
					}
				}
			}
			else
			{
				if (abs(B[it] - dest) < diff)
				{
					diff = abs(B[it] - dest);
					temp = B[it];
				}
				if (it < B.size() - 1)
				{
					if (abs(B[it + 1] - dest) < diff)
					{
						diff = abs(B[it + 1] - dest);
						temp = B[it + 1];
					}
				}
			}
			sum += temp;
		}
		cout << sum << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
