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

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, M;//나무의 개수 N과 가져갈나무 M
	cin >> N >> M;

	vector<long long> tree(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> tree[i];
	}
	
	sort(tree.begin(), tree.end());

	long long low = 0;
	long long high = tree[N - 1];
	long long maxcut = 0;

	while (high >= low)
	{
		unsigned long long temp = 0;
		long long cut = (high + low) / 2;

		for (int i = 0; i < tree.size(); ++i)
		{
			if (tree[i] - cut > 0)
				temp += tree[i] - cut;
		}

		if (temp >= M)
		{
			maxcut = cut;
			low = cut + 1;
		}
		else
		{
			high = cut - 1;
		}
	}

	cout << maxcut << '\n';
	//46 42 40 26 4
	// 몇개의 나무를 자를지 먼저 추리고
	// 그중 안잘라도 되는건 버리고
	// 추려진 나무중 가장 작은 나무를 기준을 구함
	// 가장작은나무 높이를 잘랐을때 길이 <= M 까지 구함
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
