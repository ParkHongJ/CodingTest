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
#include <cmath>
#pragma warning(disable :4996)
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	/*
	*	첫째 줄에 N, M, B가 주어진다. (1 ≤ M, N ≤ 500, 0 ≤ B ≤ 6.4 × 107)

		둘째 줄부터 N개의 줄에 각각 M개의 정수로 땅의 높이가 주어진다. 
		(i + 2)번째 줄의 (j + 1)번째 수는 좌표 (i, j)에서의 땅의 높이를 나타낸다. 
		땅의 높이는 256보다 작거나 같은 자연수 또는 0이다.
	*/

	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> world(N, vector<int>(M));

	int startHeight = 0;
	for (int i = 0; i < N; i++)
	{
		int blockCnt = 0;
		for (int j = 0; j < M; j++)
		{
			cin >> world[i][j];
			startHeight = max(startHeight, world[i][j]);
		}
	}

	deque<int> blocks; // i번째 층에 몇개의 블럭이 들어있는지
	
	const int MaxBlock = N * M;

	int maxHeight = 0;
	{
		int currentHeight = 0;
		while (currentHeight <= startHeight)
		{
			int blockCnt = 0;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (world[i][j] >= currentHeight)
					{
						++blockCnt;
					}
				}
			}
			if (blockCnt == MaxBlock)
			{
				maxHeight = currentHeight;
			}
			else
			{
				blocks.push_back(blockCnt);
			}
			++currentHeight;
		}
	}

	//높은곳에 높이를 맞출까?
	//낮은곳에 높이를 맞출까?

	//블럭 제거 후 인벤토리 추가 2초
	//블럭 설치 1초

	// 블럭을 설치해서 맞출까?
	// 현재 높이에서 블럭을 제거하는게 맞을까 블럭을 설치하는게 맞을까
	// 설치한다면 블럭이 모자랄수도있다. 하지만 가장 높은곳의 블럭을 깎으면 또 가능할듯 하다
	
	int time = 0;
	while (!blocks.empty())
	{
		if (MaxBlock - blocks.front() > B)
		{
			//1층에 땅을 설치해서 평탄화가 불가능한 경우
			//마지막층을 깎아야한다
			B += blocks.back();
			time += blocks.back() * 2;
			blocks.pop_back();
		}
		else
		{
			//1층에 땅을 설치해서 평탄화가 가능한경우.

			//땅을 설치하는 비용 vs 맨위를 깎는비용
			if (MaxBlock - blocks.front() <= blocks.back() * 2)
			{
				B -= MaxBlock - blocks.front(); //필요한 땅의 개수
				time += MaxBlock - blocks.front();
				blocks.pop_front();
				++maxHeight;
			}
			else
			{
				//깎는게 더싸다
				B += blocks.back();
				time += blocks.back() * 2;
				blocks.pop_back();
			}
		}
	}
	cout << time << " " << maxHeight << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
