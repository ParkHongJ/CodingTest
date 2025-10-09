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

int N, M;
int arr[10] = {100};
bool isUsed[10];

void func(int k)
{
	if (M == k)
	{
		for (int i = 0; i < k; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (isUsed[i] == false && i > arr[k - 1])
		{
			arr[k] = i;
			isUsed[i] = true;
			func(k + 1);
			isUsed[i] = false;
		}
	}
}
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int chunk1 = 0, chunk2 = 0;
	
	//toggle이 false이면 0의 묶음을 계산, true면 1의 묶음을 계산
	bool toggle = false;

	string str;
	cin >> str;

	char before = '9';

	for (int i = 0; i < str.length(); ++i)
	{
		if (before != str[i])
		{
			toggle = !toggle;
			before = str[i];
			
			//true면 1의묶음
			if (toggle)
			{
				//바뀌어서 true면 이전은 0의 묶음이 계산되었다
				++chunk1;
			}
			else
			{
				++chunk2;
			}
		}
	}

	cout << min(chunk1, chunk2) << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}