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

//우좌상하
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

int arr[100000];
bool isUsed[100000];

vector<int> v;
vector<vector<bool>> command;
long maxanswer = 0;
long minanswer = 0;

void func(int m)
{
	//if (m == N)
	//{
	//	string str;
	//	for (int i = 0; i < K; i++)
	//	{
	//		str += to_string(arr[i]);
	//	}

	//	//중복이 아니라면
	//	if (s.find(str) == s.end())
	//	{
	//		++answer;
	//		s.insert(str);
	//	}
	//	return;
	//}

	//for (int i = 0; i < N; ++i)
	//{
	//	if (isUsed[i] == false)
	//	{
	//		arr[m] = v[i];
	//		isUsed[i] = true;
	//		func(m + 1);
	//		isUsed[i] = false;
	//	}
	//}
}

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)

	// 둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다.
	// 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 
	// 이름은 알파벳 대소문자로 이루어져 있고,
	// 길이가 100보다 작거나 같은 문자열이다.
	// 입력은 가입한 순서로 주어진다.

	int N;

	cin >> N;
	vector<pair<pair<int,int>, string>> v;
	for (int i = 0; i < N; i++)
	{
		int input;
		string str;
		cin >> input >> str;
		v.push_back({ {input, i }, str });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first.first << " " << v[i].second << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}