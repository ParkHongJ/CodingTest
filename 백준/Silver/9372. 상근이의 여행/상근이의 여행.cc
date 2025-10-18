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

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 첫 번째 줄에는 국가의 수 N(2 ≤ N ≤ 1 000)과 비행기의 종류 M(1 ≤ M ≤ 10 000) 가 주어진다.
	// 이후 M개의 줄에 a와 b 쌍들이 입력된다.a와 b를 왕복하는 비행기가 있다는 것을 의미한다. (1 ≤ a, b ≤ n; a ≠ b)
	// 주어지는 비행 스케줄은 항상 연결 그래프를 이룬다.
	int T;
	cin >> T;
	for (int Test = 0; Test < T; Test++)
	{
		int N, M;
		cin >> N >> M;

		vector<bool> visit;
		visit.resize(N + 1, false);

		int answer = 0;

		for (int j = 0; j < M; ++j)
		{
			int from, to;
			cin >> from >> to;

			if (!visit[from] || !visit[to])
			{
				visit[from] = true;
				visit[to] = true;
				++answer;
			}
		}

		cout << N - 1 << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
