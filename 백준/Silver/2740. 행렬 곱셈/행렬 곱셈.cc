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

//상우하좌
//왼상오상 왼하 오하 
//아래방향은 없다
int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1};
int dy[8] = { -1, 0, 0, 0, -1, -1, 1, 1};

#define X second 
#define Y first 

void func(vector<int>& T);
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 
	// 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 
	// 그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 
	// 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다. 
	// N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

	int N, M, K;
	cin >> N >> M;
	vector<vector<int>> v;

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		v[i].resize(M);
		for (int j = 0; j < M; j++)
		{
			int input; 
			cin >> input;
			v[i][j] = input;
		}
	}
	cin >> M >> K;
	vector<vector<int>> v2;
	v2.resize(M);
	for (int i = 0; i < M; i++)
	{
		v2[i].resize(K);
		for (int j = 0; j < K; j++)
		{
			int input; 
			cin >> input;
			v2[i][j] = input;
		}
	}
	//i j = 00 + 01 * 00 + 10
	//01 = 00 + 01 * 01 + 11
	//i j = (i,i + i,j) * (i,j + j,i)
	//A행렬의 행과 B행렬의 열의 곱

	vector<vector<int>> answer;
	answer.resize(v.size());

	for (int i = 0; i < answer.size(); ++i)
	{
		answer[i].resize(v2[0].size());
		for (int j = 0; j < answer[i].size(); ++j)
		{
			int temp = 0;
			for (int k = 0; k < v[0].size(); k++)
			{
				temp += v[i][k] * v2[k][j];
			}
			answer[i][j] = temp;
			cout << answer[i][j] << " ";
		}
		cout << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
