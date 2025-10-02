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
vector<int> v = { 0,1,2,3 };

vector<vector<int>> board;
vector<pair<int, pair<int, int>>> cctvs;
int numCCTV = 0; //cctv의 개수 만큼 순열을 구한다.

int answer = 100000000;
int N, M;

void repeatPermutation(vector<int> vec, vector<int> perm, int depth);
bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= board[0].size() || y >= board.size())
	{
		return false;
	}
	return true;
}
void Update(pair<int,int>& cur, int dir, vector<vector<bool>>& visit)
{
	int nx, ny;
	int index = 0;

	nx = cur.first + dx[dir] * index;
	ny = cur.second + dy[dir] * index;

	while (check(nx, ny))
	{
		//벽이 아니면 감시 가능하다.
		if (board[ny][nx] != 6)
		{
			visit[ny][nx] = true;
		}
		else
		{
			//벽이라면
			break;
		}
		++index;

		nx = cur.first + dx[dir] * index;
		ny = cur.second + dy[dir] * index;
	}
}
void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	/*
	* 첫째 줄에 사무실의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 8)
	  0은 빈 칸, 6은 벽, 1~5는 CCTV 
	  CCTV의 최대 개수는 8개를 넘지 않는다.
	*/
	cin >> N >> M;

	board.resize(N);

	
	for (int i = 0; i < N; ++i)
	{
		board[i].resize(M);
		for (int j = 0; j < M; ++j)
		{
			int input;
			cin >> input;
			board[i][j] = input;
			
			if (input >= 1 && input <= 5)
			{
				++numCCTV;
				//cctv의 종류와 x,y (j,i)
				cctvs.push_back({ input, {j,i} });
			}
		}
	}

	//무한루프를 돌고
	//cctv 방향조합만큼 루프를 돌면서
	//cctv가 2개라면
	//상하좌우 (1,2,3,4)
	//상하좌우 (1,2,3,4)
	//1,1 1,2 1,3 1,4
	//2,1 2,2 2,3 2,4
	//3,1 3,2 3,3 3,4
	//4,1 4,2 4,3 4,4

	//cctv가 3개라면
	//1,1,1 1,1,2 1,1,3 1,1,4
	
	//vector<int> v; //(1,2,3,4) * cctv 개수의 숫자가 들어있어야함 
	//
	//v.resize(numCCTV);
	/*for (int i = 0; i < numCCTV; ++i)
	{
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
	}*/

	/*
	do
	{
		//cctv 방향 조합이 구해질때마다.
		vector<vector<bool>> visit;
		visit.resize(N);
		for (int i = 0; i < N; ++i)
		{
			visit[i].resize(M);
		}

		for (int i = 0; i < numCCTV; ++i)
		{
			pair<int, pair<int, int>>& cctv = cctvs[i];
			
			int type = cctv.first; //종류
			int dir = v[i]; //i번째 cctv의 방향
			pair<int, int>& cur = cctv.second; //좌표

			if (type == 1)
			{
				//기본값 오른쪽
				//4개 상하좌우
				Update(cur, dir, visit);
			}
			else if (type == 2)
			{
				//기본값 좌우
				//2개 상하 좌우
				if (dir == 0 || dir == 1)
				{
					Update(cur, 0, visit);
					Update(cur, 1, visit);
				}
				else
				{
					Update(cur, 2, visit);
					Update(cur, 3, visit);
				}
			}
			else if (type == 3)
			{
				//기본값 상우
				//4개 상하좌우
				if (dir == 0) //상우
				{
					Update(cur, 0, visit);
					Update(cur, 3, visit);
				}
				else if (dir == 1)//하우
				{
					Update(cur, 1, visit);
					Update(cur, 3, visit);
				}
				else if (dir == 2)//하 좌
				{
					Update(cur, 1, visit);
					Update(cur, 2, visit);
				}
				else //좌상
				{
					Update(cur, 0, visit);
					Update(cur, 2, visit);
				}
			}
			else if (type == 4)
			{
				//기본값 상 좌 우
				//4개 상하좌우
				if (dir == 0) //상 좌 우 
				{
					Update(cur, 0, visit);
					Update(cur, 2, visit);
					Update(cur, 3, visit);
				}
				else if (dir == 1) //하 좌 우
				{
					Update(cur, 1, visit);
					Update(cur, 2, visit);
					Update(cur, 3, visit);
				}
				else if (dir == 2) //상 좌 하
				{
					Update(cur, 0, visit);
					Update(cur, 1, visit);
					Update(cur, 2, visit);
				}
				else if (dir == 3)//상 우 하
				{
					Update(cur, 0, visit);
					Update(cur, 1, visit);
					Update(cur, 3, visit);
				}
			}
			else if (type == 5)
			{
				//기본값 상 하 좌 우
				//1개
				Update(cur, 0, visit);
				Update(cur, 1, visit);
				Update(cur, 2, visit);
				Update(cur, 3, visit);
			}
		}
		
		int cnt = 0; // 영역의 값

		//영역의 값 계산
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (visit[i][j] == false && board[i][j] == 0)
				{
					++cnt;
				}
			}
		}

		answer = min(answer, cnt);
	} while (next_permutation(v.begin(), v.begin() + numCCTV));
	*/
	vector<int> r(numCCTV);
	repeatPermutation(v, r, 0);
	cout << answer << '\n';
}

