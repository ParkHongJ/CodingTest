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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int N;
vector<vector<int>> board;
vector<int> answer;

int func(int x, int y, int m);
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	/*
	* 첫째 줄에 세준이의 물건을 구매할 의향이 있는 사람의 수 N이 주어진다. 
	이 값은 50보다 작거나 같다. 
	둘째 줄부터 각 사람이 지불할 최대 금액과 배송비가 공백을 사이에 두고 주어진다. 
	두 값은 모두 10^6보다 작거나 같은 음이 아닌 정수이고, 배송비는 0이 될 수도 있다.
	*/
	cin >> N;

	board.resize(N);

	for (int i = 0; i < N; i++)
	{
		board[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	cout <<func(0, 0, N)<<'\n';

	
	//sort(answer.begin(), answer.end());

	//if (answer.size() <= 1)
	//{
	//	cout << answer[0] << '\n';
	//}
	//else if (answer.empty())
	//	cout << board[0][0];
	//else
	//	cout << answer[1] << '\n';

}
int func(int x, int y, int m)
{
	if (m == 1)
	{
		return board[y][x];
	}

	int temp = m / 2;
	
	int a = func(x, y, temp);
	int b = func(x + temp, y, temp);
	int c = func(x, y + temp, temp);
	int d = func(x + temp, y + temp, temp);

	vector<int> test = { a, b, c, d };
	sort(test.begin(), test.end());

	return test[1];
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}
