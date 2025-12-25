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

int num = 0;
int cnt = 0;
bool bfound = false;
void func(int x, int y, int n, int r, int c);
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int N, r, c;
	cin >> N >> r >> c;

	int width = pow(2, N);

	func(0, 0, width, r, c);
}

void func(int x, int y, int n, int r, int c)
{
	if (bfound)
		return;

	if (n <= 2)
	{
		if (r >= y + n || c >= x + n)
		{
			cnt += 4;
			return;
		}
		for (int i = y; i < y + n; ++i)
		{
			for (int j = x; j < x + n; ++j)
			{
				if (i == r && j == c)
				{
					bfound = true;
					cout << cnt << '\n';
					return;
				}
				++cnt;
			}
		}
	}
	else
	{
		int width = n / 2;

		//rc 가 좌상단에 있다
		if (r < y + width && c < x + width)
		{
			func(x, y, width, r, c);
		}
		else
		{
			cnt += width * width;
		}
		
		//rc가 우상단에 있다
		if (r < y + width && c < x + width + width)
		{
			func(x + width, y, width, r, c);
		}
		else
		{
			cnt += width * width;
		}

		//rc가 좌하단에 있다
		if (r < y + width + width && c < x + width )
		{
			func(x, y + width, width, r, c);
		}
		else 
		{
			cnt += width * width;
		}
		
		//rc가 우하단에 있다
		if (r < y + width + width && c < x + width + width)
		{
			func(x + width, y + width, width, r, c);
		}
		else
		{
			cnt += width * width;
		}
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
