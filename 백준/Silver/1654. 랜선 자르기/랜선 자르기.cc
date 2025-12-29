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

	//갖고있는 랜선 K
	//필요한 랜선 N

	int K, N;
	cin >> K >> N;

	vector<long> ran(K);
	long tempsum = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> ran[i];
		tempsum += ran[i];
	}

	sort(ran.begin(), ran.end());

	long high = tempsum / N;
	long low = 1;
	long length = 0;

	while (high >= low)
	{
		long cut = (high + low) / 2;
		int num = 0;
		
		for (int i = 0; i < ran.size(); ++i)
		{
            num += ran[i] / cut;
		}

		//필요한 개수를 넘었다
		//길이를 늘림
		if (num >= N)
		{
			length = cut;
			low = cut + 1;
		}
		else
		{
			//개수가 부족하다. 
			//길이를 줄임
			high = cut - 1;
		}
	}

	cout << length << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
