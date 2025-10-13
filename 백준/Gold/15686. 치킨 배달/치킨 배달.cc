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

	// 첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 
	// 도시의 치킨 거리의 최솟값을 출력한다.
	// 치킨집이 N개라면 이중 A개를 폐업해야한다. 

	// 도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.
	
	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> town;
	town.resize(N + 1);

	vector<pair<int, int>> ChickenHouse;
	vector<pair<int, int>> Home;

	for (int i = 1; i <= N; ++i)
	{
		town[i].resize(N + 1);
		for (int j = 1; j <= N; ++j)
		{
			int input;
			cin >> input;
			town[i][j] = input;
			
			if (input == 2)
			{
				ChickenHouse.push_back({ j, i });
			}
			else if (input == 1)
			{
				Home.push_back({ j,i });
			}
		}
	}

	vector<bool> maskChicken;
	maskChicken.resize(ChickenHouse.size(), false);

	for (int i = 0; i < M; ++i)
	{
		maskChicken[i] = true;
	}
	sort(maskChicken.begin(), maskChicken.end());

	int answer = 1000000;
	do {
		int townChickenDist = 0;
		for (int j = 0; j < Home.size(); ++j)
		{
			int HomeChickenDist = 100000;
			for (int i = 0; i < ChickenHouse.size(); ++i)
			{
				//치킨집이 폐업상태라면 다음루프로.
				if (maskChicken[i] == false)
					continue;

				pair<int, int>& curChicken = ChickenHouse[i];

				//현재 폐업하지않은 치킨집과의 거리
				int curDist = abs(Home[j].first - curChicken.first) + abs(Home[j].second - curChicken.second);
				HomeChickenDist = min(HomeChickenDist, curDist);
			}
			townChickenDist += HomeChickenDist;
		}
		answer = min(answer, townChickenDist);
	} while (next_permutation(maskChicken.begin(), maskChicken.end()));

	cout << answer << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}