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

void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--)
	{
		int M, N, K;
		cin >> M >> N >> K;

		vector<vector<int>> board(N);
		vector<vector<int>> visit(N);

		for (int i = 0; i < N; i++)
		{
			board[i].resize(M);
			visit[i].resize(M);
		}

		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		int answer = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == 1 && visit[i][j] == false)
				{
					++answer;

					queue<pair<int, int>> q;
					q.push({ j,i });

					int dx[4] = { -1,1,0,0 };
					int dy[4] = { 0,0,-1,1 };

					while (!q.empty())
					{
						pair<int, int> cur = q.front(); q.pop();

						if (visit[cur.second][cur.first])
							continue;
						visit[cur.second][cur.first] = true;

						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || ny < 0 || nx >= M || ny >= N)
								continue;
							
							if (board[ny][nx] == 1 && visit[ny][nx] == false)
							{
								q.push({ nx,ny });
							}
						}

					}
				}
			}
		}
		cout << answer << '\n';
	}
}
int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}