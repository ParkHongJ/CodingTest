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

bool visit[105] = { false };

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	//횟수 N과 종류 K
	int N, Party = 0;
	char K;
	cin >> N >> K;

	vector<string> player;
	while (N--)
	{
		string name;
		cin >> name;
		player.push_back(name);
	}
	if (K == 'Y')
	{
		Party = 1;
	}
	if (K == 'F')
	{
		Party = 2;
	}
	if (K == 'O')
	{
		Party = 3;
	}
	int answer = 0;
	//임스와 같이 게임한적이 있는사람
	int currentParty = 0;

	set<string> names;
	for (int i = 0; i < player.size(); ++i)
	{
		//이미 플레이한적이 있는경우
		if (names.find(player[i]) != names.end())
			continue;
		names.insert(player[i]);
		++currentParty;

		if (currentParty == Party)
		{
			currentParty = 0;
			++answer;
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
