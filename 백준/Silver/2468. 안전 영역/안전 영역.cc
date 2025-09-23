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

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

void BackJoon()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
        
    int N;
    cin >> N;

    vector<vector<int>> height;
    
    height.resize(N);
    for (int i = 0; i < N; ++i)
    {
        height[i].resize(N);
        for (int j = 0; j < N; ++j)
        {
            int H;
            cin >> H;

            height[i][j] = H;
        }
    }
    
    queue<pair<int, int>> Q;   

    //상 하 좌 우
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };

    int answer = 0;
    for (int rain = 0; rain <= 100; ++rain)
    {
        //현재 물줄기에서 안전영역의 개수
        int answerTemp = 0;

        vector<vector<bool>> visit;
        visit.resize(N);
        for (int i = 0; i < N; i++)
        {
            visit[i].resize(N);
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                //이미 잠겼거나 bfs계산이 끝났다면
                if (rain >= height[i][j] || visit[i][j])
                {
                    continue;
                }
                
                Q.push({ j, i });
                visit[i][j] = 1;
                ++answerTemp;

                while (!Q.empty())
                {
                    pair<int, int> Cur = Q.front();
                    Q.pop();

					//물에 잠기지 않았다면 인접한 영역을 계산해야한다.

					for (int dir = 0; dir < 4; ++dir)
					{
						int x = Cur.X + dx[dir];
						int y = Cur.Y + dy[dir];
						if (x < 0 || y < 0 || x >= N || y >= N)
						{
							continue;
						}

						//인접한 높이가 물에 잠겼다면
						if (rain >= height[Cur.Y][Cur.X])
						{
							continue;
						}

                        if (visit[y][x] != 0)
                        {
                            continue;
                        }
                        visit[y][x] = 1;
						Q.push({ x,y });
					}
                }
            }
        }
        //bfs가 끝났다면 안전영역의 최대치를 갱신
        answer = max(answer, answerTemp);
    }
    cout << answer << '\n';
}

int main()
{
    BackJoon();//출력할때 endl;넣자
    //Programmers();
    return 0;
}