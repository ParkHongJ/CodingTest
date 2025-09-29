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

void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	string str;
	cin >> N;
	cin >> str;
	long answer = 0;
	for (int i = 0; i < N; ++i)
	{
		answer += str[i] - '0';
	}
	cout << answer << '\n';
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}