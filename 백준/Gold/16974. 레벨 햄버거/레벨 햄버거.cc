#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#include <cassert>
#pragma warning(disable :4996)
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0,0 };

vector<long long> burger;
vector<long long> layer;
void func(long long eatlayer, int level, long long& answer);
void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	/*
	* 1 ≤ N ≤ 50
	  1 ≤ X ≤ 레벨-N 버거에 있는 레이어의 수
	*/

	long long N, X;
	cin >> N >> X;

	long long answer = 0;
	
	burger.resize(N + 1);
	layer.resize(N + 1);

	burger[0] = 1;
	burger[1] = 3;

	layer[0] = 1; // 패티
	layer[1] = 5; // 버거 패티 패티 패티 버거
	
	for (int i = 2; i <= N; ++i)
	{
		burger[i] = burger[i - 1] * 2 + 1;
	}
	for (int i = 2; i <= N; ++i)
	{
		layer[i] = layer[i - 1] * 2 + 3; //이전레이어에 추가로 B P B추가
	}

	//현재 버거의 중심을 기점으로 패티를 계산하자
	long long mid = layer[N] / 2;
	
	// 왼쪽의 먹은 패티계산, 오른쪽 먹은패티계산
	// left, right
	// if (mid <= X)
	// func(X - mid, level, answer) //left
	// func(mid, level, answer) //right
	// burger[N - 1] 

	// 버거의 반 이상 먹었다면 둘다, 하나만 먹었다면 right
	// 반 이상? 
	func(X, N, answer);
	
	cout << answer << '\n';
}
void func(long long eatlayer, int level, long long& answer)
{
	//먹은게 없다면
	if (eatlayer <= 0)
	{
		return;
	}

	//먹은 레이어 개수가 현재 버거의 레이어보다 크면
	if (eatlayer > layer[level] || level <= 0)
	{
		//이 level 버거는 다 먹었다
		answer += burger[level];
		return;
	}

	{
		//일부만 먹었다면 왼쪽 [level - 1]버거와 오른쪽 [level - 1]버거를 검사
		long long midlayer = layer[level] / 2;
		//오른쪽 버거를 다 먹었나?
		if (midlayer <= eatlayer) 
		{
			if (eatlayer - midlayer >= 1)
			{
				//하나 더 먹었다
				++midlayer;
				++answer;
			}
			answer += burger[level - 1];// 현재레벨 오른쪽 패티를 추가
			//왼쪽 버거 계산
			func(eatlayer - midlayer, level - 1, answer);
		}
		else
		{
			//반 이하로 먹었다면 오른쪽 버거 계산
			func(eatlayer - 1, level - 1, answer);
		}
	}
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}