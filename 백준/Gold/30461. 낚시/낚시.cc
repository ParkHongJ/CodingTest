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
#include <list>
#include <iomanip>
#include <math.h>
#pragma warning(disable :4996)
using namespace std;


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0,0 };

//부모 정점이 저장된 배열을 p
vector<int> p(100005, -1);
//정점x의 그룹
int find(int x)
{
	if (p[x] < 0)
	{
		return x;
	}
	else
	{
		return p[x] = find(p[x]);
	}
}
bool uni(int u, int v)
{
	int uRoot = find(u);
	int vRoot = find(v);

	if (uRoot == vRoot)
		return false;

	p[vRoot] = uRoot; 
	return true;
}

void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, Q;
	cin >> N >> M >> Q;

	vector<vector<int>> board(N + 1);
	for (int i = 1; i <= N; i++)
	{
		board[i].resize(M + 1);
		for (int j = 1; j <= M; j++)
		{
			int input;
			cin >> input;

			if (i > 1)
			{
				board[i][j] = input + board[i - 1][j];
			}
			else
			{
				board[i][j] = input;
			}

		}
	}

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (j > 1)
			{
				board[i][j] = board[i][j] + board[i - 1][j - 1];
			}
		}
	}

	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}*/

	for (int i = 0; i < Q; ++i)
	{
		int W, P;
		cin >> W >> P;

		int answer = 0;

		/*while (W >= 1 && P >= 1)
		{
			answer += board[W][P];

			--W;
			--P;
		}*/

		answer += board[W][P];

		cout << answer << '\n';
	}
}
int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}