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
#pragma warning(disable :4996)
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };


void RotateGear(vector<int>& gearIndex, int Gear, int order)
{
	//현재 톱니 방향변경
	if (order == 1) { // 시계
		gearIndex[Gear] = (gearIndex[Gear] + 7) % 8; // -1 mod 8
	}
	else {          // -1: 반시계
		gearIndex[Gear] = (gearIndex[Gear] + 1) % 8; // +1 mod 8
	}
}
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int K;

	//각 톱니바퀴의 12시 인덱스, 맞닿아있는건 2번이다. 12시는 0번
	vector<int> v;
	v.resize(4);

	vector<vector<int>> gear;
	gear.resize(4);

	for (int i = 0; i < 4; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 8; ++j)
		{
			gear[i].push_back(str[j] - '0');
		}
	}
	
	cin >> K;

	//톱니바퀴 번호와 방향
	for (int i = 0; i < K; ++i)
	{
		int orderGear, order;
		cin >> orderGear >> order;
		--orderGear;
		
		//현재 톱니기준 왼쪽과 오른쪽을 구현해야한다.
		//오른쪽
		int right = orderGear + 1;
		int left = orderGear - 1;

		int tempCurrent = orderGear;
		int currentorder = order;
		
		//어떤 기어가 어디방향으로 회전하는지
		vector<pair<int,int>> rightRotate;
		vector<pair<int,int>> leftRotate;
		
		while (right < v.size())
		{
			//v[left]는 현재 left기어의 12시 인덱스정보
			//current기어의 오른쪽 정보와 right기어의 왼쪽정보
			
			int rightNum = (v[tempCurrent] + 2) % 8; //current기어의 오른쪽 정보
			int leftNum = (v[right] + 6) % 8; //right기어의 왼쪽 정보

			if (gear[tempCurrent][rightNum] != gear[right][leftNum])
			{
				rightRotate.push_back({right, currentorder * -1});
				currentorder = currentorder * -1;
			}
			else
			{
				//right기어는 회전하지 않는다.
				break;
			}

			tempCurrent = right++;
		}

		tempCurrent = orderGear;
		currentorder = order;

		while (left >= 0)
		{
			int rightNum = (v[left] + 2) % 8; //left기어의 오른쪽 정보
			int leftNum = (v[tempCurrent] + 6) % 8; //current기어의 왼쪽 정보

			if (gear[tempCurrent][leftNum] != gear[left][rightNum])
			{
				leftRotate.push_back({ left, currentorder * -1 });
				currentorder = currentorder * -1;
			}
			else
			{
				break;
			}

			tempCurrent = left--;
		}
		//현재 기어를 돌려야한다
		RotateGear(v, orderGear, order);

		for (int i = 0; i < rightRotate.size(); ++i)
		{
			RotateGear(v, rightRotate[i].first, rightRotate[i].second);
		}
		for (int i = 0; i < leftRotate.size(); ++i)
		{
			RotateGear(v, leftRotate[i].first, leftRotate[i].second);
		}
	}

	int answer = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		//N은 0 
		//S는 1
		//현재기어의 12시가 S극이라면
		int twelve = v[i];
		if (gear[i][twelve] == 1)
		{
			answer += 1 << i;
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