void repeatPermutation(vector<int> vec, vector<int> perm, int depth)
{
	if (depth == perm.size())
	{
		//cctv 방향 조합이 구해질때마다.
		vector<vector<bool>> visit;
		visit.resize(N);
		for (int i = 0; i < N; ++i)
		{
			visit[i].resize(M);
		}

		for (int i = 0; i < numCCTV; ++i)
		{
			pair<int, pair<int, int>>& cctv = cctvs[i];

			int type = cctv.first; //종류
			int dir = perm[i]; //i번째 cctv의 방향
			pair<int, int>& cur = cctv.second; //좌표

			if (type == 1)
			{
				//기본값 오른쪽
				//4개 상하좌우
				Update(cur, dir, visit);
			}
			else if (type == 2)
			{
				//기본값 좌우
				//2개 상하 좌우
				if (dir == 0 || dir == 1)
				{
					Update(cur, 0, visit);
					Update(cur, 1, visit);
				}
				else
				{
					Update(cur, 2, visit);
					Update(cur, 3, visit);
				}
			}
			else if (type == 3)
			{
				//기본값 상우
				//4개 상하좌우
				if (dir == 0) //상우
				{
					Update(cur, 0, visit);
					Update(cur, 3, visit);
				}
				else if (dir == 1)//하우
				{
					Update(cur, 1, visit);
					Update(cur, 3, visit);
				}
				else if (dir == 2)//하 좌
				{
					Update(cur, 1, visit);
					Update(cur, 2, visit);
				}
				else //좌상
				{
					Update(cur, 0, visit);
					Update(cur, 2, visit);
				}
			}
			else if (type == 4)
			{
				//기본값 상 좌 우
				//4개 상하좌우
				if (dir == 0) //상 좌 우 
				{
					Update(cur, 0, visit);
					Update(cur, 2, visit);
					Update(cur, 3, visit);
				}
				else if (dir == 1) //하 좌 우
				{
					Update(cur, 1, visit);
					Update(cur, 2, visit);
					Update(cur, 3, visit);
				}
				else if (dir == 2) //상 좌 하
				{
					Update(cur, 0, visit);
					Update(cur, 1, visit);
					Update(cur, 2, visit);
				}
				else if (dir == 3)//상 우 하
				{
					Update(cur, 0, visit);
					Update(cur, 1, visit);
					Update(cur, 3, visit);
				}
			}
			else if (type == 5)
			{
				//기본값 상 하 좌 우
				//1개
				Update(cur, 0, visit);
				Update(cur, 1, visit);
				Update(cur, 2, visit);
				Update(cur, 3, visit);
			}
		}

		int cnt = 0; // 영역의 값

		//영역의 값 계산
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (visit[i][j] == false && board[i][j] == 0)
				{
					++cnt;
				}
			}
		}

		answer = min(answer, cnt);

		return;
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		perm[depth] = vec[i];
		repeatPermutation(vec, perm, depth + 1);
	}
}


int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}