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

//상하좌우
int dx[4] = { 0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};

int N, K;
int arr[100000];
bool isUsed[100000];
vector<int> v;

int answer = 0;

//N개의 자연수와 자연수 M이 주어졌을 때, 
// 아래 조건을 만족하는 길이가 M인 수열
// N개의 자연수는 모두 다른 수이다.

set<string> s;

void func(int m)
{
	if (m == K)
	{
		string str;
		for (int i = 0; i < K; i++)
		{
			str += to_string(arr[i]);
		}

		//중복이 아니라면
		if (s.find(str) == s.end())
		{
			++answer;
			s.insert(str);
		}
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (isUsed[i] == false)
		{
			arr[m] = v[i];
			isUsed[i] = true;
			func(m + 1);
			isUsed[i] = false;
		}
	}
}
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	// 첫째 줄에 n이, 둘째 줄에 k가 주어진다. 
	// 셋째 줄부터 n개 줄에는 카드에 적혀있는 수가 주어진다.
	cin >> N >> K;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		v[i] = input;
	}
	//n장의 카드에 적힌 숫자가 주어졌을 때, 그 중에서 k개를 선택해서 만들 수 있는 정수의 개수
	func(0);

	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}