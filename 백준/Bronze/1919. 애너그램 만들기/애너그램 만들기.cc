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
	
	string A, B;
	cin >> A >> B;
	
	
	vector<int> v1, v2;
	v1.resize('z' - 'a' + 1);
	v2.resize('z' - 'a' + 1);

	for (int i = 0; i < A.length(); ++i)
	{
		++v1[(A[i] - 'a')];
	}
	for (int i = 0; i < B.length(); ++i)
	{
		++v2[(B[i] - 'a')];
	}

	int answer = 0;

	for (int i = 0; i < v1.size(); ++i)
	{
		if (v1[i] != v2[i])
		{
			answer += abs(v1[i] - v2[i]);
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