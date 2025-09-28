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

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	long N;
    cin >> N;

    long sum = 0;
    long cnt = 1;
    while (sum <= N)
    {
	    sum = sum + cnt;
    	++cnt;
    }
    cout << cnt - 2 << '\n';
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}