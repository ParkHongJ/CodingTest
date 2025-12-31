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

	int T, N;
	cin >> T;
	
	while (T--)
	{
		cin >> N;

		unordered_map<string, int> clothes;
		int answer = 1;
		for (int i = 0; i < N; i++)
		{
			string cloth, type;
			
			cin >> cloth >> type;

			++clothes[type];
		}

		for (auto& iter : clothes)
		{
			answer *= (iter.second + 1);
		}
		cout << --answer << '\n';
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
