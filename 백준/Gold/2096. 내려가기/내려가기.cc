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
	
	int N;

	cin >> N;
	
	int z, x, c;
	cin >> z >> x >> c;

	int mind[3] = { z,x,c };
	int maxd[3] = { z,x,c };

	for (int i = 1; i < N; ++i)
	{
		cin >> z >> x >> c;
		int input[3] = { z,x,c };

		int tempmin[3] = { mind[0], mind[1], mind[2] };
		int tempmax[3] = { maxd[0], maxd[1], maxd[2] };
		for (int j = 0; j < 3; ++j)
		{
			if (j - 1 >= 0)
			{
				mind[j] = min(mind[j], tempmin[j - 1]);
				maxd[j] = max(maxd[j], tempmax[j - 1]);
			}

			if (j + 1 < 3)
			{
				mind[j] = min(mind[j], tempmin[j + 1]);
				maxd[j] = max(maxd[j], tempmax[j + 1]);
			}
			mind[j] += input[j];
			maxd[j] += input[j];
		}
	}
	cout << max(max(maxd[0], maxd[1]), maxd[2]) << " "
		<< min(min(mind[0], mind[1]), mind[2]) << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}

