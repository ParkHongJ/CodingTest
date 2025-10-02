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

//세로 가로 스티커의 개수 K
int N, M, K;

vector<vector<int>> board;
vector<vector<vector<int>>> sticker;

void cansticker(vector<vector<int>>& curSticker, int cur, bool& bCan);
void rotateMatrix(const vector<vector<int>>& current, int cur, bool& bCan)
{
	auto tmp = current;
	//3번 회전시켜야한다.

	for (int k = 0; k < 3; ++k)
	{
		vector<vector<int>> rotateSticker;
		rotateSticker.resize(tmp[0].size());
		for (int i = 0; i < rotateSticker.size(); ++i)
		{
			rotateSticker[i].resize(tmp.size());
		}

		for (int i = 0; i < tmp.size(); ++i)
		{
			for (int j = 0; j < tmp[i].size(); ++j)
			{
				rotateSticker[j][tmp.size() - i - 1] = tmp[i][j];
			}
		}
		tmp = rotateSticker;

		//검사로직
		cansticker(rotateSticker, cur, bCan);
        if (bCan)
		{
			return;
		}
	}
}
void cansticker(vector<vector<int>>& curSticker, int cur, bool& bCan)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int posX = j;
			int posY = i;

			int sizeX = posX + curSticker[0].size() - 1;
			int sizeY = posY + curSticker.size() - 1;
			if (sizeY < N && sizeX < M)
			{
				bool btemp = true;
				for (int y = 0; y < curSticker.size(); ++y)
				{
					for (int x = 0; x < curSticker[0].size(); ++x)
					{
						if (curSticker[y][x] == 1 && board[posY + y][posX + x] == 1)
						{
							//이미 스티커가있다
							btemp = bCan = false;
							y = curSticker.size();
							break;
						}
					}
				}
				//스티커를 붙힐수있다.
				if (bCan || btemp)
				{
					bCan = true;
					for (int y = posY; y < posY + curSticker.size(); ++y)
					{
						for (int x = posX; x < posX + curSticker[0].size(); ++x)
						{
							if (curSticker[y - posY][x - posX] == 1)
							{
								board[y][x] = 1;
							}
						}
					}
					return;
				}
			}
			else
			{
				//크기때문에 스티커를 붙힐수없다.
				bCan = false;
				break;
			}
		}
	}
}
void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	board.resize(N);

	for (int i = 0; i < N; ++i)
	{
		board[i].resize(M);
	}

	sticker.resize(K); //스티커의 개수 K

	int answer = 0;

	for (int i = 0; i < K; ++i)
	{
		int R, C;
		cin >> R >> C;

		sticker[i].resize(R);
		for (int j = 0; j < R; ++j)
		{
			sticker[i][j].resize(C);

			for (int l = 0; l < C; ++l)
			{
				int input;
				cin >> input;

				sticker[i][j][l] = input;
			}
		}
		
		// 어차피 스티커는 순서대로 붙혀야하니까 
		// 뒤의 스티커를 알기전에 현재 스티커를 먼저 붙히자
		// 현재 스티커의 정보
		
	}
	
	for (int cur = 0; cur < K; ++cur)
	{
		vector<vector<int>>& curSticker = sticker[cur];

		bool bCan = true;
		cansticker(curSticker, cur, bCan);

		//스티커를 붙힐수 없다면 회전시키자.
		if (bCan == false)
		{
			rotateMatrix(curSticker, cur, bCan);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; j++)
		{
			//cout << board[i][j] << " ";
			if (board[i][j] == 1)
			{
				++answer;
			}
		}
		//cout << '\n';
	}
	// 현재위치 (x,y)에 붙힐 스티커가
	// board의 크기를 벗어나지 않는지 (x+size, y+size)
	// bool bCan = true;
	// for cur < sticker 현재 위치로부터 스티커를 비교한다
	// {
	//    if 비교위치와 현재스티커의 비교위치가 1이라면
	//       (다른 스티커가 점유했다) 현재위치를 증가시킨다.
	//       bCan = false;
	//       break;
	// }
	// if (bCan)
	//    board에 마크. for, for
	// else
	//    현재위치에 스티커를 붙힐 수 없다	
	// 
	// 현재위치를 증가시킨다. cur++
	// 현재위치가 마지막이라면 
	// 스티커를 90도 회전한다. 
	// if (cur >= size)
	// {
	//    bool bEnd = rotate(stiker) //4번째 회전이라면
	//    스티커가 전부 회전했다면
	//    현재 스티커를 증가시킨다.
	//    if (bEnd)
	//	  {
	//        sticker++
	//    }
	// }

	cout << answer << '\n';
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}