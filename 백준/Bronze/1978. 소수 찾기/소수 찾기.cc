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

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		if (number == 1)
			continue;
		bool isPrime = true;
		for (int j = 2; j * j <= number; j++)
		{
			if ((number % j) == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
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
